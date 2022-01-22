#include "mbed.h"
#define dp23 P0_0

BusOut dioda(dp23,dp24,dp25,dp26,dp27,dp5,dp6,dp28);

DigitalOut red1(dp16);
DigitalOut red2(dp15);
DigitalOut red3(dp17);
DigitalOut red4(dp18);

DigitalIn kolona1(dp9);
DigitalIn kolona2(dp10);
DigitalIn kolona3(dp11);
DigitalIn kolona4(dp13);

DigitalOut enable(dp14);

int main() {
    enable=0;
    while(1){
        dioda=255;
        red1=1;
        red2=0;
        red3=0;
        red4=0;
        if(kolona1==1) dioda=254;
        if(kolona2==1) dioda=253;
        if(kolona3==1) dioda=251;
        
        red1=0;
        red2=1;
        red3=0;
        red4=0;
        if(kolona1==1) dioda=247;
        if(kolona2==1) dioda=239;
        if(kolona3==1) dioda=223;
        
        red1=0;
        red2=0;
        red3=1;
        red4=0;
        if(kolona1==1) dioda=191;
        if(kolona2==1) dioda=127;
        wait(0.1);
    }
}
