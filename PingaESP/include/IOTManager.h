#ifndef __IOTMANAGER_H__
#define __IOTMANAGER_H__

#include <sstream>
#include <Arduino.h>
#include <Client.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "WiFiManager.h"

#include <MQTT.h>

#include "WiFiConfig.h"
#include "IOTConfig.h"
#include "NetworkManager.h"

#include <CloudIoTCore.h>
#include <CloudIoTCoreMqtt.h>

extern String getJwt();
extern void messageReceived(String &topic, String &payload);

class IOTManager {
  public:
    static CloudIoTCoreDevice *device;
    static CloudIoTCoreMqtt *mqtt;
    static WiFiClientSecure *netClient;
    static MQTTClient *mqttClient;
    static unsigned long iss;
    static String jwt;

    static WiFiClientSecure client;
    static void setupClient();

    static void setup(void);
    static void connect(void);

    static String getDefaultSensor();
    static void publishNetworkData();

    static bool ready();
    static void getReady();
};


#endif //__IOTMANAGER_H__