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
  }
};

void setup()
{

  Serial.begin(9600);
  pinMode(2, OUTPUT);
  gpioConfig();
  adConfig();
  pwmConfig();

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

  Serial.println("oi");
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

  if (command == STOP_CMD)
  {
    pwmASetDuty(0);
    pwmBSetDuty(0);
  }
}