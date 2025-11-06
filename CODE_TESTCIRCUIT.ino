//Code to plot EMG signal = check connection between muscles contraction-Circuit-Arduino//

//Define the anolog input pin (i.e. what pin the will receive the output signal from the circuit)
int analogPin=A0;

//Initialise the analog input pin
int val=0;

void setup() {
  
  Serial.begin(9600); //Begin connection with monitor
}

void loop() { //To repeat indefinitely the steps below//
  val= analogRead(analogPin); //Read value of input signal at pin A0
  Serial.println(val); //Print input signal value 
}
