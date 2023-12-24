#include "Power.h"

#define KEY_1_PIN 15
#define KEY_2_PIN 14
#define KEY_3_PIN 13

void setup() {
  Serial.begin(115200);
  Power.begin();

  pinMode(KEY_1_PIN, INPUT_PULLUP);
  pinMode(KEY_2_PIN, INPUT_PULLUP);
  pinMode(KEY_3_PIN, INPUT_PULLUP);

//  pinMode(LED_R_PIN, OUTPUT);
//  pinMode(LED_G_PIN, OUTPUT);
//  pinMode(LED_B_PIN, OUTPUT);
//  digitalWrite(LED_R_PIN, HIGH);
//  digitalWrite(LED_G_PIN, HIGH);
//  digitalWrite(LED_B_PIN, HIGH);
}

void loop() {
  if (!digitalRead(KEY_1_PIN)) {
//    digitalWrite(LED_R_PIN, LOW);
    Serial.println("KEY 1 Pressed");
  } else {
//    digitalWrite(LED_R_PIN, HIGH);
  }
  if (!digitalRead(KEY_2_PIN)) {
//    digitalWrite(LED_G_PIN, LOW);
    Serial.println("KEY 2 Pressed");
  } else {
//    digitalWrite(LED_G_PIN, HIGH);
  }
  if (!digitalRead(KEY_3_PIN)) {
//    digitalWrite(LED_B_PIN, LOW);
    Serial.println("KEY 3 Pressed");
  } else {
//    digitalWrite(LED_B_PIN, HIGH);
  }
}
