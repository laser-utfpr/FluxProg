//biblioteca feita para captar leitura e mandar comandos para o robo

#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_
#include "fluxProgBackendCte.h"
#ifdef _WIN32
#include <windows.h>
#endif // _WIN32
class Robot{
protected:
    int ultrasonic_sensor_reading [N_ULTRASONIC];
    int black_type_sensor_reading [N_BLACK_TAPE_SENSOR];
    int color_sensor_reading [N_COLOR_SENSOR];
    int command;
    int abstraction_level;

public:
    Robot();
    ~Robot(){};
    void setCommand(int _command);
    int isFinished();
    int *getUltrasonicReading();
    int *getBlackTypeReading();
    int *getColorReading();
    void updateSensorsReading();
    void setAbstractionLevel(int abstraction);
};

#endif
