#include <IRremote.h>
int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;


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
long int x = 0b00000000000000000000000000000000; // unknown signal
int COUNTER = 0;
int receiverNumber;
int motorPin=6;//motor kullanımı testi için tanımlanmış pin

void printpulses(void) {
  Serial.println(x, BIN); 
  if (x == 0b111111110000001011111101){     
     //Serial.println("this is button 5");        
     Serial.println("5");
    }
  if (x == 0b111111111001000001101111){
     //Serial.println("this is button 9");
     Serial.println("4");
    }
  if (x == 0b111111111110001000011101){
     //Serial.println("this is button 3");
     Serial.println("3");
  }
  if (x == 0b111111110110001010011101){
      //Serial.println("this is button 2");
      Serial.println("2");
    }
  if (x == 0b111111111010001001011101){
    //Serial.println("this is button 1");
    Serial.println("1");
  }
  COUNTER = 0;
}

void setup() {  
  Serial.begin(9600);
  irrecv.enableIRIn();  // this will enable the timer interrupt which consumes a small amount of cpu every 50 μs.
  
  pinMode(IRpin, INPUT);
  pinMode(motorPin,OUTPUT);//motor kullanımı testi için çıkış pini ataması
}

void loop() {
  
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

      for (uint8_t i = 0; i < currentpulse; i++) {
    
        if ((pulses[i][1] * RESOLUTION < 600) && (pulses[i][1] * RESOLUTION > 400) && ( pulses[i + 1][0] * RESOLUTION < 600) && ( pulses[i + 1][0] * RESOLUTION > 400)){
          bitWrite(x, 0, 0);  // write 0 to the least significant bit of x
          x = x << 1; 
        }
        if ((pulses[i][1] * RESOLUTION < 600) && (pulses[i][1] * RESOLUTION > 400) && ( pulses[i + 1][0] * RESOLUTION < 1600) && ( pulses[i + 1][0] * RESOLUTION > 1400)){
          bitWrite(x, 0, 1);  // write 1 to the least significant bit of x
          x = x << 1; 
        }
       }
       x = x >> 1;
         if ((x == 0b111111111001000001101111) || (x == 0b111111111110001000011101) || (x == 0b111111110110001010011101) || (x == 0b111111111010001001011101)||(x == 0b111111110000001011111101) ){
        COUNTER = 1;
        }
      
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
      for (uint8_t i = 0; i < currentpulse; i++) {
    
        if ((pulses[i][1] * RESOLUTION < 600) && (pulses[i][1] * RESOLUTION > 400) && ( pulses[i + 1][0] * RESOLUTION < 600) && ( pulses[i + 1][0] * RESOLUTION > 400)){
          bitWrite(x, 0, 0);  // write 0 to the least significant bit of x
          x = x << 1; 
        }
        if ((pulses[i][1] * RESOLUTION < 600) && (pulses[i][1] * RESOLUTION > 400) && ( pulses[i + 1][0] * RESOLUTION < 1600) && ( pulses[i + 1][0] * RESOLUTION > 1400)){
          bitWrite(x, 0, 1);  // write 1 to the least significant bit of x
          x = x << 1; 
        }
       }
       x = x >> 1;
         if ((x == 0b111111111001000001101111) || (x == 0b111111111110001000011101) || (x == 0b111111110110001010011101) || (x == 0b111111111010001001011101)||(x == 0b111111110000001011111101) ){
        COUNTER = 1;
        }
      
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
