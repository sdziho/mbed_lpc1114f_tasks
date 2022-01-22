#include "mbed.h"
#define dp23 P0_0

BusOut diode(dp23,dp24,dp25,dp26,dp27,dp5,dp6,dp28);
DigitalOut enable(dp14);
DigitalIn taster(dp1);
int main() {
    enable=0;

    char brojac = 1;
    diode=1;
    wait(1);
    while(1) {
        diode=diode*2;
        if(diode==128){diode=1;}
        wait(1);
    }
}
