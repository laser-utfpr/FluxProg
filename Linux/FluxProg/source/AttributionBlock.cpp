#include "AttributionBlock.hpp"

AttributionBlock :: AttributionBlock() {
    type = ATTRIBUTION_BLOCK;
    next = NULL;
    previous = NULL;

    value_2_alt = 999;
    
    is_2_int = false;
    is_2_value = false;
    is_2_bool = false;
    bool_2_var = NULL;
    int_2_var = NULL;

    is_1_int = false;
    is_1_bool = false;
    bool_1_var = NULL;
    int_1_var = NULL;
}

void AttributionBlock :: setNext1(Block *b) {
    next = b;
}
Block* AttributionBlock :: getNext1() {
    return next;
}
void AttributionBlock :: setNext2(Block *b) {
    //não possui
}
Block* AttributionBlock :: getNext2() {
    //não possui
    return NULL;
}
void AttributionBlock :: setPrevious1(Block *b) {
    previous = b;
}
Block* AttributionBlock :: getPrevious1() {
    return previous;
}
void AttributionBlock :: setPrevious2(Block *b) {
    //nao tem
}
Block* AttributionBlock :: getPrevious2() {
    //nao tem
    return NULL;
}
int AttributionBlock :: getPointIn1X() {
    pointIn1_x = x + 80;
    return pointIn1_x;
}
int AttributionBlock :: getPointIn1Y() {
    pointIn1_y = y;
    return pointIn1_y;
}
int AttributionBlock :: getPointIn2X() {
    //nao tem
    return 0;
}
int AttributionBlock :: getPointIn2Y() {
    //nao tem
    return 0;
}
int AttributionBlock :: getPointOut1X() {
    pointOut1_x = x + 80;
    return pointOut1_x;
}
int AttributionBlock :: getPointOut1Y() {
    pointOut1_y = y + 41;
    return pointOut1_y;
}
int AttributionBlock :: getPointOut2X() {
    //nao tem
    return 0;
}
int AttributionBlock :: getPointOut2Y() {
    //nao tem;
    return 0;
}
Block* AttributionBlock :: getExecutingNext() {
    executeFunction();
    return next;
}
int AttributionBlock :: setFirstSlotAttr(int n, int* var_int = NULL, bool* var_bool = NULL) {
    //valor do ponteiro no primeiro slot;
    if(n == 1){
        cout<<"Slot 1 do bloco de atribuicao - int: "<<*var_int<<endl;
        is_1_int = true;
        int_1_var = var_int;
        is_1_bool = false;
        return 0;
    }
    if(n == 2){
        cout<<"Slot 1 do bloco de atribuicao - bool: "<<*var_bool<<endl;
        is_1_bool = true;
        bool_1_var = var_bool;
        is_1_int = false;
        return 0;
    }
    return 0;
}
int AttributionBlock :: setSecondSlotAttr(int n, int* var_int = NULL, bool* var_bool = NULL, int value = 0) {
    //valor do ponteiro/integral no segundo slot;
    if(n == 1){
        cout<<"Slot 2 do bloco de atribuicao - int: "<<*var_int<<endl;
        is_2_int = true;
        int_2_var = var_int;
        is_2_bool = false;
        is_2_value = false;
        value_2_alt = 999;
        return 0;
    }
    if(n == 2){
        cout<<"Slot 2 do bloco de atribuicao - bool: "<<*var_bool<<endl;
        is_2_bool = true;
        bool_2_var = var_bool;
        is_2_int = false;
        is_2_value = false;
        value_2_alt = 999;
        return 0;
    }
    if(n == 3){
        cout<<"Slot 2 do bloco de atribuicao - estatica: "<<value<<endl;
        is_2_value = true;
        value_2_alt = value;
        is_2_int = false;
        is_2_bool = false;
        return 0;
    }
    return 0;
}
Block* AttributionBlock :: executeFunction() {
    if(is_1_int == true){
        if(is_2_int == true){
            *int_1_var = *int_2_var;
            return 0;
        }
        if(is_2_bool == true){
            if(*bool_2_var == true){
                *int_1_var = 1;
                return 0;
            }
            if(*bool_2_var == false){
                *int_1_var = 0;
                return 0;
            }
        }
        if(is_2_value == true){
            *int_1_var = value_2_alt;
            return 0;
        }
    }
    if(is_1_bool == true){
        if(is_2_int == true){
            if(*int_2_var > 0){
                *bool_1_var = true;
                return 0;
            }
            if(*int_2_var == 0){
                *bool_1_var = false;
                return 0;
            }
        }
        if(is_2_bool == true){
            *bool_1_var = *bool_2_var;
            return 0;
        }
        if(is_2_value == true){
            if(value_2_alt > 0){
                *bool_1_var = true;
                return 0;
            }
            if(value_2_alt == 0){
                *bool_1_var = false;
                return 0;
            }
        }
    }
    return 0;
}
int* AttributionBlock :: returnIntVar_1(){
    if(is_1_int == true){
        return int_1_var;
    }
    else{
        return NULL;
    }
}
bool* AttributionBlock :: returnBoolVar_1(){
    if(is_1_bool == true){
        return bool_1_var;
    }
    else{
        return NULL;
    }
}
int* AttributionBlock :: returnIntVar_2(){
    if(is_2_int == true){
        return int_2_var;
    }
    else{
        return NULL;
    }
}
bool* AttributionBlock :: returnBoolVar_2(){
    if(is_2_bool == true){
        return bool_2_var;
    }
    else{
        return NULL;
    }
}
int AttributionBlock :: returnStaticValue_2(){
    if(is_2_value == true){
        return value_2_alt;
    }
    else{
        return 999;
    }
}