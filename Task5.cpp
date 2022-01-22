#include "mbed.h"

DigitalOut myled(LED1);

int main() {
    float T=1;
    float T1=T;
    float a=0.03;
    int brojac=0;
    while(1) {
        myled = 0;
        wait(T);
        myled = 1;
        wait(2*T1-T);
        if(brojac==30){
             a=a*(-1);
             brojac=0;
        }
        T=T+a;
        brojac++;
    }
}
