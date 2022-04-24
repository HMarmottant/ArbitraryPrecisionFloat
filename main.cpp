
#include "ArbitraryPrecisionFloat.h"
#include "ByteArrayConverter.h"

float bintofloat(unsigned int x) {
    union {
        unsigned int  x;
        float  f;
    } temp;
    temp.x = x;
    return temp.f;
}

uint floattobin(float x) {
    union {
        float  x;
        uint  f;
    } temp;
    temp.x = x;
    return temp.f;
}



int main(int argc, char const *argv[])
{
    apfloat f (std::string("11010000000001101010110101011111011110101"),8);
    std::cout << f << std::endl;
    // std::string str("1001011");
    // bint a = bint(str);
    // std::cout << a.test(0) << std::endl;
    // std::cout << a << std::endl;
    return 0;
}
