uint8_t slave_receiver;

void setup(void) 
{
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
}

void loop(void) 
{
  slave_receiver = SPDR;
  SPDR = slave_receiver;
}