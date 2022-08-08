#include "WhileBlock.hpp"

WhileBlock :: WhileBlock() {
    type =  WHILE_BLOCK;
    next_loop = NULL;
    next_program = NULL;
    previous_program = NULL;
    previous_loop = NULL;
    number_of_loops = 1;
    limited_loop = false;
    unit = 0;
    ten = 0;
    setting_unit = true;

    value_1_alt = 999;
    value_3_alt = 999;

    is_1_int = false;
    is_1_value = false;
    is_1_bool = false;
    bool_1_var = NULL;
    int_1_var = NULL;

    is_3_int = false;
    is_3_value = false;
    is_3_bool = false;
    bool_3_var = NULL;
    int_3_var = NULL;

    logic_2_value = 999;
}

void WhileBlock :: setLimitedLoop(bool l) {
    limited_loop = l;
}

bool WhileBlock :: getLimitedLoop() {
    return limited_loop;
}

void WhileBlock :: setNumberOfLoops(int n) {
    number_of_loops = 2*n;
    number_of_loops_initial = 2*n;
}

int WhileBlock :: getNumberOfLoops() {
    return number_of_loops;
}

void WhileBlock :: decNumberOfLoops() {
    if(limited_loop == true) {
        number_of_loops = number_of_loops - 1;
    }
    ten = (number_of_loops/2)/10;
    unit = ((number_of_loops/2)%10)+1;
}

