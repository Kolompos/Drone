#include <IBusBM.h>
#include <Joystick.h>

IBusBM IBus; 
Joystick_ Joystick(0x04,JOYSTICK_TYPE_GAMEPAD,
  0, 0,                  // Button Count, Hat Switch Count
  true, true, true,     // X (CH1) and Y (CH2), but no Z Axis (CH3) and so on
  true, true, true,    // No Rx, Ry, or Rz
  true, true,           // No rudder or throttle 
  true, true, false);   // No accelerator, brake, or steering
  
//#define DEBUG

void setup() {
  #ifdef DEBUG
    //Serial port for debug
    Serial.begin(115200);
    while (!Serial) {
      delay(50); // wait for serial port to connect. Needed for native USB port only
    }
    
    Serial.println("iBUS starting...");
  #endif
  
  // iBUS connected to serial1
  IBus.begin(Serial1);
  
  #ifdef DEBUG
    Serial.println("Joystick starting...");
  #endif
  
  // Initialize Joystick Library
  Joystick.setXAxisRange(1000, 2000);
  Joystick.setYAxisRange(1000, 2000);
  Joystick.setZAxisRange(1000, 2000);
  Joystick.setRxAxisRange(1000, 2000);
  Joystick.setRyAxisRange(1000, 2000);
  Joystick.setRzAxisRange(1000, 2000);
  Joystick.setRudderRange(1000, 2000);
  Joystick.setThrottleRange(1000, 2000);
  Joystick.setAcceleratorRange(1000, 2000);
  Joystick.setBrakeRange(1000, 2000);
  
  Joystick.begin(false);
  
  #ifdef DEBUG
    Serial.println("Setup finished!");
  #endif
}

int channelValues[10] = {0,0,0,0,0,0,0,0,0,0};

void loop() {
  // read and save 10 channels
  for (int i=0; i<10 ; i++) {
    channelValues[i] = IBus.readChannel(i);
    //Debug
  }
  
  Joystick.setXAxis(channelValues[0]);    //OK
  Joystick.setYAxis(channelValues[1]);    //OK
  Joystick.setZAxis(channelValues[7]);    //OK
  Joystick.setRxAxis(channelValues[3]);
  Joystick.setRyAxis(channelValues[4]);
  Joystick.setRzAxis(channelValues[5]);
  Joystick.setRudder(channelValues[6]);
  Joystick.setThrottle(channelValues[2]); //OK
  Joystick.setAccelerator(channelValues[8]);
  Joystick.setBrake(channelValues[9]);
  
  Joystick.sendState();
  
  #ifdef DEBUG
    Serial.print(channelValues[0]);
    Serial.print(channelValues[1]);
    Serial.print(channelValues[2]);
    Serial.print(channelValues[3]);
    Serial.print(channelValues[4]);
    Serial.print(channelValues[5]);
    Serial.print(channelValues[6]);
    Serial.print(channelValues[7]);
    Serial.print(channelValues[8]);
    Serial.println(channelValues[9]);
  #endif
  delay(5);
}
