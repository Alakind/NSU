#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int plus_ten(int n) {
    return n + 10;
}

/*uint32_t CRC32_function(unsigned char *buf, int len_, uint32_t initial_crc_)
{
    uint32_t polynomial = 0xEDB88320;
    uint32_t table_[256];
    for (uint32_t i = 0; i < 256; i++)
    {
        uint32_t table_c_ = i;
        for (int j = 0; j < 8; j++)
        {
            if (table_c_ & 1) {
                table_c_ = polynomial ^ (table_c_ >> 1);
            }
            else {
                table_c_ >>= 1;
            }
        }
        table_[i] = table_c_;
    }

    uint32_t c = initial_crc_ ^ 0xFFFFFFFF;
    auto * u = static_cast<const uint8_t*>(buf);
    for (int i = 0; i < len_; ++i)
    {
        c = table_[(c ^ u[i]) & 0xFF] ^ (c >> 8);
    }
    return c ^ 0xFFFFFFFF;
}


uint32_t CRC32_count(const std::string& filename)
{
    ifstream f (filename, std::ios::binary);
    if (!f.is_open())
    {
        throw std::invalid_argument("File " + filename + " doesn't found");
    }
    char buf_[32];
    uint32_t result_ = 0;
    while (!f.eof())
    {
        f.read(buf_, 32);
        result_ = CRC32_function((unsigned char *) buf_, f.gcount(), result_);
    }
    return result_;
}


uint32_t SUM32_function(unsigned char *buf, int len_, uint32_t initial_number_)
{
    uint32_t res_ = 0;
    uint32_t word_ = initial_number_;
    while (len_ >= 4)
    {
        for (unsigned int i = 4; i > 0; --i)
        {
            word_ += *(buf + len_ - i)<<(8 * (i - 1));
        }
        res_ += word_;
        len_ -= 4;
        word_ = 0;
    }
    if (len_ != 0)
    {
        for (int i = len_; i > 0; --i)
        {
            word_ += *(buf + len_ - i)<<(8 * (i - 1));
        }
        res_ += word_;
    }
    return res_;
}

uint32_t SUM32_count(const std::string& filename)
{
    ifstream f (filename, std::ios::binary);
    if (!f.is_open())
    {
        throw std::invalid_argument("File " + filename + " doesn't found");
    }
    char buf_[32];
    uint32_t result_ = 0;
    while (!f.eof())
    {
        f.read(buf_, 32);
        result_ = SUM32_function((unsigned char *) buf_, f.gcount(), result_);
    }
    return result_;
}*/


