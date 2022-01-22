#include "mbed.h"
#define dp23 P0_0
DigitalOut enable(dp14);
BusOut diode(dp23, dp24, dp25, dp26, dp27, dp5, dp6, dp28);
AnalogIn otpor(dp9);

const float ukupni_otpor = 50000;

int main(){
    
    enable = 0; 
    
    
    
    
    while(1){
        float r=otpor.read();
        
        if(r<0.70) diode=0;
        if(r<0.74 && r>0.70) diode=1;
        if(r<0.84 && r>0.74)diode=3;
        if(r<0.92 && r>0.84) diode=7;
        if(r<0.94 && r>0.92) diode=15;
        if(r<0.96 && r>0.94) diode=31;
        if(r<0.98 && r>0.96) diode=63;
        if(r>0.98) diode=127;
        
        
        wait(0.1);
    }
}