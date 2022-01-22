#include "mbed.h"
#define dp23 P0_0
 
BusOut prikaz1(dp26,dp25,dp24,dp23);
BusOut prikaz2(dp28,dp6,dp5,dp27);
 
DigitalOut enable(dp14);
InterruptIn taster(dp1);
 
const float T(0.2);
int brojac1(0);
int brojac2(0);
Ticker vrijeme;
Timer debounce;

void prikaz(){
    brojac1=(brojac1+1)%16;
    prikaz1=brojac1;
}

void provjera(){
    if(debounce.read_ms()>200){
        brojac2=(brojac2+1)%16;
        prikaz2=brojac2;
    }
}

int main(){
    
    enable=0;
    vrijeme.attach(&prikaz,T);
    debounce.start();
    taster.rise(&provjera);
    
    
    while(1);
}