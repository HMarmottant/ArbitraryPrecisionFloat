
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
    apfloat A (std::string("1111111111111111111111111111111111"),3);
    apfloat B (std::string("0000000000000000000000000000000001"),4);
    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << A + B << std::endl;
    return 0;
}
