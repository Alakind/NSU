//#include <string>
#include <cstdint>
#include <iostream>


enum class Trit{False = 0, Unknown = 2, True = 3};   // false - 00, true - 11, unknown - 01

class TritSet{
    // false - 00, true - 11, unknown - 01
    private:
        uint8_t* array;
        size_t capacity;
        friend class TritProxy;

    public:
        TritSet(int n);

        ~TritSet();

        Trit operator[] (int position) const;

        Trit get_two_bits(uint8_t byte, int pbit_index);

        size_t get_capacity();

        class TritProxy{
            private:
                TritSet& parent_set;
                int byte_pos;
                int arr_pos;
            
            public:
                TritProxy(TritSet& parent, int position);

                void operator= (Trit n);
                bool operator== (Trit n);
                bool operator!= (Trit n);
        };
};
