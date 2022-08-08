#ifndef WHILEBLOCK_HPP_
#define WHILEBLOCK_HPP_

#include "ProgrammingBlock.hpp"

using namespace std;


class WhileBlock : public ProgrammingBlock {

    int number_of_loops, number_of_loops_initial;
    Block* next_loop;
    Block* next_program;
    Block* previous_program;
    Block* previous_loop;
    bool limited_loop;
    int unit;
    int ten;
    bool setting_unit;

    int value_1_alt;
    int value_3_alt;

    bool is_1_int;
    bool is_1_value;
    bool is_1_bool;
    bool* bool_1_var;
    int* int_1_var;

    bool is_3_int;
    bool is_3_value;
    bool is_3_bool;
    bool* bool_3_var;
    int* int_3_var;

    int logic_2_value;

    void decNumberOfLoops();

public:

    WhileBlock();
    ~WhileBlock(){};
    void setLimitedLoop(bool l);
    bool getLimitedLoop();
    void setNumberOfLoops(int n);
    int getNumberOfLoops();
    void setNext1(Block *b);
    Block* getNext1();
    void setPrevious1(Block *b);
    Block* getPrevious1();
    void setPrevious2(Block *b);
    Block* getPrevious2();
    void setNext2(Block *b);
    Block* getNext2();
    int getPointIn1X();
    int getPointIn1Y();
    int getPointIn2X();
    int getPointIn2Y();
    int getPointOut1X();
    int getPointOut1Y();
    int getPointOut2X();
    int getPointOut2Y();
    Block* getExecutingNext();
    void reset_loop_variables();
    void setUnit(int u);
    int getUnit();
    void setTen(int t);
    int getTen();
    void setValue(int v);

    int setFirstSlotWhile(int n, int* var_int, bool* var_bool);
    int setSecondSlotWhile(int value);
    int setThirdSlotWhile(int n, int* var_int, bool* var_bool, int value);
    Block* executeFunction();

    int* returnIntVar_1();
    bool* returnBoolVar_1();
    int* returnIntVar_3();
    bool* returnBoolVar_3();
    int returnStaticValue_3();
    
    int returnLogicSymbol_2();
};
#endif
