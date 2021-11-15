#include "seeed_rp2040_wifi.h"
WiFiMqtt mqtt_test;
WiFiClient socket_test;
IPAddress server(192,168,9,133); 
void setup()
{
    delay(2000);
    Serial.println("******start*******");
    while(false == WiFi.begin("wifi_ssid", "wifi_password"))
    {
         Serial.println("connect wifi fail ,try again");
         delay(5000);
    }
    Serial.println("success connect wifi");
    //set
    mqtt_test.mqtt_setcfg("Wio_RP2040",NULL,NULL,0,0,NULL);//client_id,username,password,cert_key_ID,CA_ID,path
    //connect
    mqtt_test.mqtt_connect("mqtt.p2hp.com",1883,0);//server,port,reconnect

    

    socket_test.connect(server,8080);
    
}
 
 
void loop()
{
  //pubilsh
  mqtt_test.mqtt_publish("Temperature","It's so hot,drink more water!",0,0);//topic,data,qos,retai

  
socket_test.write("hhhhhhh",7);
if(socket_test.available())
  Serial.println(socket_test.read());
delay(1000);

}
