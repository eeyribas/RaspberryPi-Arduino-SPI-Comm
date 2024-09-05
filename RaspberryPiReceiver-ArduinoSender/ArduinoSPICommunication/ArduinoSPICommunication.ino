unsigned char data[] = { 'E', 'S', 'N' };
byte count = 0;

void setup() 
{
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
}

void loop() 
{
  if ((SPSR & (1 << SPIF)) != 0) {
    SPDR = data[count];
    count++;

    if (count > sizeof(data))
      count = 0;
  }
}