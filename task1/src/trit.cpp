#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdint>

#include "trit.h"

using namespace std;

int plus_ten(int n) {
    return n + 10;
}


enum class Trit{False = 0, Unknown = 2, True = 3};   // false - 00, true - 11, unknown - 01

TritSet(int n) {
    array = (uint8_t*)malloc(sizeof(uint8_t) * (n / 8));
    capacity = n;
    
    // filling with 01 -- unknown
    uint8_t all_ones = 0b01010101;
    for (int i = 0; i < (n / sizeof(uint8_t)); i++) {
        array[i] |= all_ones;
    }
}

