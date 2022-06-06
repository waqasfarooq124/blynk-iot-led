#define BLYNK_TEMPLATE_ID "TMPL5ds8tLjS" // replace this one also with yours
#define BLYNK_DEVICE_NAME "Relay" // name this deive as you like
#define BLYNK_AUTH_TOKEN "V_q3KVx9xaCG5jnuRQ2irMytY4i5KTMl" // replace with your auth token

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";
char pass[] = "";

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
if(value == 1)
{
  Serial.println("ON");
  digitalWrite(D4,HIGH); 
  }
if(value == 0)
{
  Serial.println("OFF");
  digitalWrite(D4,LOW); 
  }
}
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D4,OUTPUT);
}
void loop()
{
  Blynk.run();
}
