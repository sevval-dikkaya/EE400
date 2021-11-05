#include <IRremote.h>
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;


int COUNTER = 0;
int receiverNumber;

#define IRpin_PIN      PIND
#define IRpin          2

 
// the maximum pulse we'll listen for - 10 milliseconds
#define MAXPULSE 10000
 
// what our timing resolution should be, larger is better
// as its more 'precise' - but too large and you wont get
// accurate timing
#define RESOLUTION 20 
 
// we will store up to 100 pulse pairs (this is -a lot-)
uint16_t pulses[100][2];  // pair is high and low pulse 
uint8_t currentpulse = 0; // index for pulses we're storing


void receivingIR() {
  if (irrecv.decode(&results)) {
    Serial.println("");
    Serial.println("");
    Serial.println(results.value, BIN);
    COUNTER = 1;
    if (results.value == 0b111111111001000001101111){
      Serial.println("this is button 9");
    }
    if (results.value == 0b111111111110001000011101){
      Serial.println("this is button 3");
    }
    irrecv.resume(); // Receive the next value
  }
}

void printpulses(void) {
  //Serial.println("");
  // Serial.print("FROM:  "); Serial.println(receiverNumber);
  Serial.println("\n\r\n\rReceived: \n\rOFF \tON");
  for (uint8_t i = 0; i < currentpulse; i++) {
    Serial.print(pulses[i][0] * RESOLUTION, DEC);
    Serial.print(" usec, ");
    Serial.print(pulses[i][1] * RESOLUTION, DEC);
    Serial.println(" usec");
  }
  COUNTER = 0;
    
}


void setup() {  
  Serial.begin(9600);
  irrecv.enableIRIn();  // Start the receiver
}

void loop() {
   receivingIR(); 
   uint16_t highpulse, lowpulse;  // temporary storage timing
   highpulse = lowpulse = 0; // start out with no pulse length
  
  
//  while (digitalRead(IRpin)) { // this is too slow!
    while (IRpin_PIN & (1 << IRpin)) {
     // pin is still HIGH
     // count off another few microseconds
     highpulse++;
     delayMicroseconds(RESOLUTION);
 
     // If the pulse is too long, we 'timed out' - either nothing
     // was received or the code is finished, so print what
     // we've grabbed so far, and then reset
     if ((highpulse >= MAXPULSE) && (currentpulse != 0)) {
       while (COUNTER){
       printpulses();
       }
       currentpulse=0;
       return;
     }
  }
  // we didn't time out so lets stash the reading
  pulses[currentpulse][0] = highpulse;
  
  // same as above
  while (! (IRpin_PIN & _BV(IRpin))) {
     // pin is still LOW
     lowpulse++;
     delayMicroseconds(RESOLUTION);
     if ((lowpulse >= MAXPULSE)  && (currentpulse != 0)) {
       while (COUNTER){
       printpulses();
       }
       currentpulse=0;
       return;
     }
  }
  pulses[currentpulse][1] = lowpulse;
 
  // we read one high-low pulse successfully, continue!
  currentpulse++;

}
