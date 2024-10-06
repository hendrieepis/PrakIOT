#include <WiFi.h>
#include <ArduinoMqttClient.h>
//testing gunakan mosquitto-client dengan sintaks sebagai berikut:
//mosquitto_sub -h broker.mqtt-dashboard.com -t elkapens/labwsn/suhu
//mosquitto_sub -h broker.mqtt-dashboard.com -t elkapens/labwsn/kelembapan
//testing pub
// mosquitto_pub -h broker.mqtt-dashboard.com -t elkapens/labwsn/kelembapan -m "85"
// mosquitto_pub -h broker.mqtt-dashboard.com -t elkapens/labwsn/suhu -m "31"



// Pengaturan WiFi
const char* ssid = "mywifi"; //cha
const char* password = "spr-blokh-3";

// Pengaturan MQTT Broker
const char* broker = "broker.mqtt-dashboard.com";
int port = 1883;
const char* temperatureTopic = "elkapens/labwsn/suhu";
const char* humidityTopic = "elkapens/labwsn/kelembapan";

// Inisialisasi WiFi dan MQTT Client
WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

// Deklarasi fungsi
void connectToWiFi();
void connectToMqttBroker();
void publishTemperature(float temperature);
void publishHumidity(float humidity);

void setup() {
  Serial.begin(115200);

  // Koneksi ke WiFi
  connectToWiFi();

  // Koneksi ke MQTT Broker
  connectToMqttBroker();
}

void loop() {
  if (!mqttClient.connected()) {
    connectToMqttBroker();
  }

  // Publikasi data suhu dan kelembaban dummies
  float dummyTemperature = 25.0 + random(0, 100) / 10.0; // Suhu dummies antara 25.0 hingga 34.9
  float dummyHumidity = 50.0 + random(0, 100) / 10.0;    // Kelembaban dummies antara 50.0 hingga 59.9

  publishTemperature(dummyTemperature);
  publishHumidity(dummyHumidity);

  // Delay sebelum mengirim data berikutnya
  delay(5000); // Mengirim data setiap 5 detik
}

void connectToWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println(" connected.");
}

void connectToMqttBroker() {
  Serial.print("Connecting to MQTT broker");
  while (!mqttClient.connect(broker, port)) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println(" connected.");
}

void publishTemperature(float temperature) {
  if (mqttClient.beginMessage(temperatureTopic)) {
    mqttClient.print(temperature);
    mqttClient.endMessage();
    Serial.print("Published temperature: ");
    Serial.println(temperature);
  } else {
    Serial.println("Failed to publish temperature");
  }
}

void publishHumidity(float humidity) {
  if (mqttClient.beginMessage(humidityTopic)) {
    mqttClient.print(humidity);
    mqttClient.endMessage();
    Serial.print("Published humidity: ");
    Serial.println(humidity);
  } else {
    Serial.println("Failed to publish humidity");
  }
}

