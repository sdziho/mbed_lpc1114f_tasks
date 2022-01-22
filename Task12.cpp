#include "mbed.h"

#define T 0.00005

PwmOut led1(dp18);
AnalogIn potenciometar(dp9);
DigitalOut enable(dp14);

int main() {
    enable = 0;
    
    led1.period(T);
    
    while(1) {
        led1= potenciometar.read();
        
    }
}
