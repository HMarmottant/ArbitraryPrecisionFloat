#include "ArbitraryPrecisionFloat.h"


apfloat::apfloat(std::string initvalue, unsigned int size)
{
    sign = (bool)initvalue.at(0);
    initvalue.erase(0,1);
	float_segments = std::vector<bint>(size,0); 
    int cnt = 0;
    for(int i = 0;i<float_segments.size();i++)
    {
        
        if(cnt+BINT_SIZE>initvalue.length())
        {
            float_segments.at(i) = bint(strflip(initvalue.substr(cnt,initvalue.length()-cnt)));
            break;
        } 
        float_segments.at(i) = bint(strflip(initvalue.substr(cnt,BINT_SIZE)));
        cnt+=BINT_SIZE;
    }

    
}

apfloat::~apfloat()
{

}

apfloat operator+(const apfloat &A,const apfloat &B)
{
    if(B.float_segments.size() > A.float_segments.size()) apfloat result("",B.float_segments.size());
    else apfloat result("",A.float_segments.size());
    
}

bint addcarry(bint a, bint b, bool *carry)
{
    bint res;
    while(b.any())
    {
        res = a&b;
        a^=b;
        if(res.test(BINT_SIZE - 1))*carry = 1;
        b = res<<1;
    }
    return a;
}

std::ostream& operator<<(std::ostream& os, const apfloat &A)
{
    os << A.sign << " ";
    for(int i = 0 ;i<A.float_segments.size();i++)
    {
        for(int j = 0;j<BINT_SIZE;j++) os << A.float_segments[i].test(j);
        os << " ";
    }
    os << std::endl;
    return os;
}

std::string strflip(std::string str)
{
    std::string tmp = str;
    for(int i = 0;i<str.length();i++)
    {
        tmp[i] = str[str.length()-1-i];
    }
    return tmp;
}