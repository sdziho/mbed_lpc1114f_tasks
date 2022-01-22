#include "mbed.h"
#define dp23 P0_0

DigitalOut led0(dp23);
DigitalOut led1(dp24);
DigitalOut led2(dp25);
DigitalOut led3(dp26);
DigitalOut led4(dp27);
DigitalOut led5(dp5);
DigitalOut led6(dp6);
DigitalOut led7(dp28);
DigitalOut enable(dp14);
Serial terminal(USBTX, USBRX);
float Tpwm=0.1;

void Postavi(float vrijednost, int koja){
    if (koja==0) led0=1;
    else if (koja==1) led1=1;
    else if (koja==2) led2=1;
    else if (koja==3) led3=1;
    else if (koja==4) led4=1;
    else if (koja==5) led5=1;
    else if (koja==6) led6=1;
    else if (koja==7) led7=1;
    wait(Tpwm*vrijednost);
    if (koja==0) led0=0;
    else if (koja==1) led1=0;
    else if (koja==2) led2=0;
    else if (koja==3) led3=0;
    else if (koja==4) led4=0;
    else if (koja==5) led5=0;
    else if (koja==6) led6=0;
    else if (koja==7) led7=0;
    wait(1-Tpwm*vrijednost);
}
int main() {
    enable=0;
    char karakter;
    led0=0;
    led1=0;
    led2=0;
    led3=0;
    led4=0;
    led5=0;
    led6=0;
    led7=0;
    int koja=0, desetice=0, jedinice=0;
    float vrijednost=0;
    while(1) {
        if (terminal.readable()) {
            karakter=terminal.getc();
            if (karakter=='0') koja=0; //00000001
            else if (karakter=='1') koja=1; //00000010
            else if (karakter=='2') koja=2; //00000100
            else if (karakter=='3') koja=3; //00001000
            else if (karakter=='4') koja=4; //00010000
            else if (karakter=='5') koja=5; //00100000
            else if (karakter=='6') koja=6; //01000000
            else if (karakter=='7') koja=7; //10000000
            while (!terminal.readable());
            karakter=terminal.getc();
            if (karakter=='0') desetice=0;
            else if (karakter=='1') desetice=1;
            else if (karakter=='2') desetice=2;
            else if (karakter=='3') desetice=3;
            else if (karakter=='4') desetice=4;
            else if (karakter=='5') desetice=5;
            else if (karakter=='6') desetice=6;
            else if (karakter=='7') desetice=7;
            else if (karakter=='8') desetice=8;
            else if (karakter=='9') desetice=9;
            while (!terminal.readable());
            karakter=terminal.getc();
            if (karakter=='0') jedinice=0;
            else if (karakter=='1') jedinice=1;
            else if (karakter=='2') jedinice=2;
            else if (karakter=='3') jedinice=3;
            else if (karakter=='4') jedinice=4;
            else if (karakter=='5') jedinice=5;
            else if (karakter=='6') jedinice=6;
            else if (karakter=='7') jedinice=7;
            else if (karakter=='8') jedinice=8;
            else if (karakter=='9') jedinice=9;
            vrijednost=desetice*10+jedinice;
            vrijednost/=100;
            Postavi(vrijednost, koja);
        }
    }
}