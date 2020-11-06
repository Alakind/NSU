#include <fstream>
#include <cmath>

#include "trit.h"

using namespace std;

const int bytes_in_bit = 8;


//  ###################################################### TritSet methods ######################################################

TritSet::TritSet(int size) {
    array = (uint8_t*)malloc(sizeof(uint8_t) * (size / (sizeof(uint8_t) * bytes_in_bit)));
    capacity = size;
    
    // filling with 01 -- unknown
    uint8_t all_ones = 0b01010101;
    for (int i = 0; i < ceil((double) (size * 2) / (sizeof(uint8_t) * bytes_in_bit)); i++) {
        array[i] |= all_ones;
    }
}

TritSet::~TritSet() {
    free(array);
    capacity = 0;
}

void TritSet::expand(int new_size) {
    array = (uint8_t*)realloc(array, sizeof(uint8_t) * (new_size / (sizeof(uint8_t) * bytes_in_bit)));

    // to start filling with unknown from new bytes
    int start = (capacity * 2 / (sizeof(uint8_t) * bytes_in_bit)) + 1;

    // filling with 01 -- unknown
    uint8_t all_ones = 0b01010101;
    for (int i = start; i < ceil((double) (new_size * 2) / (sizeof(uint8_t) * bytes_in_bit)); i++) {
        array[i] |= all_ones;
    }

    capacity = new_size;
}

void TritSet::shrink(int new_size) {
    array = (uint8_t*)realloc(array, sizeof(uint8_t) * (new_size / (sizeof(uint8_t) * bytes_in_bit)));

    capacity = new_size;
}

Trit TritSet::get_trit(int index) {
    if (index > capacity) {
        return Trit::Unknown;
    }

    int byte_pos = index % 4;    // counting position in set
    int arr_pos = (index * 2 / (sizeof(uint8_t) * bytes_in_bit));

    uint8_t byte = array[arr_pos];  // getting needed byte

    Trit trit = TritSet::get_two_bits(byte, byte_pos);   // taking needed pair of bits (trit)

    return trit;
}

/*Trit TritSet::operator[] (int index) const {
    return (*this).get_trit(index);
}*/

TritSet::TritProxy TritSet::operator[] (int index) {
    //TritSet::TritProxy proxy = new TritSet::TritProxy((*this), index);
    
    return TritSet::TritProxy((*this), index);
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
    parent_set = parent;
    index = position;
}

void TritSet::TritProxy::operator= (Trit n) {
    if (n != Trit::Unknown && index > parent_set.capacity) {
        parent_set.expand(index);
    }

    int arr_pos = index / (sizeof(uint8_t) * bytes_in_bit);     // Counting position in tritset
    int byte_pos = (index % (sizeof(uint8_t) * bytes_in_bit)) / 2;

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
}

bool TritSet::TritProxy::operator== (Trit n) {
    if (parent_set.get_trit(index) == n) {
        return true;
    }
    return false;
}

bool TritSet::TritProxy::operator!= (Trit n) {
    if (parent_set.get_trit(index) != n) {
        return true;
    }
    return false;
}
