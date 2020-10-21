#include <ESP8266WiFi.h>

String  i;
WiFiServer server(80);

void setup()
{
  i = "";

Serial.begin(9600);
pinMode(16, OUTPUT);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(0, OUTPUT);
  WiFi.disconnect();
  delay(1000);
  Serial.println("START");
   WiFi.begin("userid","password");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("....");

  }
  server.begin();
  Serial.println("connected");
  Serial.println((WiFi.localIP().toString()));

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    if (i == "up") {
      digitalWrite(16,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(0,LOW);

    }
    if (i == "down") {
      digitalWrite(16,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(0,HIGH);

    }
    if (i == "right") {
      digitalWrite(16,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      digitalWrite(0,HIGH);

    }
    if (i == "left") {
      digitalWrite(16,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(0,LOW);

    }
    if (i == "stop") {
      digitalWrite(16,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      digitalWrite(0,LOW);

    }

}
