//https://github.com/techiesms/ESP8266-Smart-Config/blob/master/smart_config/smart_config.ino
//http://techiesms.com/iot-projects/now-no-need-enter-ssid-name-password-inside-code-esp8266-smart-config/
//https://www.youtube.com/watch?time_continue=38&v=5D6lkFGPPSw

#include <Arduino.h>
#include "utils.h"

#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#else // for ESP32
#include <WiFiClient.h>
#include <WebServer.h>
#endif

ConfigStore configStore;

void setup() {
  PRINT_PORT.begin(115200);
  // PRINT_PORT.setDebugOutput(true);

  PRINT_PORT.println();
  PRINT_PORT.println();
  // PRINT_PORT.print("Firmware version: ");
  // PRINT_PORT.println(configDefault.version);

  for (uint8_t t = 5; t > 0; t--) {
    PRINT_PORT.printf("[Starting up] WAIT %d...\n", t);
    PRINT_PORT.flush();
    delay(1000);
  }

  if (initConfig(configStore)) {
    connectWiFi(configStore);
  } else {
    smartConfig(configStore);
  }

  if (WiFi.status() == WL_CONNECTED) {
    PRINT_PORT.print("Local IP: ");
    PRINT_PORT.println(WiFi.localIP());
  }
}

void loop() {
  // wait for WiFi connection
  monitorWiFi(configStore);
  //  if ((configStore.flagWiFiFail == 0) && (millis() % 10000 == 0)) { // Try to update the firmware every ten seconds
  //    if (checkFirmwareUpdate(configStore)) {
  //      firmwareUpdate(configStore);
  //    }
  //  }
}
