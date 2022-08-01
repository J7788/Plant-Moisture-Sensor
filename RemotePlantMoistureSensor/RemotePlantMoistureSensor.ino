#include <ESP8266WiFi.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("\nRemote Plant Moisture sensor v0");

  WiFi.begin("MOTO7466", "zpzdf2evu9");

  Serial.print("Connecting");

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
