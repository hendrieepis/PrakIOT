#include<Arduino.h>
#include <Wire.h>

// Pin definitions for ADC (Analog inputs)
#define PHOTO_RESISTOR_PIN 34 // No pull-up, input only (ADC1)
#define POTENSIO1_PIN 33      // Analog input (ADC1)
#define POTENSIO2_PIN 32      // Analog input (ADC1)


void setup() {
  // Start serial communication
  Serial.begin(115200);
  
}

void loop() {
  // Read analog values from sensors
  int photoResistorValue = analogRead(PHOTO_RESISTOR_PIN);
  int pot1Value = analogRead(POTENSIO1_PIN);
  int pot2Value = analogRead(POTENSIO2_PIN);

  // Print values to the serial monitor
  Serial.print("Photoresistor Value: ");
  Serial.println(photoResistorValue);
  Serial.print("Potentiometer 1 Value: ");
  Serial.println(pot1Value);
  Serial.print("Potentiometer 2 Value: ");
  Serial.println(pot2Value);
  Serial.println("-----------------------");

  // Delay before the next loop iteration
  delay(1000);  // Update every 1 second
}
