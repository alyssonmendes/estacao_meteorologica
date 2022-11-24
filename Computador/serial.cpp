/************************************************************
 * File RobotLinux.cpp - Implementation for the RobotLinux class
 *
 * This class has the implementation for virtual
 * methods from Robot.h (and Robot.cpp)
 *
 * Project: Fischer Arm
 *
 * Author: Eduardo Augusto Bezerra
 * Date: 04/04/2003
 *
 * Last change: Eduardo Augusto Bezerra
 * Date: 26/04/2003
 *
 * Methods for controlling the robot in C++ under linux
 * This code has been tested on linux Red Hat 8.0
 *
 *************************************************************/
#include "RobotLinux.h"

/************************************************************

 * Constructor

 *************************************************************/

RobotLinux::RobotLinux(void)
{
    motorWord = 0;
    fd = -1;
}

/************************************************************

 * Destructor

 *************************************************************/

RobotLinux::~RobotLinux(void)
{
    close(fd);
}
/************************************************************
 * void RobotLinux::openSerial(int ser)
 *
 * open the serial connection;
 * sets the serial parameters to 9600 Baud, no parity, 8, 1;
 * and turns all motors off
 *
 *************************************************************/

void RobotLinux::openSerial(int ser)
{
    // serial names
    const char *com1="/dev/ttyS0", *com2="/dev/ttyS1",
                *com3="/dev/ttyS2", *com4="/dev/ttyS3";


    struct termios options;

    switch(ser)
    {

    case 1:
        strcpy(serial,com1);

        break;

    case 2:
        strcpy(serial,com2);

        break;

    case 3:
        strcpy(serial,com3);

        break;

    case 4:
        strcpy(serial,com4);

        break;

    default:
        cout << "Error! valid ports are 1, 2, 3 and 4. "

             << "Will try to open port 1." << endl;

    }

    fd = open(serial, O_RDWR|O_NOCTTY|O_NDELAY);

    if (fd == -1)      // ERROR!!
        cout << "Error opening " << serial << endl;
    else
        fcntl(fd, F_SETFL, 0);

    cout << "Serial port in use: " << serial << endl << endl;

    // Program serial port to 9600, 8, 1, no parity
    //
    // Get the current options for the port
    tcgetattr(fd, &options);

    // Set the baud rate to 9600
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);

    // Enable the receiver and set local mode
     options.c_cflag |= (CLOCAL | CREAD);

    // Setting parity checking (no parity) 8N1

    options.c_cflag &= ~PARENB;        /* no parity */
    options.c_cflag &= ~CSTOPB;        /* 1 stop bit */
    options.c_cflag &= ~CSIZE;         /* Mask the character size bits */
    options.c_cflag |= CS8;            /* Select 8 data bits */

    // Setting raw input
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    // Setting raw output
    options.c_oflag &= ~OPOST;


    // Set the new options for the port
    tcsetattr(fd, TCSANOW, &options);

    motorsOff();                // motors off

}

/************************************************************
 * char sendCommand(char motorWord)
 *
 * gets a full word representing all inputs (1..8)
 *************************************************************/

char RobotLinux::sendCommand(char motorWord)
{
    char commandWord[2];
    commandWord[0] = '\xc1';         // 1st byte: 193 in hexadecimal
    commandWord[1] = motorWord;      // 2nd byte: motorWord
    int i;

    if (fd == -1)
        cout << "Erro: the serial port is closed. Please, "
            << "use the openSerial() method to open it. " << endl;
    else
    {
        int n = write(fd, commandWord, 2);  // send 2 bytes command & motors
        if (n < 0)
            cout << "Error! write() command and motor bytes failed." << endl;
        else
       {
            fcntl(fd, F_SETFL, FNDELAY);
            i = read(fd, commandWord, 1); // read 1 Byte interface status
            fcntl(fd, F_SETFL, 0);
            commandWord[1] = 0;      /* set end of string, so we can printf */
        }
    }
    return commandWord[0];
}
