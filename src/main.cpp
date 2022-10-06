#include <Arduino.h>
#include "sonic_wrappers/sonicGPIO.h"
#include "sonic_wrappers/sonicAD.h"
#include "sonic_wrappers/sonicPWM.h"
#include "utils.h"
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "strats.h"

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

std::string comando = "";
std::string recv = "Received: ";

class MyCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic)
  {
    std::string value = pCharacteristic->getValue();

    if (value == "LED")
    {
      comando = "LED";
      pCharacteristic->setValue(recv + value);
    }

    if (value == "P")
    {
      comando = "Parar";
      pCharacteristic->setValue(recv + value);
    }

    if (value == "BUSCA")
    {
      comando = "Busca";
      pCharacteristic->setValue(recv + value);
    }
  }
};

void setup()
{

  Serial.begin(115200);
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

  if (Serial.available())
  {
    Serial.println("oi");
  }

  if (comando == "LED")
  {
    while (1)
    {

      Serial.print(comando.c_str()[1]);
      if (comando == "Parar")
      {
        break;
      }
    }
  }

  if (comando == "Busca")
  {
    while (1)
    {
      follower_strat(right, left, 100);
      gpio_set_level(GPIO_NUM_2, HIGH);
      if (comando == "Parar")
      {
        break;
      }
    }
  }

  if (comando == "Parar")
  {
    pwmASetDuty(0);
    pwmBSetDuty(0);
  }
}