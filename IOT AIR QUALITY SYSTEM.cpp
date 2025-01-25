#include "thingProperties.h"
#define MQ135_PIN A0
void setup() {
  Serial.begin(115200);
  delay(100);
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}
void loop() {

  ArduinoCloud.update();
  int sensorValue = analogRead(MQ135_PIN);
  float airQuality = map(sensorValue, 0, 1023, 0, 500); 
  Serial.print("Air Quality Index: ");
  Serial.println(airQuality);
  airQualityIndex = airQuality;
  delay(2000);
}
