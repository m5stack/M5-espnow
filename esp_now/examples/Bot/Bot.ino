#include <M5Stack.h>
#include "espnow.h"

Espnow espnow;
// callback when data is sent from Master to Slave
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
{

}

void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len)
{
    if(espnow.OnBotRecv(mac_addr,data,data_len))
    return;
}
void setup() {
  M5.begin();  
  espnow.BotInit();
  esp_now_register_recv_cb(OnDataRecv);
  esp_now_register_send_cb(OnDataSent);
}

void loop() {
    espnow.BotConnectUpdate();
 }
