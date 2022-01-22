#include "mbed.h"
#define dp23 P0_0
BusOut dioda(dp26,dp27,dp5,dp6,dp28,dp4,dp18);
DigitalOut D2(dp23);
DigitalOut D3(dp24);
DigitalOut D4(dp25);
DigitalIn taster1(dp1);
DigitalIn taster2(dp2);

void Cifra4(){
    D4=0;
    D3=1;
    D2=1;
}
void Cifra3(){
    D4=1;
    D3=0;
    D2=1;
}
void Cifra2(){
    D4=1;
    D3=1;
    D2=0;
}



int main() {
    int niz[10] = {64,121,36,48,25,18,2,120,0,16};
    int broj[3]={0,0,0};
    int brojac=0;
    int stanje=0;
    while(1) {
        if(taster1==1){
            stanje=1;
            brojac+=1;
            if(brojac<10){
                broj[2]=brojac;
            }
            if(brojac>=10&&brojac<100){
                broj[1]=brojac/10;
                broj[2]=brojac%10;
            }
            if(brojac>=100&&brojac<1000){
                broj[0]=brojac/100;
                broj[1]=(brojac/10)%10;
                broj[2]=brojac%10;
            }
        }
        if(taster2==1){
            stanje=1;
            brojac-=1;
            if(brojac<10){
                broj[2]=brojac;
            }
            if(brojac>=10&&brojac<100){
                broj[1]=brojac/10;
                broj[2]=brojac%10;
            }
            if(brojac>=100&&brojac<1000){
                broj[0]=brojac/100;
                broj[1]=(brojac/10)%10;
                broj[2]=brojac%10;
            }
        }
        
           dioda=niz[broj[0]]; Cifra2(); wait(0.005);
           dioda=niz[broj[1]];Cifra3(); wait(0.005);
           dioda=niz[broj[2]];Cifra4(); wait(0.005);
        while(stanje==1){
             stanje=taster1;
        }
    }
}
