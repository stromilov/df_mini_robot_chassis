#include <SerialFlow.h> 

SerialFlow rd(9, 10);
//Двигатель левый
int in1 = 5;
int in2 = 4;
//Двигатель правый
int in3 = 3;
int in4 = 2;

void setup(void){
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.begin(57600);
  rd.setPacketFormat(2, 1);
  rd.begin(0xF0F0F0F0D2LL,0xF0F0F0F0E1LL);
}
void loop(void){
  unsigned int v;
  if( rd.receivePacket() ){
    v = rd.getPacketValue(0);
    Serial.println(v);
    if (v == 2) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    } else if (v == 3) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    } else if (v == 4) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    } else if (v == 5) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    } else {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
  }
}
