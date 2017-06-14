#include <Arduino.h>
#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  SerialUSB.begin(115200);
  SigFox.begin(19200);
  while(!SerialUSB);
  
  SerialUSB.println("Init OK !");
  SigFox.print("+++");
  delay(500);

  SigFox.print("AT/L\r");
  SerialUSB.println("Software version: ");delay(1000);
  while(!SigFox.available()){}
  while (SigFox.available()){
    SerialUSB.write(SigFox.read());
  }

  SerialUSB.println("\nSigfox ID : ");
  SigFox.print("AT$ID\r");delay(1000);
  while(!SigFox.available()){}
  while (SigFox.available()){
    SerialUSB.write(SigFox.read());
  }

  SerialUSB.println("\nSending first message : ");
  SigFox.print("AT$SB=1\r");delay(1000);
 while(!SigFox.available()){}
   //make sure transmission is complete
  delay(7000);
  while (SigFox.available()){
    SerialUSB.write(SigFox.read());
  }
  
  SerialUSB.println("\nSend another message, asking for reply");
  SigFox.print("AT$SF=0F,1\r");
  
  
}

void loop() {
  while (SigFox.available()){
    SerialUSB.write(SigFox.read());
  }
}
