#define BLYNK_TEMPLATE_ID "TMPL3hSRHZEsF"
#define BLYNK_TEMPLATE_NAME "Smart Home Automation"
#define BLYNK_AUTH_TOKEN "6sEqN6rS3RZA8z2wIArelRl-xlpmYpN8"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your Blynk authentication token
char auth[] = "6sEqN6rS3RZA8z2wIArelRl-xlpmYpN8";

// Your WiFi credentials
char ssid[] = "Jaga❣️";
char pass[] = "jaga@2004";

// Relay pin (D1 = GPIO5, D2 = GPIO4, etc.)
const int relayPin = 5; // Change this to the pin you are using for the relay

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);
  
  // Set relay pin as output
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Ensure relay is off at startup
}

void loop() {
  Blynk.run();
}

// Function to control the relay
BLYNK_WRITE(V0) { // Virtual pin V0 for the button
  int pinValue = param.asInt(); // Get value from the button
  if (pinValue == 1) {
    digitalWrite(relayPin, HIGH); // Turn relay on
  } else {
    digitalWrite(relayPin, LOW); // Turn relay off
  }
}
