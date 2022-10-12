#include <Arduino.h>
#include "sonic_wrappers/sonicGPIO.h"
#include "sonic_wrappers/sonicAD.h"
#include "sonic_wrappers/sonicPWM.h"
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "strats.h"

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

command_t command = STOP_CMD;
std::string recv = "Received: ";

int speed_arch = 0;
direction_arch_t direction_arch = RIGHT_ARCH;
int time_arch = 200;
bool first_arch = true;

class MyCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic)
  {
    std::string value = pCharacteristic->getValue();

    if (value == "LED")
    {
      command = LED_CMD;
      pCharacteristic->setValue(recv + value);
    }

    if (value == "P")
    {
      command = STOP_CMD;
      pCharacteristic->setValue(recv + value);
    }

    if (value == "BUSCA")
    {
      command = FOLLOWER_STRAT_CMD;
      pCharacteristic->setValue(recv + value);
    }

    if (value.substr(0, 4) == "ARCH")
    {
      
      Serial.println(value.substr(0, 4).c_str());
      speed_arch = std::stoi(value.substr(4,2));
      time_arch = std::stoi(value.substr(6,3));

      if(value.substr(10,1) == "0")
      {
        direction_arch == RIGHT_ARCH;
      }

      if(value.substr(10,1) == "1")
      {
        direction_arch == LEFT_ARCH;
      }

      command = ARCH_CMD;
      pCharacteristic->setValue(recv + value);
    }

    if (value == "SENSOR")
    {
      command = SENSOR_TEST_CMD;
      pCharacteristic->setValue(recv + value);
    }

    if (value == "LINE")
    {
      command = LINE_TEST_CMD;
      pCharacteristic->setValue(recv + value);
    }

    if (value == "FORWARD")
    {
      command = FORWARD_TEST_CMD;
      pCharacteristic->setValue(recv + value);
    }
  }

  void onRead(BLECharacteristic *pCharacteristic)
  {
    if(command = SENSOR_TEST_CMD)
    {
      int leitura_lat_esq = gpio_get_level(SENSOR_LAT_ESQ);
      int leitura_front_esq = gpio_get_level(SENSOR_FRONT_ESQ);
      int leitura_front_dir = gpio_get_level(SENSOR_FRONT_DIR);
      int leitura_lat_dir = gpio_get_level(SENSOR_LAT_DIR);

      std::string sensores = "LE:";
      sensores.append(std::to_string(leitura_lat_esq));
      sensores.append(" FE:");
      sensores.append(std::to_string(leitura_front_esq));
      sensores.append(" FD:");
      sensores.append(std::to_string(leitura_front_dir));
      sensores.append(" LD:");
      sensores.append(std::to_string(leitura_lat_dir));

      pCharacteristic->setValue(sensores);
      Serial.println(sensores.c_str());
    }
  }
};

void setup()
{

  Serial.begin(9600);
  pinMode(2, OUTPUT);
  gpioConfig();
  adConfig();
  pwmConfig();

  pinMode(SENSOR_FRONT_DIR, INPUT_PULLDOWN);

  BLEDevice::init("Sonic");
  BLEServer *pServer = BLEDevice::createServer();

  BLEService *pService = pServer->createService(SERVICE_UUID);

  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_WRITE);

  pCharacteristic->setCallbacks(new MyCallbacks());

  pCharacteristic->setValue("Hello World");
  pService->start();

  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
}

void loop()
{
  gpio_set_level(GPIO_NUM_2, LOW);

  Motor right(IN1, IN2, PWMA);
  Motor left(IN3, IN4, PWMB);

  Serial.println("standby");
  delay(100);

  if (command == LED_CMD)
  {
    while (1)
    {
      if (command == STOP_CMD)
      {
        break;
      }
    }
  }

  if (command == FOLLOWER_STRAT_CMD)
  {
    while (1)
    {
      follower_strat(right, left, 100);
      gpio_set_level(GPIO_NUM_2, HIGH);
      if (command == STOP_CMD)
      {
        break;
      }
    }
  }

  if (command == ARCH_CMD)
  {
    while (1)
    {

      while(first_arch)
      {
        Serial.print(speed_arch);
        Serial.print(" ");
        Serial.print(time_arch);
        Serial.print(" ");
        Serial.println(direction_arch);
        first_arch = arch(right, left, speed_arch, time_arch, direction_arch);
      }

      follower_strat(right, left, 100);
      gpio_set_level(GPIO_NUM_2, HIGH);
      if (command == STOP_CMD)
      {
        break;
      }
    }
  }

  if(command == FORWARD_TEST_CMD)
  {
    while(1)
    {
      Serial.println("Forward");
      right.move(30, FW);
      left.move(30, FW);

      if (command == STOP_CMD)
      {
        break;
      }
    }
  }
  
  if(command == LINE_TEST_CMD)
  {
    while(1)
    {
      Serial.println("line");
      if(analogRead(SENSOR_DE_LINHA_A) < 1000)
      {
        right.move(100,BW);
        left.move(100,BW);
      }

      if(analogRead(SENSOR_DE_LINHA_B) < 1000)
      {
        right.move(100,BW);
        left.move(100,BW);
      }

      if (command == STOP_CMD)
      {
        break;
      }
    }
  }

  if (command == STOP_CMD)
  {
    pwmASetDuty(0);
    pwmBSetDuty(0);
  }
}