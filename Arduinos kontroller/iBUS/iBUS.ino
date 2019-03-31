#include <IBusBM.h>

IBusBM IBus; 

void setup() {
  // initialize serial port for debug
  Serial.begin(115200);

  // iBUS connected to serial1
  IBus.begin(Serial);
  
  Serial.println("Start iBUS monitor");

}


#define TEMPBASE 400    // base value for 0'C

// sensor values
uint16_t speed=0;
uint16_t temp=TEMPBASE+200; // start at 20'C

void loop() {
  // show first 8 servo channels
  for (int i=0; i<10 ; i++) {
    Serial.print(IBus.readChannel(i));
    Serial.print(" ");
  }
  Serial.print("Cnt=");
  Serial.println(IBus.cnt_rec); // count of how many times servo values have been updated
  
  delay(500);
}
