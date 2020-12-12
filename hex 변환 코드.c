#include <stdio.h>
#include <string.h>

int main()
{
	  char store[5];
    memset(store, 0, 5);
    sprintf(store, "0x%02X%2X", datastore[5], datastore[6]);
    float temp = strtol(store, NULL, 16);
    return temp * 0.1;
}
