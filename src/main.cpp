#include <Arduino.h>
#include "setup.h"
#include "blynk_init.h"
#include "blynk_data.h"



void setup()
{
  // put your setup code hegre, to run once:
  Serial.begin(9600);
  Serial.println();
  pinMode(14, OUTPUT); // Верхний вентилятор
  pinMode(12, OUTPUT); // Боковые вентиляторы
  pinMode(13, OUTPUT); // Задний вентилятор
  pinMode(15, OUTPUT); // Подогрев
  blynk_init();
}

void loop()
{
  // put your main code here, to run repeatedly:
  Blynk.run();
  httpServer.handleClient();
  MDNS.update();
}

void start(int time_sushki, int rejim, int temp_sushki, int checkStart)
{
  if (checkStart == 1) {
  switch (rejim) {
    case 1:
    digitalWrite(14, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(15, LOW);
    break;
    case 2:
    digitalWrite(14, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(15, LOW);
    break;
    case 3:
    digitalWrite(14, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(15, HIGH);
    break;
  }

  } else {
    digitalWrite(14, LOW);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(15, LOW);
  }
    
    
}