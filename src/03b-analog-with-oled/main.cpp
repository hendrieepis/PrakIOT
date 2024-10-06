#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Pin definitions for ADC (Analog inputs)
#define PHOTO_RESISTOR_PIN 34 // No pull-up, input only (ADC1)
#define POTENSIO1_PIN 33    // Analog input (ADC1)
#define POTENSIO2_PIN 32      // Analog input (ADC1)

// I2C Interface for OLED
#define OLED_SCL 22
#define OLED_SDA 21
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  // No reset pin

// Create OLED display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Start serial communication
  Serial.begin(115200);
  
  // Initialize I2C for OLED
  Wire.begin(OLED_SDA, OLED_SCL);

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3C for most 0.96" OLED displays
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Clear the buffer
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Initial display message
  display.setCursor(0, 0);
  display.println("Initializing...");
  display.display();
  delay(2000);  // Wait for 2 seconds
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

  // Display values on the OLED screen
  display.clearDisplay();  // Clear previous display data

  // Display Photoresistor value
  display.setCursor(0, 0);
  display.print("PhotoResistor: ");
  display.println(photoResistorValue);

  // Display Potentiometer 1 value
  display.setCursor(0, 16);
  display.print("Potentiometer 1: ");
  display.println(pot1Value);

  // Display Potentiometer 2 value
  display.setCursor(0, 32);
  display.print("Potentiometer 2: ");
  display.println(pot2Value);

  // Refresh the display
  display.display();

  // Delay before the next loop iteration
  delay(1000);  // Update every 1 second
}
