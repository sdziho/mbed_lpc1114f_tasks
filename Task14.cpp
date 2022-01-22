#include "mbed.h"

DigitalOut enable(dp14);
//BusOut diode (dp23, dp24, dp25, dp26, dp27, dp5, dp6, dp28);
AnalogIn otpor(dp9);
AnalogOut D1(dp23);
AnalogOut D2(dp24);
AnalogOut D3(dp25);
AnalogOut D4(dp26);
AnalogOut D5(dp27);
AnalogOut D6(dp5);
AnalogOut D7(dp6);
AnalogOut D8(dp28);

const float ukupni_otpor = 10000;

void postavi(float vrjednost){
    D1=vrijednost;
    D2=vrijednost;
    D3=vrijednost;
    D4=vrijednost;
    D5=vrijednost;
    D6=vrijednost;
    D7=vrijednost;
    D8=vrijednost;
}


int main(){
    
    enable = 0; 

    while(1){
        float r=otpor.read();
        postavi(r);
        wait(0.1);
    }
}