#include "DHT.h"

#define DHTPIN 12  // Pin yang digunakan untuk DHT22
#define DHTTYPE DHT22  // Tipe sensor DHT

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();  // Inisialisasi sensor DHT22
}

void loop() {
  // Membaca kelembaban dan suhu
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Mengecek jika pembacaan valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Mencetak hasil ke Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
  
  delay(2000);  // Delay 2 detik antara pembacaan
}