void WhileBlock :: setNext1(Block *b) {
    next_program = b;
}
Block* WhileBlock :: getNext1() {
    return next_program;
}
void WhileBlock :: setNext2(Block *b) {
    next_loop = b;
}
Block* WhileBlock :: getNext2() {
    return next_loop;
}
void WhileBlock :: setPrevious1(Block *b) {
    previous_program = b;
}
Block* WhileBlock :: getPrevious1() {
    return previous_program;
}
void WhileBlock :: setPrevious2(Block *b) {
    previous_loop = b;
}
Block* WhileBlock :: getPrevious2() {
    return previous_loop;
}
int WhileBlock :: getPointIn1X() {
    pointIn1_x = x + 80;
    return pointIn1_x;
}
int WhileBlock :: getPointIn1Y() {
    pointIn1_y = y;
    return pointIn1_y;
}
int WhileBlock :: getPointIn2X() {
    pointIn2_x = x + 160;
    return pointIn2_x;
}
int WhileBlock :: getPointIn2Y() {
    pointIn2_y = y + 34;
    return pointIn2_y;
}
int WhileBlock :: getPointOut1X() {
    pointOut1_x = x + 80;
    return pointOut1_x;
}
int WhileBlock :: getPointOut1Y() {
    pointOut1_y = y + 42;
    return pointOut1_y;
}
int WhileBlock :: getPointOut2X() {
    pointOut2_x = x + 160;
    return pointOut2_x;
}
int WhileBlock :: getPointOut2Y() {
    pointOut2_y = y + 7;
    return pointOut2_y;
}
Block* WhileBlock :: getExecutingNext() {
    return executeFunction();
}
void WhileBlock :: reset_loop_variables() {
    //number_of_loops = number_of_loops_initial;
    setUnit((number_of_loops_initial/2)%10);
    //setTen(number_of_loops_initial/10);
}
void WhileBlock :: setUnit(int u) {
    unit = u;
    int n = 10*ten + unit;
    setNumberOfLoops(n);
}
int WhileBlock :: getUnit() {
    return unit;
}
void WhileBlock :: setTen(int t) {
    ten = t;
    int n = 10*ten + unit;
    setNumberOfLoops(n);
}
int WhileBlock :: getTen() {
    return ten;
}
void WhileBlock :: setValue(int v) {
    if(setting_unit == true) {
        setUnit(v);
        //setting_unit = false;
        cout<<"setado unidade para "<<v<<endl;
    } else {
        setTen(v);
        setting_unit = true;
        cout<<"setado dezena para "<<v<<endl;
    }
}
int WhileBlock :: setFirstSlotWhile(int n = 0, int* var_int = NULL, bool* var_bool = NULL){
    if(n == 1){
        cout<<"Slot 1 do bloco de while - int: "<<*var_int<<endl;
        is_1_int = true;
        int_1_var = var_int;
        is_1_bool = false;
        return 0;
    }
    if(n == 2){
        cout<<"Slot 1 do bloco de while - bool: "<<*var_bool<<endl;
        is_1_bool = true;
        bool_1_var = var_bool;
        is_1_int = false;
        return 0;
    }
    return 0;
}
int WhileBlock :: setSecondSlotWhile(int value = 0){
    logic_2_value = value;
    return 0;
}
int WhileBlock :: setThirdSlotWhile(int n = 0, int* var_int = NULL, bool* var_bool = NULL, int value = 0){
    if(n == 1){
        cout<<"Slot 3 do bloco de while - int: "<<*var_int<<endl;
        is_3_int = true;
        int_3_var = var_int;
        is_3_bool = false;
        is_3_value = false;
        value_3_alt = 999;
        return 0;
    }
    if(n == 2){
        cout<<"Slot 3 do bloco de while - bool: "<<*var_bool<<endl;
        is_3_bool = true;
        bool_3_var = var_bool;
        is_3_int = false;
        is_3_value = false;
        value_3_alt = 999;
        return 0;
    }
    if(n == 3){
        cout<<"Slot 3 do bloco de while - estatica: "<<value<<endl;
        is_3_value = true;
        value_3_alt = value;
        is_3_int = false;
        is_3_bool = false;
        return 0;
    }
    return 0;
}
Block* WhileBlock :: executeFunction(){
    if(logic_2_value == 0){
        //se for igual
        if(is_3_int == true){
            if(is_1_int == true){
                if(*int_3_var == *int_1_var){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
            if(is_1_bool == true){
                if(*int_3_var >= 1 && *bool_1_var == true){
                    return next_loop;
                }
                else if(*int_3_var < 1 && *bool_1_var == false){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
        return next_program;
        }
        if(is_3_bool == true){
            if(is_1_int == true){
                if(*int_1_var >= 1 && *bool_3_var == true){
                    return next_loop;
                }
                else if(*int_1_var < 1 && *bool_3_var == false){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
            if(is_1_bool == true){
                if(*bool_3_var == *bool_1_var){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
            return next_program;
        }
        if(is_3_value == true){
            if(is_1_int == true){
                if(value_3_alt == *int_1_var){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
            if(is_1_bool == true){
                if(value_3_alt >= 1 && *bool_1_var == true){
                    return next_loop;
                }
                else if(value_3_alt < 1 && *bool_1_var == false){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
            return next_program;
        }
    }
    if(logic_2_value == 1){
        //se for diferente
        if(is_3_int == true){
            if(is_1_int == true){
                if(*int_3_var == *int_1_var){
                    return next_program;
                }
                else{
                    return next_loop;
                }
                return next_program;
            }
            if(is_1_bool == true){
                if(*int_3_var >= 1 && *bool_1_var == true){
                    return next_program;
                }
                else if(*int_3_var < 1 && *bool_1_var == false){
                    return next_program;
                }
                else{
                    return next_loop;
                }
                return next_program;
            }
        return next_program;
        }
        if(is_3_bool == true){
            if(is_1_int == true){
                if(*int_1_var >= 1 && *bool_3_var == true){
                    return next_program;
                }
                else if(*int_1_var < 1 && *bool_3_var == false){
                    return next_program;
                }
                else{
                    return next_loop;
                }
                return next_program;
            }
            if(is_1_bool == true){
                if(*bool_3_var == *bool_1_var){
                    return next_program;
                }
                else{
                    return next_loop;
                }
                return next_program;
            }
            return next_program;
        }
        if(is_3_value == true){
            if(is_1_int == true){
                if(value_3_alt == *int_1_var){
                    return next_program;
                }
                else{
                    return next_loop;
                }
                return next_program;
            }
            if(is_1_bool == true){
                if(value_3_alt >= 1 && *bool_1_var == true){
                    return next_program;
                }
                else if(value_3_alt < 1 && *bool_1_var == false){
                    return next_program;
                }
                else{
                    return next_loop;
                }
                return next_program;
            }
            return next_program;
        }
    }
    //maior
    if(logic_2_value == 2){
        if(is_3_int == true){
            if(is_1_int == true){
                if(*int_3_var < *int_1_var){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
            if(is_1_bool == true){
                return next_program;
            }
        return next_program;
        }
        if(is_3_bool == true){
            if(is_1_int == true){
                return next_program;
            }
            if(is_1_bool == true){
                return next_program;
            }
            return next_program;
        }
        if(is_3_value == true){
            if(is_1_int == true){
                if(value_3_alt < *int_1_var){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
            if(is_1_bool == true){
                return next_program;
            }
            return next_program;
        }
    }
    //maior ou igual
    if(logic_2_value == 3){
        if(is_3_int == true){
            if(is_1_int == true){
                if(*int_3_var <= *int_1_var){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
            if(is_1_bool == true){
                return next_program;
            }
        return next_program;
        }
        if(is_3_bool == true){
            if(is_1_int == true){
                return next_program;
            }
            if(is_1_bool == true){
                return next_program;
            }
            return next_program;
        }
        if(is_3_value == true){
            if(is_1_int == true){
                if(value_3_alt <= *int_1_var){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
            if(is_1_bool == true){
                return next_program;
            }
            return next_program;
        }
    }
    if(logic_2_value == 4){
        if(is_3_int == true){
            if(is_1_int == true){
                if(*int_3_var > *int_1_var){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
            if(is_1_bool == true){
                return next_program;
            }
        return next_program;
        }
        if(is_3_bool == true){
            if(is_1_int == true){
                return next_program;
            }
            if(is_1_bool == true){
                return next_program;
            }
            return next_program;
        }
        if(is_3_value == true){
            if(is_1_int == true){
                if(value_3_alt > *int_1_var){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
            if(is_1_bool == true){
                return next_program;
            }
            return next_program;
        }
    }
    if(logic_2_value == 5){
        if(is_3_int == true){
            if(is_1_int == true){
                if(*int_3_var >= *int_1_var){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
            if(is_1_bool == true){
                return next_program;
            }
        return next_program;
        }
        if(is_3_bool == true){
            if(is_1_int == true){
                return next_program;
            }
            if(is_1_bool == true){
                return next_program;
            }
            return next_program;
        }
        if(is_3_value == true){
            if(is_1_int == true){
                if(value_3_alt >= *int_1_var){
                    return next_loop;
                }
                else{
                    return next_program;
                }
                return next_program;
            }
            if(is_1_bool == true){
                return next_program;
            }
            return next_program;
        }
    }
    return next_program;
}
int* WhileBlock :: returnIntVar_1(){
    if(is_1_int == true){
        return int_1_var;
    }
    else{
        return NULL;
    }
}
bool* WhileBlock :: returnBoolVar_1(){
    if(is_1_bool == true){
        return bool_1_var;
    }
    else{
        return NULL;
    }
}
int* WhileBlock :: returnIntVar_3(){
    if(is_3_int == true){
        return int_3_var;
    }
    else{
        return NULL;
    }
}
bool* WhileBlock :: returnBoolVar_3(){
    if(is_3_bool == true){
        return bool_3_var;
    }
    else{
        return NULL;
    }
}
int WhileBlock :: returnStaticValue_3(){
    if(is_3_value == true){
        return value_3_alt;
    }
    else{
        return 999;
    }
}
int WhileBlock :: returnLogicSymbol_2(){
        return logic_2_value;
}