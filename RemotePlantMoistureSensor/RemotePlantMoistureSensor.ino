#include <ESP8266WiFi.h>

char network[] = "MOTO7466";
char pass[] = "zpzdf2evu9";
byte ip[4] = {192, 168, 0, 12};
char buffer[256];
WiFiClient client;

void setup() {
  //Setting up the wifi connection
  Serial.begin(9600);
  Serial.println("\nRemote Plant Moisture sensor v0");

  WiFi.begin(network, pass);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Attemping Connection to main computer now...");
  if (client.connect(ip, 1492)) {
    Serial.println("Connected!");
    client.println("This is a test coming from an esp8266. Your moms a hoe");
    Serial.println("Message sent. Waiting on response...");
    byte next_byte;
    while(next_byte = client.read()){
      Serial.print(next_byte);
    }
    Serial.println();
    buffer[256] = '\0';
    Serial.println(buffer);
    client.stop();
    Serial.print("Connection closed");
  }
  else {
    Serial.println("Connection failed");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
