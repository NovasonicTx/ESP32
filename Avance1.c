#define REMOTEXY_MODE__ESP32CORE_BLE
#include <BLEDevice.h>
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"
#include <RemoteXY.h>
#pragma pack(push, 1)  

uint8_t RemoteXY_CONF[] =   // 106 bytes
  { 255,3,0,1,0,99,0,19,0,0,0,0,31,1,106,200,1,1,5,0,
  10,67,47,23,23,48,4,26,31,79,78,0,31,79,70,70,0,10,18,47,
  22,22,48,4,26,31,79,80,69,78,0,31,67,76,79,83,69,0,70,47,
  124,18,18,16,26,37,0,2,32,146,51,19,0,2,26,31,31,79,78,0,
  79,70,70,0,129,4,31,96,12,64,36,67,79,67,72,69,82,65,32,32,
  32,76,65,77,80,0 };

struct 
{
  uint8_t pushSwitch_02; // LAMPARA
  uint8_t pushSwitch_03; // COCHERA
  uint8_t switch_01;     // ON OFF ALARMA
  uint8_t led_03;        // ALARMA ACTIVADA
  uint8_t connect_flag;  
} 
RemoteXY;   
#pragma pack(pop)

#define LED_PIN 2  

void setup() 
{
  RemoteXY_Init(); 
  pinMode(LED_PIN, OUTPUT); 
}

void loop() 
{ 
  RemoteXY_Handler();

  if (RemoteXY.pushSwitch_02 == 1) 
  {
    digitalWrite(LED_PIN, HIGH);
  } 
    else 
    {
      digitalWrite(LED_PIN, LOW);
    }
}
