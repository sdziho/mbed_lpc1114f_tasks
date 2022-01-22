#include "mbed.h"

DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);

int main() {
    myled1=1;
    myled2=1;
    myled3=1;
    float a=1;
    while(1) {
        
        myled1 = 0;
        myled2 = 1;
        myled3 = 1;
        wait(a);
        myled1 = 1;
        myled2 = 0;
        myled3 = 1;
        wait(a);
        myled1 = 1;
        myled2 = 1;
        myled3 = 0;
        wait(a);
        if(a!=0.1)a-=0.1;
    }
}
