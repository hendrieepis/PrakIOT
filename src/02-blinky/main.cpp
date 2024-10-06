#include <Arduino.h>
// Definisikan pin LED
#define LED_R 27

void setup() {
  // Atur kedua pin sebagai output
  pinMode(LED_R, OUTPUT);
}

void loop() {
  // Nyalakan LED pada pin GPIO2 dan matikan LED pada pin GPIO4
  digitalWrite(LED_R, HIGH);
  delay(1000); // Tunggu selama 1 detik

  // Matikan LED pada pin GPIO2 dan nyalakan LED pada pin GPIO4
  digitalWrite(LED_R, LOW);
  delay(1000); // Tunggu selama 1 detik
}
