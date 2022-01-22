#include "mbed.h"
#define dp23 P0_0

BusOut diode(dp23,dp24,dp25,dp26,dp27,dp5,dp6,dp28);
DigitalOut enable(dp14);
DigitalIn taster(dp1);
int main() {
    enable=0;

    char brojac = 0;
    while(1) {
        if (taster == 1){
               
            if (brojac==0) brojac=255; 
            else brojac --;    
    }
        else{
             if(brojac==255)brojac=0;
             else brojac+=1;
        }
        diode=brojac;
        wait(1);
    }
}
