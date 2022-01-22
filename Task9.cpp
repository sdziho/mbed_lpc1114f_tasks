#include "mbed.h"
#define dp23 P0_0
BusOut dioda(dp26,dp27,dp5,dp6,dp28,dp1,dp2);

DigitalOut D2(dp23);
DigitalOut D3(dp24);
DigitalOut D4(dp25);

DigitalOut red1(dp16);
DigitalOut red2(dp15);
DigitalOut red3(dp17);
DigitalOut red4(dp18);

DigitalIn kolona1(dp9);
DigitalIn kolona2(dp10);
DigitalIn kolona3(dp11);
DigitalIn kolona4(dp13);

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
    int main() {
    int niz[10] = {32,121,36,48,25,18,2,120,0,16};
    int brojac[3]={0,0,0};
    int br=0;
    while(1){
        red1=1;
        red2=1;
        red3=0;
        red4=1;
        if(kolona4==0) {
            D4=1;
            D2=1;
            D3=1;
            continue;
        }
        
        red1=0;
        red2=1;
        red3=1;
        red4=1;
        brojac[br]++;
        if(brojac[br]==1) Cifra4();
        if(brojac[br]==1) Cifra3();
        if(brojac[br]==1) Cifra2();
        
        if(kolona1==0)  diode=niz[1];
        if(kolona2==0) diode=niz[2];
        if(kolona3==0) diode=niz[3];
        
        red1=1;
        red2=0;
        red3=1;
        red4=1;
        if(kolona1==0) diode=niz[4];
        if(kolona2==0) diode=niz[5];
        if(kolona3==0) diode=niz[6];
        
        red1=1;
        red2=1;
        red3=0;
        red4=1;
        if(kolona1==0) diode=niz[7];
        if(kolona2==0) diode=niz[8];
        if(kolona3==0) diode=niz[9];
        
        red1=1;
        red2=1;
        red3=1;
        red4=0;
        if(kolona2==0) diode=niz[0];
        wait(0.1);
        br++;
        if(br==3) br=0;
        brojac[0]=0;
        brojac[1]=0; 
        brojac[2]=0;
    }
}
}
