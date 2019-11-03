#include <Arduino.h>
#include "setup.h"
#include "blynk_init.h"
#include "blynk_data.h"



void setup()
{
  // put your setup code hegre, to run once:
  Serial.begin(9600);
  Serial.println();
  pinMode(4, OUTPUT);
  blynk_init();
}

void loop()
{
  // put your main code here, to run repeatedly:
  Blynk.run();
  httpServer.handleClient();
  MDNS.update();
}

void start(int checkStart)
{
    digitalWrite(4, checkStart);
}