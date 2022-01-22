#include "mbed.h"
#include <cmath>
/*
AnalogOut osciloskop(PTE30);

const float pi = 3.14;
const float period  =1/400;
const float br_uzoraka  = 50;
const float razlocuvost = 50 * 0.000001;
const float T_step = period/br_uzoraka; //korak crtanja ,jer se jedan period realizuje sa 50 uzoraka prema tekstu
const float max_vrijednost = 1; // sa grafa vidimo

float abssin(float t){
    return (1-sin(t))/2;
}

int main(){
    
     float vrijednosti[51];
    
    for(int i = 0; i <= br_uzoraka; i++)
        vrijednosti[i] = abssin(i * T_step); //crtamo samo VV ...
        
    int brojac = 0;
    
    while(1) {
        for(float i=0;i<1;i++){
            osciloskop.write(sin());
        }
        osciloskop.write(vrijednosti[brojac++]/3.3);
        if(brojac== br_uzoraka)
            brojac = 0;
        wait(T_step);    
    }
}
*/
AnalogOut signal(PTE30);

int main(){
    float i(1);
    while(1){
    for(i=1;i>=0;i-=0.04){
        signal.write(sin(i*3.14));
        wait_us(50);
    }
    }
}
