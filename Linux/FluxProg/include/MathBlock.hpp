#ifndef MATHBLOCK_HPP_
#define MATHBLOCK_HPP_

#include "Block.hpp"
#include <math.h>

using namespace std;


class MathBlock : public Block {

    Block* next;
    Block* previous;

    int operacao;

    int value_2_alt;
    int value_4_alt;

    bool is_1_int;
    bool is_1_bool;
    bool* bool_1_var;
    int* int_1_var;

    bool is_2_int;
    bool is_2_value;
    bool is_2_bool;
    bool* bool_2_var;
    int* int_2_var;

    bool is_3_logic;
    bool is_3_math;
    int logic_3_value;
    int math_3_value;

    bool is_4_int;
    bool is_4_value;
    bool is_4_bool;
    bool* bool_4_var;
    int* int_4_var;


public:

    MathBlock();
    ~MathBlock(){};
    void setNext1(Block *b);
    Block* getNext1();
    void setNext2(Block *b);
    Block* getNext2();
    void setPrevious1(Block *b);
    Block* getPrevious1();
    void setPrevious2(Block *b);
    Block* getPrevious2();
    int getPointIn1X();
    int getPointIn1Y();
    int getPointIn2X();
    int getPointIn2Y();
    int getPointOut1X();
    int getPointOut1Y();
    int getPointOut2X();
    int getPointOut2Y();
    Block* getExecutingNext();

    int setFirstSlotMath(int n, int* var_int, bool* var_bool);
    int setSecondSlotMath(int n, int* var_int, bool* var_bool, int value);
    int setThirdSlotMath(int n, int value);
    int setFourthSlotMath(int n, int* var_int, bool* var_bool, int value);
    Block* executeFunction();

    int* returnIntVar_1();
    bool* returnBoolVar_1();
    int* returnIntVar_2();
    bool* returnBoolVar_2();
    int returnStaticValue_2();
    int* returnIntVar_4();
    bool* returnBoolVar_4();
    int returnStaticValue_4();
    
    int returnLogicSymbol_3();
    int returnMathSymbol_3();
};
#endif