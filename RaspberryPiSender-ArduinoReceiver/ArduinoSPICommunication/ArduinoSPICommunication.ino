uint8_t slave_received;

void setup(void) 
{
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
}

void loop(void) 
{
  slave_received = SPDR;
  SPDR = slave_received;
}