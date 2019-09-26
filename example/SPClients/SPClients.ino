#include <ETH.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

#include <PubSubClient.h>

#include <mqttclient.h>

#include <Base64.h>
#include <global.h>
#include <MD5.h>
#include <sha1.h>
#include <WebSocketClient.h>
#include <WebSocketServer.h>

#include <ArduinoJson.h>

#include <HTTP_Method.h>
#include <WebServer.h>

#ifdef ESP8266
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif

#define SSID  "Dicosta"  //  insert your wlan ssid
#define PASS  "ramo011911"  //  .. and password
//#include <init.h>   //  and remove this line

#include "myapp.h"

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASS);
  Serial.print("\nConnecting");
  while (WiFi.status() != WL_CONNECTED) delay(500),Serial.print("."); Serial.println("ok!");
  Serial.print("Connected as ");
  Serial.println(WiFi.localIP());
  myApp.begin();
}

void loop() {
  myApp.loop();
}
