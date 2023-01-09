#include <BlynkGOv3.h>

#define MQTT_SERVER     "broker.hivemq.com" // "test.mosquitto.org"
#define MQTT_PORT       1883

GWiFiManager  wifi_manager;
GSwitch3D     sw3d;

void setup() {
  Serial.begin(115200); Serial.println();
  BlynkGO.begin();

  wifi_manager.align(ALIGN_TOP_RIGHT,-5,5);

  sw3d.size(80,120);          // กำหนดขนาด
  sw3d.gpio(5);               // กำหนดขา relay
  
  // เก็บสถานะ sw3d บน flashMem 
  // โดยเริ่มต้นทำการเรียกคืนสถานะปุ่มจาก flashMem
  if(BlynkGO.flashMem_exists("MY_SWITCH")){
    bool sw3d_state =  (bool) BlynkGO.flashMem_Int("MY_SWITCH"); 
    (sw3d_state)? sw3d.ON() : sw3d.OFF();
  }else{
    BlynkGO.flashMem("MY_SWITCH", 0);
    sw3d.OFF();
  }

  // หาก ผู้ใช้มีการกด เปลี่ยนแปลงสถานะ sw3d
  sw3d.onValueChanged([](GWidget* widget){
    BlynkGO.flashMem("MY_SWITCH"    , sw3d.state() );  // ให้ทำการ save สถานะ sw3d ลงบน flahsMem เกิดไฟดับและไฟมา ก็ยังสถานะเดิมได้

    if( sw3d.isON()){
      Serial.println("Switch3D : Turn ON from touch screen"); 
    }else{
      Serial.println("Switch3D : Turn OFF from touch screen"); 
    }
  });

  //------------------------------------
  MQTT.setServer(MQTT_SERVER, MQTT_PORT);
  MQTT.onMessage([](char* topic, char* data, MessageProperties properties, size_t len, size_t index, size_t total){
    static String  payload;
    if(index == 0) payload = "";
    char buf[len]; memcpy(buf, data, len); buf[len]=0; payload += buf;
    
    if( index + len >= total) {
      Serial.printf("[MQTT] message :  topic : %s -> payload : %s\n", topic, payload.c_str() );

      // รับคำสั่งเปิด/ปิด sw3d จาก MQTT มากำหนดสถานะให้ sw3d
      bool sw3d_state = payload.toInt();
      if( sw3d_state != sw3d.state() ){   // หาก สถานะที่ได้รับจาก mqtt ไม่ตรงกับสถานะปัจจุบันของ sw3d
        sw3d.state(sw3d_state);           // ให้กำหนด สถานะใหม่
        BlynkGO.flashMem("MY_SWITCH"    , sw3d.state() );
        if(sw3d_state){
          Serial.println("Switch3D : Turn ON from MQTT"); 
        }else{
          Serial.println("Switch3D : Turn OFF from MQTT"); 
        }
      }
    }
  });  
}

void loop() {
  BlynkGO.update();
}

WIFI_CONNECTED(){
  Serial.println("[WiFi] connected");
}

WIFI_DISCONNECTED(){
  Serial.println("[WiFi] disconnected");  
}

MQTT_CONNECTED(){
  Serial.println("[MQTT] connected");
  Serial.println("[MQTT] subscribing...");
  MQTT.subscribe("/MY_SWITCH/state");                 // กำหนด subscribe topic
}

MQTT_DISCONNECTED(){
  Serial.println("[MQTT] disconnected");  
}

MQTT_SUBSCRIBED(){
  Serial.println("[MQTT] subscribed");  
}

