#include <M5Stack.h>
#include"espnow.h"
Espnow espnow;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
{
  
}

void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len)
{
    if(espnow.OnRemotRecv(mac_addr,data,data_len)){
      return;
    }   
}


void setup() {
  // put your setup code here, to run once:
  
  m5.begin();
  espnow.RemoteInit();
  esp_now_register_recv_cb(OnDataRecv);
  esp_now_register_send_cb(OnDataSent);
 
}
void loop() {
    espnow.RemoteConnectUpdate();
     
}
