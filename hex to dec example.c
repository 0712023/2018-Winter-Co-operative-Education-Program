#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main ()
{   char datastore[] = "\0H";
   char store[3];
   memset(store, 0, 3);
   sprintf(store, "0x%02x%02x", datastore[0], datastore[1]);
   int temp_hex = strtol(store, NULL, 16);

        //convert temp_hex to dec
        int j = 0, val, len;
        float temp_dec;
        /* Find the length of total number of temp_hex digit */
        len = strlen(temp_hex);
        len--;

        for(j=0; temp_hex[j]!='\0'; j++)
        {

            /* Find the decimal representation of hex[i] */
            if(temp_hex[j]>='0' && temp_hex[j]<='9')
            {
                val = temp_hex[j] - 48;
            }
            else if(temp_hex[j]>='a' && temp_hex[j]<='f')
            {
                val = temp_hex[j] - 97 + 10;
            }
            else if(temp_hex[j]>='A' && temp_hex[j]<='F')
            {
                val =temp_hex[j] - 65 + 10;
            }

            temp_dec += val * pow(16, len) * 0.1;
            len--;
        }

    printf("%f", temp_dec);

}


       
