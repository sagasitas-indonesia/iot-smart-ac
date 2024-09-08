#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "YourTemplateName"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Ganti dengan kredensial WiFi Anda
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

// Pin untuk relay
const int relayPin = D4;

void setup() {
  // Inisialisasi pin relay
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Pastikan relay mati saat mulai

  // Mulai serial monitor
  Serial.begin(115200);

  // Mulai Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}

// Fungsi untuk mengendalikan relay dari Blynk
BLYNK_WRITE(V1) {
  int relayState = param.asInt();
  digitalWrite(relayPin, relayState);
}
