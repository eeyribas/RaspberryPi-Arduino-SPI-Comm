#include <SPI.h>
#include <avr/sleep.h>

boolean received;
volatile byte slave_receiver;
volatile byte slave_sender;

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
    slave_sender = slave_receiver;
    sleep_enable();
    delay(30);
    sleep_disable();
    SPDR = slave_sender;
  }
}

ISR(SPI_STC_vect)
{
  slave_receiver = SPDR;
  received = true;
}