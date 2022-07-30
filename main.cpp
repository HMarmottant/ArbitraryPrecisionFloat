
#include "ArbitraryPrecisionFloat.h"

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
    // double f = 1;
    // double e = 0;
    // for(int i =0;i<50;i++)
    // {
    //     e = e + (1/f);
    //     f = f * (i +1);
    //     std::cout << printf("%1.32f",e) << std::endl; 
    // }   

    apfloat::apfloat base (std::string("000000000000000000000000000001010"),1);
    apfloat::apfloat e (std::string("0"),16,BASE10APF);
    apfloat::apfloat one (std::string("1.0"),16,BASE10APF);
    apfloat::apfloat n = one;
    apfloat::apfloat inv_facto = one;

    extendedFloatArray st = e.getasuintarray();
    // std::cout << e.tobasestring(BASE10APF) << std::endl;

    // std::cout << one.tobasestring(BASE10APF) << std::endl;

    for(int i =0;i<50;i++)
    {
        e = e + inv_facto;
        inv_facto = inv_facto / n;
        n = n + one;
        std::cout << e.tobasestring(BASE10APF) << std::endl;
        // std::cout << n.tobasestring(BASE10APF) << std::endl;
        // std::cout << facto.tobasestring(BASE10APF) << std::endl << std::endl;
    }

    // std::cout << A << std::endl;

    // std::cout << std::to_string(test);


    // apfloat::apfloat A (std::string("000000000000000000000000110110111101101011010110001"),4);
    
    // apfloat::apfloat C (std::string("0000000000000000000000001001110111111101011011110001"),4);
    // C = apfloat::apfloat(std::string("0000000000000000000000001001110111111101011011110001"),4);
    // std::cout << A << std::endl;
    // std::cout << C << std::endl;
    // std::cout << base << std::endl;
    // std::cout << A.extendedRemainderDivSpecial(B) << std::endl;
    // std::cout << A.tobasestring(base) << std::endl;
    // std::cout << C.tobasestring(base) << std::endl;
    // std::cout << (A * C).tobasestring(base) << std::endl;
    // std::cout << A.getintegerpart() << std::endl;
    // std::cout << A.extendedRemainderDiv(B) << std::endl;
    // std::cout << A.extendedRemainderDivRest(B) << std::endl;
    // std::cout << B << std::endl;
    // std::cout << A + B << std::endl;
    // std::cout << A / B << std::endl;

    // bool borrow = 1;
    // bint a(strflip("10000000000000000000000000000000"));
    // bint b(strflip("11111111111111111111111111111111"));
    // a>>=2;
    // std::cout << binttostr(a) << std::endl;
    // bint c = subborrow(a,b,&borrow);
    // std::cout << borrow << " " << binttostr(c) << std::endl;
    return 0;
}
