#include <QDebug>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <iostream>

using namespace std;

int SPIRxTx(unsigned char txDat);

int fd;
unsigned char value = 'a';

int main(int argc, char *argv[])
{
    fd = open("/dev/spidev0.0", O_RDWR);
    unsigned int speed = 4000000;
    ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);

    while (true) {
        int result = SPIRxTx(value);
        cout << result;
    }
}

int SPIRxTx(unsigned char tx_data)
{
    unsigned char rx_data;
    struct spi_ioc_transfer spi;
    memset(&spi, 0, sizeof(spi));

    spi.tx_buf = (unsigned long)&tx_data;
    usleep(1);
    spi.rx_buf = (unsigned long)&rx_data;
    spi.len = 1;
    ioctl(fd, SPI_IOC_MESSAGE(1), &spi);

    return rx_data;
}
