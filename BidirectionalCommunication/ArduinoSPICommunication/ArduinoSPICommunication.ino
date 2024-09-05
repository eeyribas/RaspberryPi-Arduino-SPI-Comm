#include <SPI.h>
#include <avr/sleep.h>

boolean received;
volatile byte slave_received;
volatile byte slave_send;

void setup()
{
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  received = false;

  SPI.attachInterrupt();
}

void loop() 
{
  if (received) {
    slave_send = slave_received;
    sleep_enable();
    delay(30);
    sleep_disable();
    SPDR = slave_send;
  }
}

ISR(SPI_STC_vect) 
{
  slave_received = SPDR;
  received = true;
}