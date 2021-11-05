
int IRledPin1 =  13;    // LED connected to digital pin 13
int IRledPin2 =  12;    // LED connected to digital pin 12
int IRledPin3 =  11;    // LED connected to digital pin 11
int IRledPin4 =  10;    // LED connected to digital pin 10
int IRledPin5 =  9;    // LED connected to digital pin 9
 
 
void setup()   {                
  // initialize the IR digital pin as an output:
  pinMode(IRledPin1, OUTPUT);      
  pinMode(IRledPin2, OUTPUT);   
  pinMode(IRledPin3, OUTPUT);  
  pinMode(IRledPin4, OUTPUT);  
  pinMode(IRledPin5, OUTPUT); 
  Serial.begin(9600);
}
 
void loop()                     
{ 
  SendButtonFive();
  delay(400); 
  SendButtonNine(); 
  delay(400); 
  SendButtonThree();
  delay(400);  
  SendButtonTwo();
  delay(400);  
  SendButtonOne();
  delay(1000); 
  
}
 
// This procedure sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs, int LedPin) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(LedPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(LedPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
 
void SendButtonNine() {

  // This is the code for button 9 of the ir remote
  
  pulseIR(9000, IRledPin1);
  delay(4);
  pulseIR(580, IRledPin1);
  delayMicroseconds(540);
  pulseIR(580, IRledPin1);
  delayMicroseconds(540);
  pulseIR(580, IRledPin1);
  delayMicroseconds(560);
  pulseIR(580, IRledPin1);
  delayMicroseconds(540);
  pulseIR(560, IRledPin1);
  delayMicroseconds(560);
  pulseIR(560, IRledPin1);
  delayMicroseconds(560);
  pulseIR(560, IRledPin1);
  delayMicroseconds(560);
  pulseIR(560, IRledPin1);
  delayMicroseconds(560);
  pulseIR(560, IRledPin1);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin1);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin1);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin1);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin1);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin1);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin1);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin1);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin1);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin1);
  delayMicroseconds(560);
  pulseIR(560, IRledPin1);
  delayMicroseconds(560);
  pulseIR(560, IRledPin1);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin1);
  delayMicroseconds(540);
  pulseIR(560, IRledPin1);
  delayMicroseconds(560);
  pulseIR(560, IRledPin1);
  delayMicroseconds(540);
  pulseIR(580, IRledPin1);
  delayMicroseconds(560);
  pulseIR(560, IRledPin1);
  delayMicroseconds(560);
  pulseIR(580, IRledPin1);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin1);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin1);
  delayMicroseconds(540);
   pulseIR(560, IRledPin1);
  delayMicroseconds(1700);
   pulseIR(580, IRledPin1);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin1);
  delayMicroseconds(1700);
   pulseIR(580, IRledPin1);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin1);
  delay(34);
   pulseIR(8820, IRledPin1);
  delayMicroseconds(540);
   pulseIR(560, IRledPin1);

  // delay(35); // wait 35 milliseconds before sending it again
 
}

void SendButtonThree() {

  // This is the code for button 3 of the ir remote
  
  pulseIR(9000, IRledPin2);
  delay(4);
  pulseIR(580, IRledPin2);
  delayMicroseconds(540);
  pulseIR(580, IRledPin2);
  delayMicroseconds(540);
  pulseIR(580, IRledPin2);
  delayMicroseconds(560);
  pulseIR(580, IRledPin2);
  delayMicroseconds(540);
  pulseIR(560, IRledPin2);
  delayMicroseconds(560);
  pulseIR(560, IRledPin2);
  delayMicroseconds(560);
  pulseIR(560, IRledPin2);
  delayMicroseconds(560);
  pulseIR(560, IRledPin2);
  delayMicroseconds(560);
  pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin2);
  delayMicroseconds(560);
  pulseIR(560, IRledPin2);
  delayMicroseconds(540);
  pulseIR(560, IRledPin2);
  delayMicroseconds(560);
  pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
  pulseIR(580, IRledPin2);
  delayMicroseconds(560);
  pulseIR(560, IRledPin2);
  delayMicroseconds(560);
  pulseIR(580, IRledPin2);
  delayMicroseconds(560);
  pulseIR(560, IRledPin2);
  delayMicroseconds(560);
  pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin2);
  delayMicroseconds(1700);
   pulseIR(580, IRledPin2);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin2);
  delayMicroseconds(560);
   pulseIR(580, IRledPin2);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin2);
  delay(34);
   pulseIR(8820, IRledPin2);
  delayMicroseconds(540);
   pulseIR(560, IRledPin2);

  // delay(35); // wait 35 milliseconds before sending it again
 
}

