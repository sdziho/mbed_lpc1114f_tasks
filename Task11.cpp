# include "mbed.h"
# define dp23 P0_0
# include "stdio.h"
# include "SPI_TFT_ILI9341.h"
# include "string"
# include "Arial12x12.h"
# include "Arial24x23.h"
# include "Arial28x28.h"
# include "font_big.h"

SPI_TFT_ILI9341 TFT( dp2 , dp1 , dp6 , dp24 , dp23 , dp25 ,"TFT");
AnalogIn voltage(dp9);
DigitalOut enable(dp14);

//320x240 pixels            (0,0)           (320,0)
                                                                
                                                                
//                          (0,240)         (320,240)    
int main() {
    TFT.claim(stdout);
    TFT.set_orientation(1);
    TFT.background(Blue);
    TFT.foreground(White);
    TFT.cls();
    
    int vrijeme=0;
    char tacka[2]={50,180};
    while(1) {
        
        TFT.foreground(Black);
        TFT.background(White);
       
       // TFT.cls();
        TFT.set_font((unsigned char*) Arial12x12);
        TFT.locate(150,0);
        TFT.printf("Napon: %fV",voltage.read()*3.3*1000);
        TFT.locate(150,15);
        TFT.printf("Temp: %fC",voltage.read()*3.3*100);
        TFT.locate(150,30);
        TFT.printf("Vrijeme: %ds",vrijeme);
        
            //    x,y
        TFT.line(50,5,50,250,Black);
        TFT.line(0,180,300,180,Black);
        
        TFT.set_font((unsigned char*) Arial24x23);
        TFT.locate(21,180);
        TFT.printf("%d",20);
        TFT.locate(21,100);
        TFT.printf("%d",30);
        TFT.locate(21,20);
        TFT.printf("%d",40);
        
        if(vrijeme!=0){
            TFT.fillcircle(50+vrijeme,180-voltage.read()*100,2,Black);
            TFT.line(tacka[0],tacka[1],50+vrijeme,180-voltage.read()*100,Red);
            tacka[0]=50+vrijeme;
            tacka[1]=180-voltage.read()*100;
        }
        wait(1);
        vrijeme++;
        if(vrijeme>=50) break;
    }
}
