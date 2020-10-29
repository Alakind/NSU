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

// TritSet functions

TritSet::TritSet(int n) {
    array = (uint8_t*)malloc(sizeof(uint8_t) * (n / 8));
    capacity = n;
    
    // filling with 01 -- unknown
    uint8_t all_ones = 0b01010101;
    for (int i = 0; i < (n / sizeof(uint8_t)); i++) {
        array[i] |= all_ones;
    }
}

TritSet::~TritSet() {
    free(array);
    capacity = 0;
}

TritSet::size_t get_capacity() {
    return capacity;
}

// TritProxy functions

TritSet::TritProxy::TritProxy(TritSet& parent, int position) {
    parent_set = parent;
    arr_pos = position / sizeof(uint8_t); // Counting position in tritset
    byte_pos = position % sizeof(uint8_t);
}

TritSet::TritProxy::void operator= (int n) {
    uint8_t mask_tmp = 0b11000000;
    mask_tmp >>= byte_pos;
    uint8_t mask = 0b11111111;
    mask ^= mask_tmp;

    parent_set.array[arr_pos] &= mask;

    if (n == Trit::True) {}
        uint8_t mask_trit = 0b11000000;
        mask_tmp >>= byte_pos;

        parent_set.array[arr_pos] |= mask_trit;
    }
    if (n == Trit::False) {
        uint8_t mask_trit = 0b00000000;

        parent_set.array[arr_pos] |= mask_trit;
    }
    else if (n == Trit::Unknown) {
        uint8_t mask_trit = 0b01000000;
        mask_tmp >>= byte_pos;

        parent_set.array[arr_pos] |= mask_trit;
    }
}

