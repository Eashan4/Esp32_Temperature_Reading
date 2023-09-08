#define BLYNK_TEMPLATE_ID "TMPL3LpxvpkD9"
#define BLYNK_TEMPLATE_NAME "ESP32 Iot Sensor"
#define BLYNK_AUTH_TOKEN "d6Q-HfTEfjakGZSESL63lNxCfQFxA03Y"

#include <DHT.h>
#include <BlynkSimpleEsp32.h>

#define DHTPIN 2 // Data pin is connected to D2 on ESP
#define DHTTYPE DHT11 // Name the sensor as an object

char auth[] = "d6Q-HfTEfjakGZSESL63lNxCfQFxA03Y";
char ssid[] = "Eashan";
char pass[] = "123456788";

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test Successful!");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk Connected Successfully");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Something is not working as intended.");
    return; 
  }
  Serial.println("Humidity: ");
  Serial.print(h);
  Serial.print("%");
  Serial.println("Temperature");
  Serial.print(t);
  Serial.print("degrees celsius.");
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
	delay(1000);
}