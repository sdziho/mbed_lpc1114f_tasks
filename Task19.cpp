#include "mbed.h"
#define dp23 P0_0

BusOut diode(dp23, dp24, dp25, dp26, dp27, dp5, dp6, dp28);
Serial pc(USBTX,USBRX);
DigitalOut enable (dp14);

int main() {
    enable=0;
    diode=256;
    while(1) {
        if(pc.readable()){
            char c=pc.getc()-'0';
            if(c==0) diode=255-254;
            if(c==1) diode=255-253;
            if(c==2) diode=255-251;
            if(c==3) diode=255-247;
            if(c==4) diode=255-239;
            if(c==5) diode=255-223;
            if(c==6) diode=255-191;
            if(c==7) diode=255-127;
        }
        wait(0.5);
    }
}
