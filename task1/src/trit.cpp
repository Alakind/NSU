#include <fstream>
#include <cmath>

#include "trit.h"

using namespace std;

const int bytes_in_bit = 8;


//  ###################################################### TritSet methods ######################################################

TritSet::TritSet(int n) {
    array = (uint8_t*)malloc(sizeof(uint8_t) * (n / (sizeof(uint8_t) * bytes_in_bit)));
    capacity = n;
    
    // filling with 01 -- unknown
    uint8_t all_ones = 0b01010101;
    for (int i = 0; i < ceil((double) (n * 2) / (sizeof(uint8_t) * bytes_in_bit)); i++) {
        array[i] |= all_ones;
    }
}

TritSet::~TritSet() {
    free(array);
    capacity = 0;
}

Trit TritSet::operator[] (int position) const
{
    int byte_pos = position % 4;
    int arr_pos = (position * 2 / (sizeof(uint8_t) * bytes_in_bit));

    uint8_t byte = array[arr_pos];

    Trit trit = TritSet::get_two_bits(byte, byte_pos);

    return trit;
}

Trit TritSet::get_two_bits(uint8_t byte, int pbit_index) {
    uint8_t mask = 0b00000011;

    mask <<= (3 - pbit_index) * 2;
    mask &= byte;

    mask >>= (3 - pbit_index) * 2;

    int number = (int) mask;

    if (number == 3) {
        return Trit::True;
    }
    if (number == 0) {
        return Trit::False;
    }
    if (number == 1) {
        return Trit::Unknown;
    }
}

size_t TritSet::get_capacity() {
    return capacity;
}




//  ################################################### TritProxy methods #######################################################

TritSet::TritProxy::TritProxy(TritSet& parent, int position): parent_set {parent}  {
    //parent_set = parent;
    arr_pos = position / (sizeof(uint8_t) * bytes_in_bit); // Counting position in tritset
    byte_pos = (position % (sizeof(uint8_t) * bytes_in_bit)) / 2;
}

void TritSet::TritProxy::operator= (Trit n) {
    uint8_t mask_tmp = 0b11000000;
    mask_tmp >>= byte_pos;
    uint8_t mask = 0b11111111;
    mask ^= mask_tmp;

    parent_set.array[arr_pos] &= mask;

    if (n == Trit::True) {
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

    /*bool operator== (Trit n) {

    }*/
}
