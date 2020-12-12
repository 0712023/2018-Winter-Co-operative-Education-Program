#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>     // 파일 처리 함수가 선언된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <stdbool.h>   // bool, true, false가 정의된 헤더 파일
#include <string.h>    // strchr, memset, memcpy 함수가 선언된 헤더 파일
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <math.h>

int main()
{

   char datastore[29];

      int fd ;

      if ((fd = serialOpen ("/dev/ttyUSB0", 19200)) < 0){
        fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
        return 1 ;
      }
      int n;
         for (n =0; n<8; n++){
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
        }

        for(int i=0;i<28;i++)
         {   datastore[i] = serialGetchar(fd);
          fflush(stdout);
       //값이 계속 이상하게 나옴. 중요한건 멈추게 해야됨.
         }

         char hex[5];
         memset(hex, 0, 5);
         sprintf(hex, "0x%02x%02x", datastore[5], datastore[6]);
         float temp = strtol(hex, NULL, 16);
        printf("%f", temp);

}
