
#include "mbed.h"
#define dp23 P0_0


BusOut diodedisp (dp26,dp27,dp5,dp6,dp28,dp4,dp18);
DigitalOut Tacka(dp17);
InterruptIn taster1(dp1); // START/stop  //pale se sa 1
InterruptIn taster2(dp2);  //reset

DigitalOut D2(dp23);   //pale se sa 0 a gase sa 1
DigitalOut D3(dp24);
DigitalOut D4(dp25);
//DigitalOut enable (p14) //ne treba


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

const float desetinka(0.1);
const float t(0.005); //vrijeme za koje ispisujemo cifru na ekran
int vrijeme(0); //trenutno vrijeme
int start_pritisnut(0);

Ticker ispisivanje_vremena;
Ticker brojac; //povecava vrijeme za 0.1 svakih 0.1sekundi
Timer debounce_T1, debounce_T2; //samo ako se taster pritisne neko vrijeme


void povecaj_brojac(){
    if(start_pritisnut % 2 !=0){ //start je pritisnut
        vrijeme=vrijeme+1;
        if(vrijeme == 999)vrijeme = 0;
    }
}

//implementirati da se stop/start moze pritisnut uvijek a ne samo po 1
void start_stop(){
    if(debounce_T1.read_ms() > 200){  //ovdje treba read_ms u milisekundama !!
        //prvi put start se pritisce, povecamo start_pritisnut- ako je je neparan => start pitisnut, inace stop
        start_pritisnut = start_pritisnut+1;
        debounce_T1.reset();
    }
}

void reset(){
    if(debounce_T2.read_ms() > 200){
        vrijeme = 0;
        start_pritisnut = 0; 
        debounce_T2.reset();
    }
}

//diode se pale na 0 na 7mo segmentom displeju
void ispisivanje_na_displej(){
    //brojevi      0   1    2  3   4   5 6   7   8   9
    int niz[10] = {64 ,121,36 ,48,25 ,18,2, 120, 0, 16}; //kombinacije za paljenje dioda na jedno poziciji
    int a=vrijeme%10;
    int b=(vrijeme/10)%10;
    int c=vrijeme/100;
    Cifra4(); diodedisp = niz[a];
    Cifra3(); diodedisp = niz[b];
    Cifra2(); diodedisp = niz[c];
}


int main(){
    ispisivanje_vremena.attach(&ispisivanje_na_displej,t); //ispisujemo svakih t vremena, t malo bas malo za ljudsko oko da ne vidi promjenu
    brojac.attach(&povecaj_brojac,desetinka);
    debounce_T1.start(); 
    taster1.rise(&start_stop);
    debounce_T2.start();
    taster2.rise(&reset);
    
    
    while(1);    
}