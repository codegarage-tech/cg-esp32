#ifndef UTILS_H
#define UTILS_H

#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#else // for ESP32
#include <WiFiClient.h>
#include <WebServer.h>
#endif

#include <EEPROM.h>

#define DEBUG

#define PRINT_PORT              Serial
#define PRINT_LOG(msg)          {PRINT_PORT.print(millis()), PRINT_PORT.print(" "), PRINT_PORT.println(msg);}
#define PRINTF_LOG(msg, ...)    {PRINT_PORT.print(millis()), PRINT_PORT.print(" "), PRINT_PORT.printf(msg, ##__VA_ARGS__);}

#if defined(DEBUG)
#define DEBUG_PRINT(msg)  PRINT_LOG(msg)
#define DEBUG_PRINTF(msg, ...)  PRINTF_LOG(msg, ##__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#define DEBUG_PRINTF(...)
#endif

// Indicator pin definition
#define LED_PIN            2    //BUILTIN_LED
#define BOARD_PWM_MAX      1024

#define EEPROM_CONFIG_START 0

struct ConfigStore {
  uint32_t  magic;
//  char      version[12];
  uint8_t   flagConfig: 1; // Enter configuration mode
  uint8_t   flagApFail: 1; // AP failure
  uint8_t   flagWiFiFail: 1; // WiFi disconnect
  uint8_t   flagSelfTest: 1;

  char      wifiSSID[32];
  char      wifiPass[32];

//  char      cloudHost[32];
//  uint16_t  cloudPort;
//  char      cloudUpdateUrl[64];
//  char      cloudFwCheckUrl[64];
} __attribute__((packed));

//ConfigStore configStore;
const ConfigStore configDefault = {
  0x26512E6D,  //0x265CAE6D
//  "0.0.1",
  0, 0, 0, 0,
  "Dicosta",
  "ramo011911"
//  ,"iot-cuddle.000webhostapp.com"
//  ,80
//  ,"/iot/fota"
//  ,"/update.txt"
};

boolean initConfig(ConfigStore &configStore);

// Write configuration to flash
void writeConfig(ConfigStore &configStore);

// Read configuration from flash
boolean readConfig(ConfigStore &configStore);

void connectWiFi(ConfigStore &configStore);

void monitorWiFi(ConfigStore &configStore);

// Get password through Smart Config
void smartConfig(ConfigStore &configStore);
#endif
