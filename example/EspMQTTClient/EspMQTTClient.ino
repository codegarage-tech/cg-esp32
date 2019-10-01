/*
  SimpleMQTTClient.ino
  The purpose of this exemple is to illustrate a simple handling of MQTT and Wifi connection.
  Once it connects successfully to a Wifi network and a MQTT broker, it subscribe to a topic and send a message to it.
  It will also send a message delayed 5 seconds later.
*/

#include "EspMQTTClient.h"

EspMQTTClient client(
  "Dicosta",
  "ramo011911",
  "157.245.88.4",  // MQTT Broker server ip
  "admin",   // Can be omitted if not needed
  "admin",   // Can be omitted if not needed
  "SmartHome",     // Client name that uniquely identify your device
  1883              // The MQTT port, default to 1883. this line can be omitted
);

void setup()
{
  Serial.begin(115200);

  // Optionnal functionnalities of EspMQTTClient : 
  client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  client.enableHTTPWebUpdater(); // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overrited with enableHTTPWebUpdater("user", "password").
  client.enableLastWillMessage("/420/69", "I am going offline");  // You can activate the retain flag by setting the third parameter to true
}

// This function is called once everything is connected (Wifi and MQTT)
// WARNING : YOU MUST IMPLEMENT IT IF YOU USE EspMQTTClient
void onConnectionEstablished()
{
  // Subscribe to "/420/69" and display received message to Serial
  client.subscribe("/420/69", [](const String & payload) {
    Serial.println(payload);
  });

  // Publish a message to "/420/69"
//  client.publish("/420/69", "This is a message"); // You can activate the retain flag by setting the third parameter to true

  // Execute delayed instructions
//  client.executeDelayed(5 * 1000, []() {
//    client.publish("/420/69", "This is a message sent 5 seconds later");
//  });
}

void loop()
{
  client.loop();
}
