#include <Mouse.h>

//Define the anolog pins (i.e.: what action the muscle they receive a signal from causes)//
int mouse_right=A2;
int mouse_left=A3;

//Initialise the analog input pins//
int val2=0; 
int val3=0;

void setup() {
  //Start communication with serial monitor:
  Serial.begin(9600);
}

void loop() {
  //Assign voltage generated from muscle contraction to a variable 'valX' with X=number of the analog pin the "muscle channel" is connected to//
  val2=analogRead(mouse_right);
  val3=analogRead(mouse_left);
  
  //Serial.println(val);
  
  if(val2>300 & val3<500){//if  is brachiaradialis is contracted = wrist extended
      Mouse.move(30,0); //move mouse right
      delay(250);}
  else if (val2<600 & val3>250){//if flexor carpi radialis is contracted = wrist flexed
      Mouse.move(-30,0); //move mouse left
      delay(250);}
  else{
      Mouse.end();}
    }
