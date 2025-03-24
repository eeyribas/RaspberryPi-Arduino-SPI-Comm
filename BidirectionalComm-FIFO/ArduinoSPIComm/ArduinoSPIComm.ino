#include "CircularBuffer.h"

CircularBuffer<char, 100> buffer_stroge;

char data[] = { 12, 34, 56, 78, 91, 23, 45 };
byte count = 0;
byte slave_received;
int slave_received_int = 0;

void setup(void) 
{
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);

  for (int i = 0; i < 7; i++)
    buffer_stroge.push(data[i]);
}

void loop(void) 
{
  slave_received = SPDR;
  slave_received_int = (int)slave_received;

  if (slave_received_int == 97) {
    if ((SPSR & (1 << SPIF)) != 0) {
      SPDR = data[count];
      count++;

      if (count > sizeof(data))
        count = 0;
    }

    for (int i = 0; i < 7; i++)
      buffer_stroge.push(data[i]);

    for (int j = 0; j < 7; j++)
      buffer_stroge.shift();
  } else {
    SPDR = 'H';
  }
}