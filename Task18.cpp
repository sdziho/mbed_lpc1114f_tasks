#include "mbed.h"
#define dp23 P0_0

Serial pc(USBTX,USBRX);
//Analogni ulazi sa dzojstika

AnalogIn    VRx(dp11);
AnalogIn    VRy(dp10);
//Taster sa dzojstika
DigitalIn   SW(dp9);
 
//Digitalni izlaz za aktivaciju LED buffera
DigitalOut enable(dp14);
//LED prikaz
BusOut  prikazX(dp28,dp6,dp5);
BusOut  prikazY(dp27,dp26,dp25);
DigitalOut  prikazSW(dp23);
 
 void prikazi(int a){
     if(a==0) pc.puts("centar ");
     if(a==1) pc.puts("gore ");
     if(a==2) pc.puts("desno ");
     if(a==3) pc.puts("dole ");
     if(a==4) pc.puts("lijevo ");
}
int main()
{
    //aktivacija LED dioda
    enable=0;
    //Aktivacija pull-up otpornika
    SW.mode(PullUp);
    int pozicija(0);
    bool ispisi(true);
    int gore=0.7,dole=0.3,lijevo=0.3,desno=0.7;
    while(1) {
        int polozaj(0);
        
        if (VRx<lijevo)
             polozaj=2;
    
             
        else if (VRx>desno) 
            polozaj=4;
      
            
        else if (VRy<dole)
             polozaj=3;
         
             
             
        else if (VRy>gore)
             polozaj=1;
   
             
        else 
            polozaj=0;
            
 
     //   if (SW==1) prikazSW=1;
     //   else prikazSW=0;
 
        if(ispisi==true){
            if(polozaj!=pozicija){
                prikazi(polozaj);
                pozicija=polozaj;
            }
            else ispisi=false;
            
        }else ispisi=true;
        
        wait(0.01);
    }
}