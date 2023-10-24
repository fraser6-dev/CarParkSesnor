#include <WiFi.h>
#include <aREST.h>
#include <DHT.h>

#define DHTPIN 13
#define DHTTYPE DHT11
#define TRIGGER_PIN 12
#define ECHO_PIN 14

DHT dht(DHTPIN, DHTTYPE);

aREST rest = aREST();

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

int ledRed = 2; 
int ledGreen = 4;
int distance = 0;
float humidity = 0.0;
float temperature = 0.0;

void setup() {
  Serial.begin(115200);

  dht.begin();
  
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected!");

  rest.set_id("1");
  rest.set_name("esp32_parking");

  rest.variable("distance", &distance);
  rest.variable("humidity", &humidity);
  rest.variable("temperature", &temperature);
}

void loop() {
  rest.handle(WiFiClient());

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  distance = (int)(pulseIn(ECHO_PIN, HIGH) * 0.0343 / 2);
  
  if(distance > 0 && distance < 30){
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
  } else {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
  }
  
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  delay(2000);
}
