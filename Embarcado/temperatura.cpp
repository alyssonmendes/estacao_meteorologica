#include <fcntl.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/ioctl.h>

//-------------------------------------------------------------------------

float leituraTemperatura(void)
{
    int fd = open("/dev/vcio", 0);
    if (fd == -1)
    {
        perror("open /dev/vcio");
        exit(EXIT_FAILURE);
    }

    uint32_t property[8] =
    {
        0x00000000,
        0x00000000,
        0x00030006,
        0x00000008,
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000
    };

    property[0] = 8 * sizeof(property[0]);

    if (ioctl(fd, _IOWR(100, 0, char *), property) == -1)
    {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    uint32_t temper = property[6];
    property[2] = 0x003000a;
    if (ioctl(fd, _IOWR(100, 0, char *), property) == -1)
    {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    uint32_t tempMax = property[6];
    close(fd);

    //printf("Temp: %.3f\n", (float)temper/1000.0);
    //printf("Max temp: %.3f\n", (float)tempMax/1000.0);

    return (float)temper/1000.0;
}
