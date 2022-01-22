#include "mbed.h"
#define dp23 P0_0
BusOut dioda(dp26,dp27,dp5,dp6,dp28,dp4,dp18);
DigitalOut D2(dp23);
DigitalOut D3(dp24);
DigitalOut D4(dp25);
DigitalOut Tacka(dp17);

void Cifra4(){
    D4=0;
    D3=1;
    D2=1;
    Tacka=1;
}
void Cifra3(){
    D4=1;
    D3=0;
    D2=1;
    Tacka=0;
}
void Cifra2(){
    D4=1;
    D3=1;
    D2=0;
    Tacka=1;
}



int main() {
    int niz[10] = {64,121,36,48,25,18,2,120,0,16};
    int broj[3]={0,0,0};
    double brojac=0;
    wait(2); 
    while(1) {
        if(brojac==12.3) break;
        brojac+=0.1;
        if(brojac<1){
            broj[2]=brojac*10;
        }
        if(brojac>=1&&brojac<10){
            broj[1]=brojac;
            int br=brojac*10;
            broj[2]=br%10;
        }
        if(brojac>=100&&brojac<1000){
            broj[0]=brojac/10;
            int br=(brojac*10)/10;
            broj[1]=br%10;
            int br2=brojac*10;
            broj[2]=br2%10;
        }
        
        
        
          dioda=niz[broj[0]];Cifra2();wait(0.005);
           dioda=niz[broj[1]]; Cifra3();wait(0.005);
           dioda=niz[broj[2]]; Cifra4(); wait(0.005);
        
    }
}
