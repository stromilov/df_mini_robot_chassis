#include <SerialFlow.h>

SerialFlow rd(9,10);
const unsigned long data_to = 100; 
unsigned long tm, data_next;
#define button_pin2 2
#define button_pin3 3
#define button_pin4 4
#define button_pin5 5

void setup(void){
  pinMode(button_pin2, INPUT_PULLUP);
  pinMode(button_pin3, INPUT_PULLUP);
  pinMode(button_pin4, INPUT_PULLUP);
  pinMode(button_pin5, INPUT_PULLUP);

  rd.setPacketFormat(2, 1);
  rd.begin(0xF0F0F0F0E1LL,0xF0F0F0F0D2LL);
}
void loop(void){
  if (digitalRead(button_pin2) == LOW){
    rd.setPacketValue(2);
    rd.sendPacket();
  } else if (digitalRead(button_pin3) == LOW) {
    rd.setPacketValue(3);
    rd.sendPacket();
  } else if (digitalRead(button_pin4) == LOW) {
    rd.setPacketValue(4);
    rd.sendPacket();
  } else if (digitalRead(button_pin5) == LOW){
    rd.setPacketValue(5);
    rd.sendPacket();
  } else {
    rd.setPacketValue(0);
    rd.sendPacket();
  }
  
}
