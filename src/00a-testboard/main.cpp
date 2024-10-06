#include <Arduino.h>
#include "DHT.h"

//define DHT
#define DHTPIN 12  // Pin yang digunakan untuk DHT22
#define DHTTYPE DHT22  // Tipe sensor DHT
DHT dht(DHTPIN, DHTTYPE);

// Digital Output GPIO Pins
#define RELAY1_PIN 16
#define RELAY2_PIN 17
#define LED1_PIN 14
#define LED_R 27
#define LED_G 26
#define LED_B 25
#define BUZZER_PIN 2

// Digital Input GPIO Pins (Push Buttons)
#define BUTTON1_PIN 35  // No pull-up/down available, external pull-up required
#define BUTTON2_PIN 13   // Internal pull-up enabled
#define BUTTON3_PIN 15  // Internal pull-up enabled
#define BUTTON4_PIN 0  // Internal pull-up enabled
#define PIR_PIN 4

// Analog Input GPIO Pins
#define PHOTO_RESISTOR_PIN 34 // No pull-up available, input only (ADC1)
#define POTENSIO1_PIN 33      // Analog input (ADC1)
#define POTENSIO2_PIN 32      // Analog input (ADC1)

// I2C Interface (for OLED display)
#define OLED_SCL 22
#define OLED_SDA 21

// Array of LED and Relay pins
const int ledPins[] = {LED1_PIN, LED_R, LED_G, LED_B};
int num_leds = sizeof(ledPins) / sizeof(ledPins[0]);
const int relayPins[] = {RELAY1_PIN, RELAY2_PIN};

void setup() {
  Serial.begin(115200);
  dht.begin();  // Inisialisasi sensor DHT22
    // Initialize I2C communication
  
  // Initialize LED and Relay pins as OUTPUT
  for (int i = 0; i < num_leds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  for (int i = 0; i < 2; i++) {
    pinMode(relayPins[i], OUTPUT);
  }

  // Initialize GPIO for Digital Outputs
  pinMode(BUZZER_PIN, OUTPUT);

  // Initialize GPIO for Digital Inputs (Push Buttons)
  pinMode(BUTTON1_PIN, INPUT);           // External pull-up needed
  pinMode(BUTTON2_PIN, INPUT_PULLUP);    // Internal pull-up enabled
  pinMode(BUTTON3_PIN, INPUT_PULLUP);    // Internal pull-up enabled
  pinMode(BUTTON4_PIN, INPUT_PULLUP);    // Internal pull-up enabled
  pinMode(PIR_PIN, INPUT);    

  // Initialize GPIO for Analog Inputs
  pinMode(PHOTO_RESISTOR_PIN, INPUT);
  pinMode(POTENSIO1_PIN, INPUT);
  pinMode(POTENSIO2_PIN, INPUT);

  // LED and Relay sequential activation 3 times with 300ms delay
  for (int i = 0; i < 3; i++) {
    // Iterate through LEDs and Relays
    for (int j = 0; j < num_leds; j++) {
      // Turn on LED and corresponding relay if available
      digitalWrite(ledPins[j], HIGH);
      if (j < 2) {
        digitalWrite(relayPins[j], HIGH);
      }
      delay(300);

      // Turn off LED and corresponding relay
      digitalWrite(ledPins[j], LOW);
      if (j < 2) {
        digitalWrite(relayPins[j], LOW);
      }
      delay(300);
    }
  }

  Serial.println("Setup complete. LED and Relay sequence done.");
}

void loop() {
  // Read Digital Inputs (Push Buttons)
  if(!digitalRead(BUTTON1_PIN)) {
    Serial.print("Button 1: ");
  }

  if(!digitalRead(BUTTON2_PIN)) {
    Serial.print("Button 2: ");
  }

  if(!digitalRead(BUTTON3_PIN)) {
    Serial.print("Button 3: ");
  }

  if(!digitalRead(BUTTON4_PIN)) {
    Serial.print("Button 4: ");
    digitalWrite(BUZZER_PIN,HIGH);
    digitalWrite(RELAY1_PIN,HIGH);
    digitalWrite(RELAY2_PIN,HIGH);
    digitalWrite(LED1_PIN,HIGH);
    digitalWrite(LED_R,HIGH);
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_B,HIGH);
  } else {
    digitalWrite(BUZZER_PIN,LOW);
    digitalWrite(RELAY1_PIN,LOW);
    digitalWrite(RELAY2_PIN,LOW);
    digitalWrite(LED1_PIN,LOW);
    digitalWrite(LED_R,LOW);
    digitalWrite(LED_G,LOW);
    digitalWrite(LED_B,LOW);
  }

    if(digitalRead(PIR_PIN)) {
    Serial.print("PIR Activated: ");
  }

  // Read Analog Inputs
  int photoResistorValue = analogRead(PHOTO_RESISTOR_PIN);
  int potValue1 = analogRead(POTENSIO1_PIN);
  int potValue2 = analogRead(POTENSIO2_PIN);

  Serial.printf("photo Resistor: %d Potensio1: %d, Potensio2: %d \n\r",photoResistorValue,potValue1, potValue2);

   // Membaca kelembaban dan suhu
   float humidity = dht.readHumidity();
   float temperature = dht.readTemperature();

  // Mengecek jika pembacaan valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // // Mencetak hasil ke Serial Monitor
  // Serial.print("Humidity: ");
  // Serial.print(humidity);
  // Serial.print("%  Temperature: ");
  // Serial.print(temperature);
  // Serial.println("°C");

  Serial.printf("Humidity: %.1f %%  Temperature: %.1f °C \n\r",humidity,temperature);

  delay(1000);  // Delay to slow down serial output
}
