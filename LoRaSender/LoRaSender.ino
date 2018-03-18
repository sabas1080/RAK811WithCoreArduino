/*
 * Basic Example for modulo LoRa in RAK811
 * Library LoRa: https://github.com/sandeepmistry/arduino-LoRa
 * Arduino Core: https://github.com/sabas1080/Arduino_Core_STM32
 * Autor: Andrés Sabas
 * Date: 17 March 2018
 * for Electronic Cats @ https://electroniccats.com 
 */
#include <SPI.h>
#include <LoRa.h>

int counter = 0;

void setup() {
  SPI.setMISO(RADIO_MISO_PORT);
  SPI.setMOSI(RADIO_MOSI_PORT);
  SPI.setSCLK(RADIO_SCLK_PORT);
  SPI.setSSEL(RADIO_NSS_PORT);
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(5000);
}
