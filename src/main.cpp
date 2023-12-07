#include <Arduino.h>

#define relePin A1
#define driverSig 13
#define opticSig A2

void setup() {
  pinMode(relePin, OUTPUT); //пин для реле
  digitalWrite(relePin, HIGH);
  
  pinMode(driverSig, OUTPUT); //выход драйвера на открытие
  digitalWrite(driverSig, LOW);
  
  pinMode(opticSig, INPUT); //наличие света

}

void loop() {
  if(digitalRead(relePin) == LOW){ //если реле подало сигнал
   if(digitalRead(opticSig) == LOW){//если мундштука нет
    delayMicroseconds(150);//150
    if(digitalRead(opticSig) == LOW){ //если мундштука нет, то открываем клапан
      delay(15); //было 30, время открытия клапана
      digitalWrite(driverSig, HIGH);
      delay(100); //время, через к-е клапан закроется
      digitalWrite(driverSig, LOW);
      while(digitalRead(relePin) == LOW){} //если станок остановился, а реле открыто
      }
    }
  }
  delay(30);
} 