#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

int SPITxRx();

int fd;

int main()
{
    fd = open("/dev/spidev0.0", O_RDWR);
    unsigned int speed = 1000000;
    ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);

    while (true) {
        unsigned char result = SPITxRx();
        std::cout << result;
        usleep(10);
    }

    return 0;
}

int SPITxRx()
{
    unsigned char rx_data;
    struct spi_ioc_transfer spi;
    memset(&spi, 0, sizeof(spi));

    spi.rx_buf = (unsigned long)&rx_data;
    spi.len = 1;
    ioctl(fd, SPI_IOC_MESSAGE(1), &spi);

    return rx_data;
}
