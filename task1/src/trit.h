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
        class TritProxy;

        TritSet(int size);

        ~TritSet();

        //Trit get_trit(int index) const;
        Trit get_trit(int index);

        //Trit operator[] (int index) const;
        TritProxy operator[] (int index);

        static Trit get_two_bits(uint8_t byte, int pbit_index);

        size_t get_capacity();

        void expand(int new_size);

        void shrink(int new_size);

        class TritProxy{
            private:
                TritSet& parent_set;
                int index;
            
            public:
                TritProxy(TritSet& parent, int position);

                void operator= (Trit n);
                bool operator== (Trit n);
                bool operator!= (Trit n);

                operator Trit();
        };
};
