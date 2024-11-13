// Definitions
#define BLYNK_TEMPLATE_ID "TMPL3gP1gLjt0"
#define BLYNK_TEMPLATE_NAME "SIS"
#define BLYNK_AUTH_TOKEN "L7gnFXfCgaEeS_KRZiZe7ZUvjR380CQ8"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
#define LED_PIN V1 
#define LED_GPIO_PIN 3
// Hardware Specifics
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Jaga❣️"; // "WIFI NAME"
char pass[] = "jaga@2004"; // "WIFI PASSWORD"
char auth[] = "L7gnFXfCgaEeS_KRZiZe7ZUvjR380CQ8";


int moisture() {
  int value = analogRead(A0);
  value = map(value, 0, 1023, 0, 100);
  Blynk.virtualWrite(V0, value);
  Serial.println(value);
  return value;
}

BLYNK_WRITE(LED_PIN) {
  int pinValue = param.asInt();
  digitalWrite(LED_GPIO_PIN, pinValue); // Read the value sent from the app (0 or 1)
}

void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT); // Ensure this matches your hardware setup
  digitalWrite(4, HIGH);
  pinMode(LED_GPIO_PIN, OUTPUT); // Initialize LED pin
  digitalWrite(LED_GPIO_PIN, LOW); // Start with LED off
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  delay(1000);
  int mvalue = moisture();
  if (mvalue > 60) {
    digitalWrite(4, LOW);
    Blynk.logEvent("moderate_level");
    Blynk.virtualWrite(V1,0);
  } else {
    digitalWrite(4, HIGH);
    Blynk.logEvent("low_water_level");
    Blynk.virtualWrite(V1,1);
  }
}
