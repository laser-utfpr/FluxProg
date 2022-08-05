#include "PhysicalRobot.hpp"

PhysicalRobot::PhysicalRobot(int *error)
{
    if(RS232_OpenComport(CPORT_NR, BDRATE, "8N1"))
    {
        //printf("AVISO: NENHUMA serial encontrada!!\n");
        *error = 1;
    }
    else
    {
        RS232_enableDTR(CPORT_NR);
        RS232_enableRTS(CPORT_NR);
    }
}

PhysicalRobot::~PhysicalRobot()
{
    RS232_CloseComport(CPORT_NR);
}

void PhysicalRobot::setCommand(int _command)
{
    command = _command;
    if(command > 0)
    {
        sendCommand();
    }
}

void PhysicalRobot::sendCommand()
{
    RS232_flushTX(CPORT_NR);
    RS232_SendByte(CPORT_NR, (unsigned char)command);
    std::cout << "mandei o comando 1"<<std::endl;
}

void PhysicalRobot::updateSensorsReading()
{
    receiveData();
}

void PhysicalRobot::receiveData()
{
    int ndx = 0;
    unsigned char rc;
    char receivedChars[64];
    int size = 1;

    int max_rep = 5;
    while (max_rep > 0) {
        size = RS232_PollComport(CPORT_NR, &rc, 1);
	    std::cout << '.' << std::endl;

        if (size > 0 && rc == '<') {
        break;
        }
        else {
        --max_rep;
#ifdef _WIN32
        Sleep(1000);
#else
        sleep(1);
#endif
        }
    }

    while (size > 0 && rc != '>' && ndx < 63) {
        size = RS232_PollComport(CPORT_NR, &rc, 1);
        receivedChars[ndx++] = rc;
    }
    receivedChars[ndx] = '\0';
    RS232_flushRX(CPORT_NR);


    ndx = 0;
    std::cout<< "BLACK TAPE (" << N_BLACK_TAPE_SENSOR << "): ";
    for (int i = 0; i < N_BLACK_TAPE_SENSOR; ++i) {
        black_type_sensor_reading[i] = receivedChars[ndx];
        std::cout << black_type_sensor_reading[i] <<" ";
        ++ndx;
    }
    std::cout << std::endl;
    std::cout << "ULTRASONIC (" << N_ULTRASONIC << "): ";
    for (int i = 0; i < N_ULTRASONIC; i++) {
        ultrasonic_sensor_reading[i] = receivedChars[ndx]? 20: 99999;
        std::cout << ultrasonic_sensor_reading[i] <<" ";
        ++ndx;
    }
    std::cout << std::endl;
    std::cout << "COLOR (" << N_COLOR_SENSOR << "): ";
    for (int i = 0; i < N_COLOR_SENSOR; i++) {
        color_sensor_reading[i] = receivedChars[ndx];
        std::cout << color_sensor_reading[i] <<" ";
        ++ndx;
    }
    std::cout << std::endl;

    command = 1;
}
