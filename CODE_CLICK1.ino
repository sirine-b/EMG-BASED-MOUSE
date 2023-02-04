#include <Mouse.h>
// set pin number for the electrode connected to deltoid :
int mouseStop = A0;
int mouseClick = A1;
int VAL=0;
void setup() {  // initialize the electrode' input:
  pinMode(mouseClick, INPUT); //set signal from electrode as input//
  Serial.begin(9600);
  pinMode(mouseStop,INPUT);
  // initialize mouse control:
  Mouse.begin();}
void loop(){
  VAL=analogRead(mouseClick);
  Serial.println(VAL);
   if(VAL>300);{//if deltoid is contracted and voltage is generated//
    Mouse.click(); //left click with the mouse//
    delay(500);
   }
   if (analogRead(mouseStop) > 1){
    Mouse.end();
    delay(500);
   }
}
