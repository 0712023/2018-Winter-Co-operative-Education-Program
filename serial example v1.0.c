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
      int z;
         for(z=0;z<28;z++)
         {   datastore[z] = serialGetchar(fd);
          fflush(stdout);
       //값이 계속 이상하게 나옴. 중요한건 멈추게 해야됨.
         }

       char hex[3];
       memset(hex, 0, 3);
       sprintf(hex, "%02x%02x", datastore[5], datastore[6]);
        float decimal = 0;                  // 10진수를 저장할 변수

        int position = 0;
        int i;
        for ( i = strlen(hex) - 1; i >= 0; i--)    // 문자열을 역순으로 반복
        {
            char ch = hex[i];         // 각 자릿수에 해당하는 문자를 얻음

            if (ch >= 48 && ch <= 57)         // 문자가 0~9이면(ASCII 코드 48~57)
            {
                // 문자에서 0에 해당하는 ASCII 코드 값을 빼고
                // 16에 자릿수를 거듭제곱한 값을 곱함
                decimal += (ch - 48) * pow(16, position);
            }
            else if (ch >= 65 && ch <= 70)    // 문자가 A~F이면(ASCII 코드 65~70)
            {                                 // 대문자로 된 16진수의 처리
                // 문자에서 (A에 해당하는 ASCII 코드 값 - 10)을 빼고
                // 16에 자릿수를 거듭제곱한 값을 곱함
                decimal += (ch - (65 - 10)) * pow(16, position);
            }
            else if (ch >= 97 && ch <= 102)   // 문자가 a~f이면(ASCII 코드 97~102)
            {                                 // 소문자로 된 16진수의 처리
                // 문자에서 (a에 해당하는 ASCII 코드 값 - 10)을 빼고
                // 16에 자릿수를 거듭제곱한 값을 곱함
                decimal += (ch - (97 - 10)) * pow(16, position);
            }

            position++;
        }

           // 300

        printf("%f", decimal);

}