void SendButtonFive() {

  // This is the code for button 5 of the ir remote
  
  pulseIR(9000, IRledPin5);
  delay(4);
  pulseIR(580, IRledPin5);
  delayMicroseconds(540);
  pulseIR(580, IRledPin5);
  delayMicroseconds(540);
  pulseIR(580, IRledPin5);
  delayMicroseconds(560);
  pulseIR(580, IRledPin5);
  delayMicroseconds(540);
  pulseIR(560, IRledPin5);
  delayMicroseconds(560);
  pulseIR(560, IRledPin5);
  delayMicroseconds(560);
  pulseIR(560, IRledPin5);
  delayMicroseconds(560);
  pulseIR(560, IRledPin5);
  delayMicroseconds(560);
  pulseIR(560, IRledPin5);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin5);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin5);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin5);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin5);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin5);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin5);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin5);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin5);
  delayMicroseconds(560);
  pulseIR(560, IRledPin5);
  delayMicroseconds(560);
  pulseIR(560, IRledPin5);
  delayMicroseconds(560);
  pulseIR(560, IRledPin5);
  delayMicroseconds(560);
  pulseIR(560, IRledPin5);
  delayMicroseconds(540);
  pulseIR(560, IRledPin5);
  delayMicroseconds(560);
  pulseIR(560, IRledPin5);
  delayMicroseconds(1700);
  pulseIR(580, IRledPin5);
  delayMicroseconds(560);
  pulseIR(560, IRledPin5);
  delayMicroseconds(1700);
  pulseIR(580, IRledPin5);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin5);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin5);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin5);
  delayMicroseconds(1700);
   pulseIR(580, IRledPin5);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin5);
  delayMicroseconds(560);
   pulseIR(580, IRledPin5);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin5);
  delay(34);
   pulseIR(8820, IRledPin5);
  delayMicroseconds(540);
   pulseIR(560, IRledPin5);

  // delay(35); // wait 35 milliseconds before sending it again
 
}

void SendButtonTwo() {

  // This is the code for button 2 of the ir remote
  
  pulseIR(9000, IRledPin3);
  delay(4);
  pulseIR(580, IRledPin3);
  delayMicroseconds(540);
  pulseIR(580, IRledPin3);
  delayMicroseconds(540);
  pulseIR(580, IRledPin3);
  delayMicroseconds(560);
  pulseIR(580, IRledPin3);
  delayMicroseconds(540);
  pulseIR(560, IRledPin3);
  delayMicroseconds(560);
  pulseIR(560, IRledPin3);
  delayMicroseconds(560);
  pulseIR(560, IRledPin3);
  delayMicroseconds(560);
  pulseIR(560, IRledPin3);
  delayMicroseconds(560);
  pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin3);
  delayMicroseconds(560);
  pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin3);
  delayMicroseconds(560);
  pulseIR(560, IRledPin3);
  delayMicroseconds(540);
  pulseIR(560, IRledPin3);
  delayMicroseconds(560);
  pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
  pulseIR(580, IRledPin3);
  delayMicroseconds(560);
  pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
  pulseIR(580, IRledPin3);
  delayMicroseconds(560);
  pulseIR(560, IRledPin3);
  delayMicroseconds(560);
  pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin3);
  delayMicroseconds(1700);
   pulseIR(580, IRledPin3);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin3);
  delayMicroseconds(560);
   pulseIR(580, IRledPin3);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin3);
  delay(34);
   pulseIR(8820, IRledPin3);
  delayMicroseconds(540);
   pulseIR(560, IRledPin3);

  // delay(35); // wait 35 milliseconds before sending it again
 
}

void SendButtonOne() {

  // This is the code for button 1 of the ir remote
  
  pulseIR(9000, IRledPin4);
  delay(4);
  pulseIR(580, IRledPin4);
  delayMicroseconds(540);
  pulseIR(580, IRledPin4);
  delayMicroseconds(540);
  pulseIR(580, IRledPin4);
  delayMicroseconds(560);
  pulseIR(580, IRledPin4);
  delayMicroseconds(540);
  pulseIR(560, IRledPin4);
  delayMicroseconds(560);
  pulseIR(560, IRledPin4);
  delayMicroseconds(560);
  pulseIR(560, IRledPin4);
  delayMicroseconds(560);
  pulseIR(560, IRledPin4);
  delayMicroseconds(560);
  pulseIR(560, IRledPin4);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin4);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin4);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin4);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin4);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin4);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin4);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin4);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin4);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin4);
  delayMicroseconds(560);
  pulseIR(560, IRledPin4);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin4);
  delayMicroseconds(560);
  pulseIR(560, IRledPin4);
  delayMicroseconds(540);
  pulseIR(560, IRledPin4);
  delayMicroseconds(560);
  pulseIR(560, IRledPin4);
  delayMicroseconds(1700);
  pulseIR(580, IRledPin4);
  delayMicroseconds(560);
  pulseIR(560, IRledPin4);
  delayMicroseconds(560);
  pulseIR(580, IRledPin4);
  delayMicroseconds(1700);
  pulseIR(560, IRledPin4);
  delayMicroseconds(560);
  pulseIR(560, IRledPin4);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin4);
  delayMicroseconds(1700);
   pulseIR(580, IRledPin4);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin4);
  delayMicroseconds(560);
   pulseIR(580, IRledPin4);
  delayMicroseconds(1700);
   pulseIR(560, IRledPin4);
  delay(34);
   pulseIR(8820, IRledPin4);
  delayMicroseconds(540);
   pulseIR(560, IRledPin4);

  // delay(35); // wait 35 milliseconds before sending it again
 
}
