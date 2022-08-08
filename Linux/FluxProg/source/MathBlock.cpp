#include "MathBlock.hpp"

MathBlock :: MathBlock() {
    type = MATH_BLOCK;
    next = NULL;
    previous = NULL;

    operacao = 0;

    value_2_alt = 999;
    value_4_alt = 999;

    is_1_int = false;
    is_1_bool = false;
    bool_1_var = NULL;
    int_1_var = NULL;

    is_2_int = false;
    is_2_value = false;
    is_2_bool = false;
    bool_2_var = NULL;
    int_2_var = NULL;

    is_3_logic = false;
    is_3_math = false;
    logic_3_value = 999;
    math_3_value = 999;

    is_4_int = false;
    is_4_value = false;
    is_4_bool = false;
    bool_4_var = NULL;
    int_4_var = NULL;
}

void MathBlock :: setNext1(Block *b) {
    next = b;
}
Block* MathBlock :: getNext1() {
    return next;
}
void MathBlock :: setNext2(Block *b) {
    //não possui
}
Block* MathBlock :: getNext2() {
    //não possui
    return NULL;
}
void MathBlock :: setPrevious1(Block *b) {
    previous = b;
}
Block* MathBlock :: getPrevious1() {
    return previous;
}
void MathBlock :: setPrevious2(Block *b) {
    //nao tem
}
Block* MathBlock :: getPrevious2() {
    //nao tem
    return NULL;
}
int MathBlock :: getPointIn1X() {
    pointIn1_x = x + 114;
    return pointIn1_x;
}
int MathBlock :: getPointIn1Y() {
    pointIn1_y = y;
    return pointIn1_y;
}
int MathBlock :: getPointIn2X() {
    //nao tem
    return 0;
}
int MathBlock :: getPointIn2Y() {
    //nao tem
    return 0;
}
int MathBlock :: getPointOut1X() {
    pointOut1_x = x + 114;
    return pointOut1_x;
}
int MathBlock :: getPointOut1Y() {
    pointOut1_y = y + 41;
    return pointOut1_y;
}
int MathBlock :: getPointOut2X() {
    //nao tem
    return 0;
}
int MathBlock :: getPointOut2Y() {
    //nao tem;
    return 0;
}
Block* MathBlock :: getExecutingNext() {
    executeFunction();
    return next;
}
int MathBlock :: setFirstSlotMath(int n = 0, int* var_int = NULL, bool* var_bool = NULL){
    if(n == 1){
        cout<<"Slot 1 do bloco de math - int: "<<*var_int<<endl;
        is_1_int = true;
        int_1_var = var_int;
        is_1_bool = false;
        return 0;
    }
    if(n == 2){
        cout<<"Slot 1 do bloco de math - bool: "<<*var_bool<<endl;
        is_1_bool = true;
        bool_1_var = var_bool;
        is_1_int = false;
        return 0;
    }
    return 0;
}
int MathBlock :: setSecondSlotMath(int n = 0, int* var_int = NULL, bool* var_bool = NULL, int value = 0){
    if(n == 1){
        cout<<"Slot 2 do bloco de math - int: "<<*var_int<<endl;
        is_2_int = true;
        int_2_var = var_int;
        is_2_bool = false;
        is_2_value = false;
        value_2_alt = 999;
        return 0;
    }
    if(n == 2){
        cout<<"Slot 2 do bloco de math - bool: "<<*var_bool<<endl;
        is_2_bool = true;
        bool_2_var = var_bool;
        is_2_int = false;
        is_2_value = false;
        value_2_alt = 999;
        return 0;
    }
    if(n == 3){
        cout<<"Slot 2 do bloco de math - estatica: "<<value<<endl;
        is_2_value = true;
        value_2_alt = value;
        is_2_int = false;
        is_2_bool = false;
        return 0;
    }
    return 0;
}
int MathBlock :: setThirdSlotMath(int n = 0, int value = 0){
    if(n == 4){
        cout<<"Slot 3 do bloco de math - math: "<<value<<endl;
        is_3_logic = false;
        math_3_value = value;
        is_3_math = true;
        return 0;
    }
    if(n == 5){
        cout<<"Slot 3 do bloco de math - logic: "<<value<<endl;
        is_3_math = false;
        logic_3_value = value;
        is_3_logic = true;
        return 0;
    }
    return 0;
}
int MathBlock :: setFourthSlotMath(int n = 0, int* var_int = NULL, bool* var_bool = NULL, int value = 0){
    if(n == 1){
        cout<<"Slot 4 do bloco de math - int: "<<*var_int<<endl;
        is_4_int = true;
        int_4_var = var_int;
        is_4_bool = false;
        is_4_value = false;
        value_4_alt = 999;
        return 0;
    }
    if(n == 2){
        cout<<"Slot 4 do bloco de math - bool: "<<*var_bool<<endl;
        is_4_bool = true;
        bool_4_var = var_bool;
        is_4_int = false;
        is_4_value = false;
        value_4_alt = 999;
        return 0;
    }
    if(n == 3){
        cout<<"Slot 4 do bloco de math - estatica: "<<value<<endl;
        is_4_value = true;
        value_4_alt = value;
        is_4_int = false;
        is_4_bool = false;
        return 0;
    }
    return 0;
}
Block* MathBlock :: executeFunction(){
    //ADD
    if(is_3_math == true && math_3_value == 0){
        if(is_1_int == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    *int_1_var = *int_2_var + *int_4_var;
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    *int_1_var = *int_2_var + value_4_alt;
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    *int_1_var = value_2_alt + *int_4_var;
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    *int_1_var = value_2_alt + value_4_alt;
                }
            }
        }
        if(is_1_bool == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
        }
    }
    //SUB
    if(is_3_math == true && math_3_value == 1){
        if(is_1_int == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    *int_1_var = *int_2_var - *int_4_var;
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    *int_1_var = *int_2_var - value_4_alt;
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    *int_1_var = value_2_alt - *int_4_var;
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    *int_1_var = value_2_alt - value_4_alt;
                }
            }
        }
        if(is_1_bool == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
        }
    }
    //MULT
    if(is_3_math == true && math_3_value == 2){
        if(is_1_int == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    *int_1_var = *int_2_var * *int_4_var;
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    *int_1_var = *int_2_var * value_4_alt;
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    *int_1_var = value_2_alt * *int_4_var;
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    *int_1_var = value_2_alt * value_4_alt;
                }
            }
        }
        if(is_1_bool == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
        }
    }
    //DIV
    if(is_3_math == true && math_3_value == 3){
        if(is_1_int == true){
            if(is_2_int == true){
                if(is_4_int == true && *int_4_var != 0){
                    *int_1_var = *int_2_var / *int_4_var;
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true && value_4_alt != 0){
                    *int_1_var = *int_2_var / value_4_alt;
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_value == true){
                if(is_4_int == true && *int_4_var != 0){
                    *int_1_var = value_2_alt / *int_4_var;
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true && value_4_alt != 0){
                    *int_1_var = value_2_alt / value_4_alt;
                }
            }
        }
        if(is_1_bool == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
        }
    }
    //EXPO
    if(is_3_math == true && math_3_value == 4){
        if(is_1_int == true){
            if(is_2_int == true){
                if(is_4_int == true && *int_4_var != 0){
                    *int_1_var = pow(*int_2_var , *int_4_var);
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true && value_4_alt != 0){
                    *int_1_var = pow(*int_2_var , value_4_alt);
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_value == true){
                if(is_4_int == true && *int_4_var != 0){
                    *int_1_var = pow(value_2_alt , *int_4_var);
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true && value_4_alt != 0){
                    *int_1_var = pow(value_2_alt , value_4_alt);
                }
            }
        }
        if(is_1_bool == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    //errado
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    //errado
                }
            }
        }
    }
    //EQUAL
    if(is_3_logic == true && logic_3_value == 0){
        //atribuir a int
        if(is_1_int == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    if(*int_2_var == *int_4_var){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_bool == true){
                    if(*int_2_var >= 1 && *bool_4_var == true){
                        *int_1_var = 1;
                    }
                    else if(*int_2_var < 1 && *bool_4_var == false){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_value == true){
                    if(*int_2_var == value_4_alt){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    if(*int_4_var >= 1 && *bool_2_var == true){
                        *int_1_var = 1;
                    }
                    else if(*int_4_var < 1 && *bool_2_var == false){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_bool == true){
                    if(*bool_2_var == *bool_4_var){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_value == true){
                    if(value_4_alt >= 1 && *bool_2_var == true){
                        *int_1_var = 1;
                    }
                    else if(value_4_alt < 1 && *bool_2_var == false){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    if(value_2_alt == *int_4_var){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_bool == true){
                    if(value_2_alt >= 1 && *bool_4_var == true){
                        *int_1_var = 1;
                    }
                    else if(value_2_alt < 1 && *bool_4_var == false){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_value == true){
                    if(value_2_alt == value_4_alt){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
            }
        }
        //atribuir a bool
        if(is_1_bool == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    if(*int_2_var == *int_4_var){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_bool == true){
                    if(*int_2_var >= 1 && *bool_4_var == true){
                        *bool_1_var = true;
                    }
                    else if(*int_2_var < 1 && *bool_4_var == false){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_value == true){
                    if(*int_2_var == value_4_alt){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    if(*int_4_var >= 1 && *bool_2_var == true){
                        *bool_1_var = true;
                    }
                    else if(*int_4_var < 1 && *bool_2_var == false){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_bool == true){
                    if(*bool_2_var == *bool_4_var){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_value == true){
                    if(value_4_alt >= 1 && *bool_2_var == true){
                        *bool_1_var = true;
                    }
                    else if(value_4_alt < 1 && *bool_2_var == false){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    if(value_2_alt == *int_4_var){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_bool == true){
                    if(value_2_alt >= 1 && *bool_4_var == true){
                        *bool_1_var = true;
                    }
                    else if(value_2_alt < 1 && *bool_4_var == false){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_value == true){
                    if(value_2_alt == value_4_alt){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
            }
        }
    }
    //UNEQUAL
    if(is_3_logic == true && logic_3_value == 1){
        //atribuir a int
        if(is_1_int == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    if(*int_2_var == *int_4_var){
                        *int_1_var = 0;
                    }
                    else{
                        *int_1_var = 1;
                    }
                }
                if(is_4_bool == true){
                    if(*int_2_var >= 1 && *bool_4_var == true){
                        *int_1_var = 0;
                    }
                    else if(*int_2_var < 1 && *bool_4_var == false){
                        *int_1_var = 0;
                    }
                    else{
                        *int_1_var = 1;
                    }
                }
                if(is_4_value == true){
                    if(*int_2_var == value_4_alt){
                        *int_1_var = 0;
                    }
                    else{
                        *int_1_var = 1;
                    }
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    if(*int_4_var >= 1 && *bool_2_var == true){
                        *int_1_var = 0;
                    }
                    else if(*int_4_var < 1 && *bool_2_var == false){
                        *int_1_var = 0;
                    }
                    else{
                        *int_1_var = 1;
                    }
                }
                if(is_4_bool == true){
                    if(*bool_2_var == *bool_4_var){
                        *int_1_var = 0;
                    }
                    else{
                        *int_1_var = 1;
                    }
                }
                if(is_4_value == true){
                    if(value_4_alt >= 1 && *bool_2_var == true){
                        *int_1_var = 0;
                    }
                    else if(value_4_alt < 1 && *bool_2_var == false){
                        *int_1_var = 0;
                    }
                    else{
                        *int_1_var = 1;
                    }
                }
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    if(value_2_alt == *int_4_var){
                        *int_1_var = 0;
                    }
                    else{
                        *int_1_var = 1;
                    }
                }
                if(is_4_bool == true){
                    if(value_2_alt >= 1 && *bool_4_var == true){
                        *int_1_var = 0;
                    }
                    else if(value_2_alt < 1 && *bool_4_var == false){
                        *int_1_var = 0;
                    }
                    else{
                        *int_1_var = 1;
                    }
                }
                if(is_4_value == true){
                    if(value_2_alt == value_4_alt){
                        *int_1_var = 0;
                    }
                    else{
                        *int_1_var = 1;
                    }
                }
            }
        }
        //atribuir a bool
        if(is_1_bool == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    if(*int_2_var == *int_4_var){
                        *bool_1_var = false;
                    }
                    else{
                        *bool_1_var = true;
                    }
                }
                if(is_4_bool == true){
                    if(*int_2_var >= 1 && *bool_4_var == true){
                        *bool_1_var = false;
                    }
                    else if(*int_2_var < 1 && *bool_4_var == false){
                        *bool_1_var = false;
                    }
                    else{
                        *bool_1_var = true;
                    }
                }
                if(is_4_value == true){
                    if(*int_2_var == value_4_alt){
                        *bool_1_var = false;
                    }
                    else{
                        *bool_1_var = true;
                    }
                }
            }
            if(is_2_bool == true){
                if(is_4_int == true){
                    if(*int_4_var >= 1 && *bool_2_var == true){
                        *bool_1_var = false;
                    }
                    else if(*int_4_var < 1 && *bool_2_var == false){
                        *bool_1_var = false;
                    }
                    else{
                        *bool_1_var = true;
                    }
                }
                if(is_4_bool == true){
                    if(*bool_2_var == *bool_4_var){
                        *bool_1_var = false;
                    }
                    else{
                        *bool_1_var = true;
                    }
                }
                if(is_4_value == true){
                    if(value_4_alt >= 1 && *bool_2_var == true){
                        *bool_1_var = false;
                    }
                    else if(value_4_alt < 1 && *bool_2_var == false){
                        *bool_1_var = false;
                    }
                    else{
                        *bool_1_var = true;
                    }
                }
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    if(value_2_alt == *int_4_var){
                        *bool_1_var = false;
                    }
                    else{
                        *bool_1_var = true;
                    }
                }
                if(is_4_bool == true){
                    if(value_2_alt >= 1 && *bool_4_var == true){
                        *bool_1_var = false;
                    }
                    else if(value_2_alt < 1 && *bool_4_var == false){
                        *bool_1_var = false;
                    }
                    else{
                        *bool_1_var = true;
                    }
                }
                if(is_4_value == true){
                    if(value_2_alt == value_4_alt){
                        *bool_1_var = false;
                    }
                    else{
                        *bool_1_var = true;
                    }
                }
            }
        }
    }
    //GREATER
    if(is_3_logic == true && logic_3_value == 2){
        //atribuir a int
        if(is_1_int == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    if(*int_2_var > *int_4_var){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(*int_2_var > value_4_alt){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
            }
            if(is_2_bool == true){
                //errado
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    if(value_2_alt > *int_4_var){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(value_2_alt > value_4_alt){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
            }
        }
        //atribuir a bool
        if(is_1_bool == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    if(*int_2_var > *int_4_var){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(*int_2_var > value_4_alt){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
            }
            if(is_2_bool == true){
                //errado
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    if(value_2_alt > *int_4_var){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(value_2_alt > value_4_alt){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
            }
        }
    }
    //GREATER EQUAL
    if(is_3_logic == true && logic_3_value == 3){
        //atribuir a int
        if(is_1_int == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    if(*int_2_var >= *int_4_var){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(*int_2_var >= value_4_alt){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
            }
            if(is_2_bool == true){
                //errado
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    if(value_2_alt >= *int_4_var){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(value_2_alt >= value_4_alt){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
            }
        }
        //atribuir a bool
        if(is_1_bool == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    if(*int_2_var >= *int_4_var){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(*int_2_var >= value_4_alt){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
            }
            if(is_2_bool == true){
                //errado
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    if(value_2_alt >= *int_4_var){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(value_2_alt >= value_4_alt){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
            }
        }
    }
    //LESS
    if(is_3_logic == true && logic_3_value == 4){
        //atribuir a int
        if(is_1_int == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    if(*int_2_var < *int_4_var){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(*int_2_var < value_4_alt){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
            }
            if(is_2_bool == true){
                //errado
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    if(value_2_alt < *int_4_var){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(value_2_alt < value_4_alt){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
            }
        }
        //atribuir a bool
        if(is_1_bool == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    if(*int_2_var < *int_4_var){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(*int_2_var < value_4_alt){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
            }
            if(is_2_bool == true){
                //errado
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    if(value_2_alt < *int_4_var){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(value_2_alt < value_4_alt){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
            }
        }
    }
    //LESS EQUAL
    if(is_3_logic == true && logic_3_value == 5){
        //atribuir a int
        if(is_1_int == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    if(*int_2_var <= *int_4_var){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(*int_2_var <= value_4_alt){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
            }
            if(is_2_bool == true){
                //errado
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    if(value_2_alt <= *int_4_var){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(value_2_alt <= value_4_alt){
                        *int_1_var = 1;
                    }
                    else{
                        *int_1_var = 0;
                    }
                }
            }
        }
        //atribuir a bool
        if(is_1_bool == true){
            if(is_2_int == true){
                if(is_4_int == true){
                    if(*int_2_var <= *int_4_var){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(*int_2_var <= value_4_alt){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
            }
            if(is_2_bool == true){
                //errado
            }
            if(is_2_value == true){
                if(is_4_int == true){
                    if(value_2_alt <= *int_4_var){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
                if(is_4_bool == true){
                    //errado
                }
                if(is_4_value == true){
                    if(value_2_alt <= value_4_alt){
                        *bool_1_var = true;
                    }
                    else{
                        *bool_1_var = false;
                    }
                }
            }
        }
    }
    return NULL;
}
int* MathBlock :: returnIntVar_1(){
    if(is_1_int == true){
        return int_1_var;
    }
    else{
        return NULL;
    }
}
bool* MathBlock :: returnBoolVar_1(){
    if(is_1_bool == true){
        return bool_1_var;
    }
    else{
        return NULL;
    }
}
int* MathBlock :: returnIntVar_2(){
    if(is_2_int == true){
        return int_2_var;
    }
    else{
        return NULL;
    }
}
bool* MathBlock :: returnBoolVar_2(){
    if(is_2_bool == true){
        return bool_2_var;
    }
    else{
        return NULL;
    }
}
int MathBlock :: returnStaticValue_2(){
    if(is_2_value == true){
        return value_2_alt;
    }
    else{
        return 999;
    }
}
int* MathBlock :: returnIntVar_4(){
    if(is_4_int == true){
        return int_4_var;
    }
    else{
        return NULL;
    }
}
bool* MathBlock :: returnBoolVar_4(){
    if(is_4_bool == true){
        return bool_4_var;
    }
    else{
        return NULL;
    }
}
int MathBlock :: returnStaticValue_4(){
    if(is_4_value == true){
        return value_4_alt;
    }
    else{
        return 999;
    }
}
int MathBlock :: returnLogicSymbol_3(){
    if(is_3_logic == true){
        return logic_3_value;
    }
    else{
        return 999;
    }
}
int MathBlock :: returnMathSymbol_3(){
    if(is_3_math == true){
        return math_3_value;
    }
    else{
        return 999;
    }
}