#include <Arduino.h>
#include <Arduino.h>

#define LED1_PIN 12
#define LED2_PIN 14
#define LED_R 27
#define LED_G 26
#define LED_B 25

#define RELAY1_PIN 16
#define RELAY2_PIN 17

// Array of LEDs to simplify code
uint16_t leds[] = {LED1_PIN, LED2_PIN, LED_R, LED_G, LED_B};
int num_leds = sizeof(leds) / sizeof(leds[0]);

int rlys[]={RELAY1_PIN, RELAY2_PIN};
int num_rlys = sizeof(rlys) / sizeof(num_rlys);

void setup() {
    // Initialize all LED pins as output
    for (int i = 0; i < num_leds; i++) {
        pinMode(leds[i], OUTPUT);
        digitalWrite(leds[i], LOW); // Ensure all LEDs are off initially
    }

    for (int i=0;i< num_rlys;i++) {
      pinMode(rlys[i],OUTPUT);
      digitalWrite(rlys[i],LOW); // ensure ALL rlys are off
    }
}

void loop() {
    // Iterate over each LED and turn them on one by one
    for (int i = 0; i < num_leds; i++) {
        digitalWrite(leds[i], HIGH);  // Turn on the LED
        delay(200);                   // Wait for 200 milliseconds
        digitalWrite(leds[i], LOW);   // Turn off the LED
        delay(200);
    }

    for (int i=0; i< num_rlys;i++) {
      digitalWrite(rlys[i],HIGH);
      delay(200);
      digitalWrite(rlys[i],LOW);
      delay(200);
    }
}
