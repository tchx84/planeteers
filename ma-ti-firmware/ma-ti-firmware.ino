#include "../config.h"
#include "lora_receiver.h"
#include "wifi.h"
#include "utils.h"

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.print("Ma-ti Air Quality Sensor starting up, v");
  Serial.println(VERSION);
  initLora();
  // initWifi();
}

void loop() {
  String payload = receiveLoRa();
  if(payload != "") {
    String g_pm1p0_sp_value = getValue(payload, ':', 0);
    String g_pm2p5_sp_value = getValue(payload, ':', 1);
    String g_pm10p0_sp_value = getValue(payload, ':', 2);
    Serial.print("payload received: ");
    Serial.print("pm1p0: " + String(g_pm1p0_sp_value) + ", ");
    Serial.print("pm2p5: " + String(g_pm2p5_sp_value) + ", ");
    Serial.println("pm10p0: " + String(g_pm10p0_sp_value));
  }
  // reportToHttp(g_pm1p0_sp_value, g_pm2p5_sp_value, g_pm10p0_sp_value);
}