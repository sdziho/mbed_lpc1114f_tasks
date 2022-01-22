#include "mbed.h"
#include "string"
#include "N5110.h"
#define dp23 P0_0
N5110 lcd(dp4,dp24,dp23,dp25,dp2,dp6,dp18);
AnalogIn voltage(dp9);
DigitalOut enable(dp14);
DigitalIn taster(dp1);


const float R = 10000;
const float VCC = 3.3;
int main() {
    enable  = 1; 
    
    char ispis[14] ;
    
    lcd.init ();
    int modprikaza  = 0; 
    
    while(1){
        
        if(taster == 1){
            if(modprikaza == 0)modprikaza = 1;
            else modprikaza = 0;
        }
        float vrijednost=voltage.read()*VCC;
        float omi=vrijednost*R/VCC;
        
        if(modprikaza == 0){
            sprintf(ispis, "%f V",vrijednost);
        }else {
            sprintf(ispis, "%f Ohm",omi);
        }
        
        lcd.clear();
        lcd.printString(ispis,0,0);
        wait(0.1);
        
    }
    
}