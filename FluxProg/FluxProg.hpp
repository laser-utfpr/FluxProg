#ifndef _FLUXPROG_HPP_
#define _FLUXPROG_HPP_

#include <iostream> // usada para debugging
#include <cmath>
#include <fstream>
#include <cstring>
#include <iostream>
#include <signal.h>
#include "Block.hpp"
#include "StartBlock.hpp"
#include "ActionBlock.hpp"
#include "ConditionalBlock.hpp"
#include "EndBlock.hpp"
#include "LoopBlock.hpp"
#include "MergeBlock.hpp"
#include "Communication.hpp"
#include "fluxProgCte.h"
#include "Interface.hpp"

using namespace std;

#define valor_maximo_blocos 100

class FluxProg {

    Block* blocks_list_to_print[valor_maximo_blocos];
    bool executing_fluxogram;
    Block* current_executing_block;
    bool simulator_connected, robot_connected, program_connected;
    Communication* communication;
    Interface* interface;

    void add_block(Block* b);
    void remove_block(Block* b);
    void refresh_executing_block();
    void execute();
    bool check_if_only_one_startblock_exists();
    bool check_if_at_least_one_endblock_exist();
    bool check_if_all_the_blocks_have_connections();
    bool check_if_all_blocks_have_functions_or_sensors();
    void reset_fluxogram_execution();

    void connect_simulator();
    void connect_robot();
    void connect();

public:

    FluxProg();
    ~FluxProg();
    void start();
};
#endif
