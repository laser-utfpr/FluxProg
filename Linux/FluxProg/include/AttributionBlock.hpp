#ifndef ATTRIBUTIONBLOCK_HPP_
#define ATTRIBUTIONBLOCK_HPP_

#include "Block.hpp"

using namespace std;


class AttributionBlock : public Block {
    Block* next;
    Block* previous;

    int value_2_alt;

    bool is_1_int, is_1_bool;
    bool* bool_1_var;
    int* int_1_var;

    bool is_2_int, is_2_value, is_2_bool;
    bool* bool_2_var;
    int* int_2_var;

    int int_result;
    bool bool_result;

public:

    AttributionBlock();
    ~AttributionBlock(){};
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
    
    int setFirstSlotAttr(int n, int* var_int, bool* var_bool);
    int setSecondSlotAttr(int n, int* var_int, bool* var_bool, int value);
    Block* executeFunction();

    int* returnIntVar_1();
    bool* returnBoolVar_1();
    int* returnIntVar_2();
    bool* returnBoolVar_2();
    int returnStaticValue_2();
};
#endif
