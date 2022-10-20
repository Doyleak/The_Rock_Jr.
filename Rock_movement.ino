/* Code to get robot moving with the PS joysticks.
 * 
 */

// PS2 Controller Constants
#include "PS2X_lib.h"  //for v1.6  //Adds PS2 controller library
#define PS2_DAT   14   //P1.7 <-> brown wire
#define PS2_CMD   15   //P1.6 <-> orange wire
#define PS2_SEL   34   //P2.3 <-> yellow wire (also called attention)
#define PS2_CLK   35   //P6.7 <-> blue wire
PS2X ps2x;             // create PS2 Controller Class

//Defines the states
#define STOP    0
#define GO      1
int STATE = STOP;

void setup() {
  Serial1.begin(57600); //ZJE: changed from Arduino deafult of 9600
  delayMicroseconds(500 * 1000); //added delay to give wireless ps2 module some time to startup
  PS2ControllerSetup();
}

void loop() {
    PS2ButtonDetect();
    switch (STATE) {
      case STOP:
        Serial.println("I am not moving.");
        noSchmoove();
        break;
      case GO:
        Serial.println("I am moving.");
        Schmoove();
        break;
    }
}

void PS2ControllerSetup(){
  //setup pins and settings: GamePad(clock, command, attention, data, Pressures?, Rumble?)
  ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
}

void PS2ButtonDetect() {
  ps2x.read_gamepad();
}

void noSchmoove() {
  
}

void Schmoove() {
  
}
