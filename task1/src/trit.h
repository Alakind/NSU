//#include <string>


int plus_ten(int n);

enum class Trit{False = 0, Unknown = 2, True = 3};   // false - 00, true - 11, unknown - 01

class TritSet{
    // false - 00, true - 11, unknown - 01
    private:
        uint8_t* array;
        size_t capacity;
        friend class TritProxy;

    public:
        TritSet(int n) {}

        ~TritSet() {}

        size_t get_capacity() {}

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
        }
};
