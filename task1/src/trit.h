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
        TritSet(int n) {
            array = (uint8_t*)malloc(sizeof(uint8_t) * (n / 8));
            capacity = n;
            
            // filling with 01 -- unknown
            uint8_t all_ones = 0b01010101;
            for (int i = 0; i < (n / sizeof(uint8_t)); i++) {
                array[i] |= all_ones;
            }
        }

        ~TritSet() {
            free(array);
            capacity = 0;
        }

        size_t get_capacity() {
            return capacity;
        }

        class TritProxy{
            private:
                TritSet& parent_set;
                int byte_pos;
                int arr_pos;
            
            public:
        }
};

/*uint32_t CRC32_count(const std::string& filename);

uint32_t CRC32_function(unsigned char *buf, int len_, uint32_t initial_crc_);

uint32_t SUM32_function(unsigned char *buf, int len_, uint32_t initial_number_);

uint32_t SUM32_count(const std::string& filename);*/
