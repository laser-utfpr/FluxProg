#ifndef _FLUX_PROG_BACKEND_CTE_H_
#define _FLUX_PROG_BACKEND_CTE_H_

//acesso de memoria
#define MEMORY_BLOCK "memory"
#define MEMORY_COMMAND "command"
#define MEMORY_ABSTRACTION "abstraction_level"
#define MEMORY_FEEDBACK "feedback"
#define MEMORY_VISION_SENSOR "reading_VS"
#define MEMORY_ULTRASONIC_SENSOR "readin_US"
#define MEMORY_ROBOT_TYPE "robot_type"


//variaveis robo
#define VEL_MOT 4.25 //tecnicamente em rad/s
#define DIS_RETO 0.05 //tamanho do passo em m ate inicio da leitura dos sensores
#define DIS_CURVA 0.2 //delta para virar PI, ja que ha o delay de comunicacao e eh float, nunca igual, (~VEL_MOT/(7.5PI)) - aleatorio
#define D_ANG 0.1 //delta para captacao de salto da atan, (~DIS_CURVA-0.1)
#define MAX_INTE 0.2 //delta para media ta intensidade. tecnicamente, deve ser zero
#define CONT 0 //contador para comecar virar
#define N_MOTORS 2
#define ANGLE_COMPONENTS 3

//variaveis bluetooth
#define BDRATE 9600
#define CPORT_NR 26
#define N_ULTRASONIC 1
#define N_BLACK_TAPE_SENSOR 4
#define N_COLOR_SENSOR 2
#define SIZEPACKET (N_ULTRASONIC + N_BLACK_TAPE_SENSOR + N_COLOR_SENSOR)
#define ULTRASONIC_SENSOR_COMPONENTS 3
#define VISION_SENSOR_COMPONENTS 15
#define HIGH_ABSTRACTION 0
#define MID_ABSTRACTION 1
#define LOW_ABSTRACTION 2
#define COLISION -2

//variaveis de communicacao entre back e front end
#define CLOSE_PROGRAM -10
#define CONNECT_ERROR -5
#define CONNECT -1
#define READY 1
#define EXECUTING 0
#define MOVE_FORWARD 8
#define TURN_LEFT 4
#define TURN_RIGHT 6
#endif
