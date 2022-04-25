
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
    apfloat A (std::string("011111111111111111111111111111111"),1);
    apfloat B (std::string("1000000000000000000000000000000001"),2);
    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << A - B << std::endl;

    // bool borrow = 1;
    // bint a(strflip("00000000000000000000000000000000"));
    // bint b(strflip("11111111111111111111111111111111"));
    // bint c = subborrow(a,b,&borrow);
    // std::cout << borrow << " " << binttostr(c) << std::endl;
    return 0;
}
