#ifndef NEWCONDITIONALBLOCK_HPP_
#define NEWCONDITIONALBLOCK_HPP_

#include "ProgrammingBlock.hpp"

using namespace std;


class NewConditionalBlock : public ProgrammingBlock {

    int parameter1;
    int parameter2;
    int type_of_sensor;
    Block* previous;
    Block* next_true;
    Block* next_false;

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


    bool getResponse();

public:

    NewConditionalBlock();
    ~NewConditionalBlock(){};
    void setParameter1(int p);
    int getParameter1();
    void setParameter2(int p);
    int getParameter2();
    void setPrevious(Block b);
    Block getPrevious();
    void setNext1(Block *b);
    Block* getNext1();
    void setNext2(Block *b);
    Block* getNext2();
    void setPrevious1(Block *b);
    Block* getPrevious1();
    void setPrevious2(Block *b);
    Block* getPrevious2();
    void setTypeOfSensor(int t);
    int getTypeOfSensor();
    int getPointIn1X();
    int getPointIn1Y();
    int getPointIn2X();
    int getPointIn2Y();
    int getPointOut1X();
    int getPointOut1Y();
    int getPointOut2X();
    int getPointOut2Y();
    Block* getExecutingNext();

    int setFirstSlotConditional(int n, int* var_int, bool* var_bool);
    int setSecondSlotConditional(int value);
    int setThirdSlotConditional(int n, int* var_int, bool* var_bool, int value);
    Block* executeFunction();

    int* returnIntVar_1();
    bool* returnBoolVar_1();
    int* returnIntVar_3();
    bool* returnBoolVar_3();
    int returnStaticValue_3();
    
    int returnLogicSymbol_2();
};
#endif
