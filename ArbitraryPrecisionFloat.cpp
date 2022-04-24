#include "ArbitraryPrecisionFloat.h"


apfloat::apfloat(std::string initvalue, unsigned int size)
{
    sign = (bool)initvalue.at(initvalue.length()-1);
    initvalue.erase(initvalue.length()-1);
	float_segments = std::vector<bint>(size,0); 
    int cnt = initvalue.length();
    for(int i = float_segments.size()-1;i>=0;i--)
    {
        cnt-=BINT_SIZE;
        if(cnt<0)
        {
            cnt+=BINT_SIZE;
            float_segments.at(i) = bint(initvalue.substr(0,cnt));
            break;
        } 
        float_segments.at(i) = bint(initvalue.substr(cnt,BINT_SIZE));
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
    for(int i = 0 ;i<A.float_segments.size();i++)
    {
        os << A.float_segments.at(i) << " ";
    }
    os << A.sign << std::endl;
    return os;
}