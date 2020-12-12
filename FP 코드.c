#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int serialdataput();
int main (){
  int fd ;
  char datastore[29];
  if ((fd = serialOpen ("/dev/ttyUSB0", 19200)) < 0){
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1 ;
  }serialdataput();
     for(int i=0;i<28;i++)
     {   datastore[i] = serialGetchar(fd);
      fflush(stdout);
   //값이 계속 이상하게 나옴. 중요한건 멈추게 해야됨.
   }for(int j=0;j<28;j++){
      printf("%02x\n", datastore[j]);
   }
  }
int serialdataput(){
   int fd;
   if ((fd = serialOpen ("/dev/ttyUSB0", 19200)) < 0){
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1 ;
  }for (int n =0; n<8; n++){
            if( n == 0){
              int a = 0x02;
               unsigned char hex1 = (char) a;
               serialPutchar(fd, hex1);
               fflush (stdout) ;
         }if(n ==1){
           int b = 0x01;
            unsigned char hex2 = (char) b;
            serialPutchar(fd, hex2);
            fflush (stdout) ;
         }if( n == 2){
           int c = 0x31;
            unsigned char hex3 = (char) c;
            serialPutchar(fd, hex3);
            fflush (stdout) ;
         }if(n == 3){
           int d = 0x00;
            unsigned char hex4 = (char) d;
            serialPutchar(fd, hex4);
            fflush (stdout) ;
         }if( n ==4){
           int e = 0x00;
            unsigned char hex5 = (char) e;
            serialPutchar(fd, hex5);
            fflush (stdout) ;
         }if(n == 5){
           int f = 0x00;
            unsigned char hex6 = (char) f;
            serialPutchar(fd, hex6);
            fflush (stdout) ;
         }if(n == 6){
           int g = 0x00;
            unsigned char hex7 = (char) g;
            serialPutchar(fd, hex7);
            fflush (stdout) ;
         }if(n == 7){
           int h = 0x03;
            unsigned char hex8 = (char) h;
            serialPutchar(fd, hex8);
            fflush (stdout) ;
         }
      }
    char store[5];
    memset(store, 0, 5);
    sprintf(store, "0x%02X%2X", datastore[5], datastore[6]);
    float temp = strtol(store, NULL, 16);
    return temp * 0.1;
