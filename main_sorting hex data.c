#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <kaa.h>
#include <platform/kaa_client.h>
#include <kaa_error.h>
#include <kaa_configuration_manager.h>
#include <kaa_logging.h>
#include <gen/kaa_logging_gen.h>
#include <platform/kaa_client.h>
#include <utilities/kaa_log.h>
#include <platform-impl/common/ext_log_upload_strategies.h>

#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>


static int32_t sample_period;
static time_t  last_sample_time;
extern kaa_error_t ext_unlimited_log_storage_create(void **log_storage_context_p, kaa_logger_t *logger);
/* Retrieves current temperature. */
static float get_temperature_FP(void)
{
    /* For the sake of example, random data is used */




      char datastore[29];
      if ((fd = serialOpen ("/dev/ttyUSB0", 19200)) < 0){
        fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
        return 1 ;
      }

         for (int n =0; n<8; n++){
            if( n == 0){
                int a = 0x02;
                unsigned char hex1 = (char) a;
                serialPutchar(fd, hex1);
                fflush (stdout) ;
             }
         if(n ==1){
               int b = 0x01;
               unsigned char hex2 = (char) b;
                serialPutchar(fd, hex2);
                fflush (stdout) ;
             }
         if( n == 2){
               int c = 0x31;
                unsigned char hex3 = (char) c;
                serialPutchar(fd, hex3);
                fflush (stdout) ;
             }
         if(n == 3){
               int d = 0x00;
                unsigned char hex4 = (char) d;
                serialPutchar(fd, hex4);
                fflush (stdout) ;
             }
         if( n ==4){
               int e = 0x00;
                unsigned char hex5 = (char) e;
                serialPutchar(fd, hex5);
                fflush (stdout) ;
             }
         if(n == 5){
               int f = 0x00;
                unsigned char hex6 = (char) f;
                serialPutchar(fd, hex6);
                fflush (stdout) ;
             }
         if(n == 6){
               int g = 0x00;
                unsigned char hex7 = (char) g;
                serialPutchar(fd, hex7);
                fflush (stdout) ;
             }
         if(n == 7){
               int h = 0x03;
                unsigned char hex8 = (char) h;
                serialPutchar(fd, hex8);
                fflush (stdout) ;
           }

         for(int i=0;i<28;i++)
         {   datastore[i] = serialGetchar(fd);
          fflush(stdout);
       //값이 계속 이상하게 나옴. 중요한건 멈추게 해야됨.

         }


        char store[5];
        memset(store, 0, 5);
        sprintf(store, "0x%02X%2X", datastore[5], datastore[6]);
        float temp = strtol(store, NULL, 16);
        return temp * 0.1;
   }
}
/* Periodically called by Kaa SDK. */
static void FP_callback(void *context)
{
    time_t current_time = time(NULL);
    /* Respect sample period */
    if (difftime(current_time, last_sample_time) >= sample_period) {
        float temperature = get_temperature_FP();
        printf("Sampled temperature: %f\n", temperature);
        last_sample_time = current_time;
        kaa_user_log_record_t *log_record = kaa_logging_data_collection_create();
        log_record->temperature = temperature;
        kaa_logging_add_record(kaa_client_get_context(context)->log_collector, log_record, NULL);
    }
}
/* Receives new configuration data. */
static kaa_error_t on_configuration_updated(void *context, const kaa_root_configuration_t *conf)
{
    (void) context;
    printf("Received configuration data. New sample period: %i seconds\n", conf->sample_period);
    sample_period = conf->sample_period;
    return KAA_ERR_NONE;
}
int main(void)
{
    /* Init random generator used to generate temperature */
    srand(time(NULL));
    /* Prepare Kaa client. */
    kaa_client_t *kaa_client = NULL;
    kaa_error_t error = kaa_client_create(&kaa_client, NULL);
    if (error) {
        return EXIT_FAILURE;
    }
    /* Configure notification manager. */
    kaa_configuration_root_receiver_t receiver = {
        .context = NULL,
        .on_configuration_updated = on_configuration_updated
    };
    error = kaa_configuration_manager_set_root_receiver(
        kaa_client_get_context(kaa_client)->configuration_manager,
        &receiver);
    if (error) {
        return EXIT_FAILURE;
    }
    /* Obtain default configuration shipped within SDK. */
    const kaa_root_configuration_t *dflt = kaa_configuration_manager_get_configuration(
        kaa_client_get_context(kaa_client)->configuration_manager);
    printf("Default sample period: %i seconds\n", dflt->sample_period);
    sample_period = dflt->sample_period;

    /* Configure data collection. */
    void *log_storage_context         = NULL;
    void *log_upload_strategy_context = NULL;
    /* The internal memory log storage distributed with Kaa SDK. */
    error = ext_unlimited_log_storage_create(&log_storage_context,
        kaa_client_get_context(kaa_client)->logger);
    if (error) {
        return EXIT_FAILURE;
    }
    /* Create a strategy based on timeout. */
    error = ext_log_upload_strategy_create(
        kaa_client_get_context(kaa_client), &log_upload_strategy_context,
        KAA_LOG_UPLOAD_BY_TIMEOUT_STRATEGY);
    if (error) {
        return EXIT_FAILURE;
    }
    /* Strategy will upload logs every 5 seconds. */
    error = ext_log_upload_strategy_set_upload_timeout(log_upload_strategy_context, 5);
    if (error) {
        return EXIT_FAILURE;
    }
    /* Specify log bucket size constraints. */
    kaa_log_bucket_constraints_t bucket_sizes = {
         .max_bucket_size       = 32,   /* Bucket size in bytes. */
         .max_bucket_log_count  = 2,    /* Maximum log count in one bucket. */
    };
    /* Initialize the log storage and strategy (by default, they are not set). */
    error = kaa_logging_init(kaa_client_get_context(kaa_client)->log_collector,
        log_storage_context, log_upload_strategy_context, &bucket_sizes);
    if (error) {
        return EXIT_FAILURE;
    }

    /* Start Kaa SDK's main loop. FP_callback is called once per second. */
    error = kaa_client_start(kaa_client, FP_callback, kaa_client, 1);
    /* Should get here only after Kaa stops. */
    kaa_client_destroy(kaa_client);

    if (error) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
