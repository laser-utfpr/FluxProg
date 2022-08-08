#include "NewConditionalBlock.hpp"

NewConditionalBlock :: NewConditionalBlock() {
    type = NEW_CONDITIONAL_BLOCK;
    pointIn1_x = x + 80;
    pointIn1_y = y;
    pointOut1_x = x + 35;
    pointOut1_y = y + 41;
    pointOut2_x = x + 126;
    pointOut2_y = y + 41;
    next_true = NULL;
    next_false = NULL;
    previous = NULL;
    type_of_sensor = 0;
    
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

void NewConditionalBlock :: setParameter1(int p) {
    parameter1 = p;
}

int NewConditionalBlock :: getParameter1() {
    return parameter1;
}

void NewConditionalBlock :: setParameter2(int p) {
    parameter2 = p;
}

int NewConditionalBlock :: getParameter2() {
    return parameter2;
}

bool NewConditionalBlock :: getResponse() {
    if(parameter1 < parameter2) {
        return false;
    } else {
        return true;
    }
}

void NewConditionalBlock :: setNext1(Block *b) {
    next_true = b;
    //cout<<"setou o next corretamente"<<endl;
    //cout<<"origem: "<<getID()<<" ---- destino: "<<b->getID()<<endl;
}

Block* NewConditionalBlock :: getNext1() {
    return next_true;
}

void NewConditionalBlock :: setNext2(Block *b) {
    next_false = b;
}

Block* NewConditionalBlock :: getNext2() {
    return next_false;
}
void NewConditionalBlock :: setPrevious1(Block *b) {
    previous = b;
}
Block* NewConditionalBlock :: getPrevious1() {
    return previous;
}
void NewConditionalBlock :: setPrevious2(Block *b) {

}
Block* NewConditionalBlock :: getPrevious2() {
    return NULL;
}
void NewConditionalBlock :: setTypeOfSensor(int t) {
    type_of_sensor = t;
}

int NewConditionalBlock :: getTypeOfSensor() {
    return type_of_sensor;
}

int NewConditionalBlock :: getPointIn1X() {
    pointIn1_x = x + 80;
    return pointIn1_x;
}
int NewConditionalBlock :: getPointIn1Y() {
    pointIn1_y = y;
    return pointIn1_y;
}
int NewConditionalBlock :: getPointIn2X() {
    //nao tem
    return 0;
}
int NewConditionalBlock :: getPointIn2Y() {
    //nao tem
    return 0;
}
int NewConditionalBlock :: getPointOut1X() {
    pointOut1_x = x + 35;
    return pointOut1_x;
}
int NewConditionalBlock :: getPointOut1Y() {
    pointOut1_y = y + 41;
    return pointOut1_y;
}
int NewConditionalBlock :: getPointOut2X() {
    pointOut2_x = x + 126;
    return pointOut2_x;
}
int NewConditionalBlock :: getPointOut2Y() {
    pointOut2_y = y + 41;
    return pointOut2_y;
}
Block* NewConditionalBlock :: getExecutingNext() {
    return executeFunction();
}
int NewConditionalBlock :: setFirstSlotConditional(int n = 0, int* var_int = NULL, bool* var_bool = NULL){
    if(n == 1){
        cout<<"Slot 1 do bloco de conditional - int: "<<*var_int<<endl;
        is_1_int = true;
        int_1_var = var_int;
        is_1_bool = false;
        return 0;
    }
    if(n == 2){
        cout<<"Slot 1 do bloco de conditional - bool: "<<*var_bool<<endl;
        is_1_bool = true;
        bool_1_var = var_bool;
        is_1_int = false;
        return 0;
    }
    return 0;
}
int NewConditionalBlock :: setSecondSlotConditional(int value = 0){
    logic_2_value = value;
    return 0;
}
int NewConditionalBlock :: setThirdSlotConditional(int n = 0, int* var_int = NULL, bool* var_bool = NULL, int value = 0){
    if(n == 1){
        cout<<"Slot 3 do bloco de conditional - int: "<<*var_int<<endl;
        is_3_int = true;
        int_3_var = var_int;
        is_3_bool = false;
        is_3_value = false;
        value_3_alt = 999;
        return 0;
    }
    if(n == 2){
        cout<<"Slot 3 do bloco de conditional - bool: "<<*var_bool<<endl;
        is_3_bool = true;
        bool_3_var = var_bool;
        is_3_int = false;
        is_3_value = false;
        value_3_alt = 999;
        return 0;
    }
    if(n == 3){
        cout<<"Slot 3 do bloco de conditional - estatica: "<<value<<endl;
        is_3_value = true;
        value_3_alt = value;
        is_3_int = false;
        is_3_bool = false;
        return 0;
    }
    return 0;
}
Block* NewConditionalBlock :: executeFunction(){
    if(logic_2_value == 0){
        //se for igual
        if(is_3_int == true){
            if(is_1_int == true){
                if(*int_3_var == *int_1_var){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
            if(is_1_bool == true){
                if(*int_3_var >= 1 && *bool_1_var == true){
                    return next_true;
                }
                else if(*int_3_var < 1 && *bool_1_var == false){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
        return next_false;
        }
        if(is_3_bool == true){
            if(is_1_int == true){
                if(*int_1_var >= 1 && *bool_3_var == true){
                    return next_true;
                }
                else if(*int_1_var < 1 && *bool_3_var == false){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
            if(is_1_bool == true){
                if(*bool_3_var == *bool_1_var){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
            return next_false;
        }
        if(is_3_value == true){
            if(is_1_int == true){
                if(value_3_alt == *int_1_var){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
            if(is_1_bool == true){
                if(value_3_alt >= 1 && *bool_1_var == true){
                    return next_true;
                }
                else if(value_3_alt < 1 && *bool_1_var == false){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
            return next_false;
        }
    }
    if(logic_2_value == 1){
        //se for diferente
        if(is_3_int == true){
            if(is_1_int == true){
                if(*int_3_var == *int_1_var){
                    return next_false;
                }
                else{
                    return next_true;
                }
                return next_false;
            }
            if(is_1_bool == true){
                if(*int_3_var >= 1 && *bool_1_var == true){
                    return next_false;
                }
                else if(*int_3_var < 1 && *bool_1_var == false){
                    return next_false;
                }
                else{
                    return next_true;
                }
                return next_false;
            }
        return next_false;
        }
        if(is_3_bool == true){
            if(is_1_int == true){
                if(*int_1_var >= 1 && *bool_3_var == true){
                    return next_false;
                }
                else if(*int_1_var < 1 && *bool_3_var == false){
                    return next_false;
                }
                else{
                    return next_true;
                }
                return next_false;
            }
            if(is_1_bool == true){
                if(*bool_3_var == *bool_1_var){
                    return next_false;
                }
                else{
                    return next_true;
                }
                return next_false;
            }
            return next_false;
        }
        if(is_3_value == true){
            if(is_1_int == true){
                if(value_3_alt == *int_1_var){
                    return next_false;
                }
                else{
                    return next_true;
                }
                return next_false;
            }
            if(is_1_bool == true){
                if(value_3_alt >= 1 && *bool_1_var == true){
                    return next_false;
                }
                else if(value_3_alt < 1 && *bool_1_var == false){
                    return next_false;
                }
                else{
                    return next_true;
                }
                return next_false;
            }
            return next_false;
        }
    }
    //maior
    if(logic_2_value == 2){
        if(is_3_int == true){
            if(is_1_int == true){
                if(*int_3_var < *int_1_var){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
            if(is_1_bool == true){
                return next_false;
            }
        return next_false;
        }
        if(is_3_bool == true){
            if(is_1_int == true){
                return next_false;
            }
            if(is_1_bool == true){
                return next_false;
            }
            return next_false;
        }
        if(is_3_value == true){
            if(is_1_int == true){
                if(value_3_alt < *int_1_var){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
            if(is_1_bool == true){
                return next_false;
            }
            return next_false;
        }
    }
    //maior ou igual
    if(logic_2_value == 3){
        if(is_3_int == true){
            if(is_1_int == true){
                if(*int_3_var <= *int_1_var){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
            if(is_1_bool == true){
                return next_false;
            }
        return next_false;
        }
        if(is_3_bool == true){
            if(is_1_int == true){
                return next_false;
            }
            if(is_1_bool == true){
                return next_false;
            }
            return next_false;
        }
        if(is_3_value == true){
            if(is_1_int == true){
                if(value_3_alt <= *int_1_var){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
            if(is_1_bool == true){
                return next_false;
            }
            return next_false;
        }
    }
    if(logic_2_value == 4){
        if(is_3_int == true){
            if(is_1_int == true){
                if(*int_3_var > *int_1_var){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
            if(is_1_bool == true){
                return next_false;
            }
        return next_false;
        }
        if(is_3_bool == true){
            if(is_1_int == true){
                return next_false;
            }
            if(is_1_bool == true){
                return next_false;
            }
            return next_false;
        }
        if(is_3_value == true){
            if(is_1_int == true){
                if(value_3_alt > *int_1_var){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
            if(is_1_bool == true){
                return next_false;
            }
            return next_false;
        }
    }
    if(logic_2_value == 5){
        if(is_3_int == true){
            if(is_1_int == true){
                if(*int_3_var >= *int_1_var){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
            if(is_1_bool == true){
                return next_false;
            }
        return next_false;
        }
        if(is_3_bool == true){
            if(is_1_int == true){
                return next_false;
            }
            if(is_1_bool == true){
                return next_false;
            }
            return next_false;
        }
        if(is_3_value == true){
            if(is_1_int == true){
                if(value_3_alt >= *int_1_var){
                    return next_true;
                }
                else{
                    return next_false;
                }
                return next_false;
            }
            if(is_1_bool == true){
                return next_false;
            }
            return next_false;
        }
    }
    return next_false;
}
int* NewConditionalBlock :: returnIntVar_1(){
    if(is_1_int == true){
        return int_1_var;
    }
    else{
        return NULL;
    }
}
bool* NewConditionalBlock :: returnBoolVar_1(){
    if(is_1_bool == true){
        return bool_1_var;
    }
    else{
        return NULL;
    }
}
int* NewConditionalBlock :: returnIntVar_3(){
    if(is_3_int == true){
        return int_3_var;
    }
    else{
        return NULL;
    }
}
bool* NewConditionalBlock :: returnBoolVar_3(){
    if(is_3_bool == true){
        return bool_3_var;
    }
    else{
        return NULL;
    }
}
int NewConditionalBlock :: returnStaticValue_3(){
    if(is_3_value == true){
        return value_3_alt;
    }
    else{
        return 999;
    }
}
int NewConditionalBlock :: returnLogicSymbol_2(){
        return logic_2_value;
}