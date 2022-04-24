#include "ArbitraryPrecisionFloat.h"


apfloat::apfloat(std::string initvalue, unsigned int size)
{
    sign = initvalue.at(0) == '1';
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
    apfloat result("0",0);
    if(B.float_segments.size() > A.float_segments.size()) result = apfloat("0",B.float_segments.size());
    else result = apfloat("0",A.float_segments.size());
    bool carry = 0;
    for(int i = result.size();i>=0;i--)
    {
        if(i<A.float_segments.size() && i<B.float_segments.size())
        {
            result.float_segments.at(i) = addcarry(A.float_segments.at(i),B.float_segments.at(i),&carry);
        }
        else if(i<A.float_segments.size())
        {
            result.float_segments.at(i) = addcarry(A.float_segments.at(i),bint("0"),&carry);
        }
        else if(i<B.float_segments.size())
        {
            result.float_segments.at(i) = addcarry(bint("0"),B.float_segments.at(i),&carry);
        }
        //std::cout << carry << std::endl;
    }
    return result;
}

bint addcarry(bint a, bint b, bool *carry)
{
    bint res = 0;
    if(*carry)
    {
        *carry = 0;
        bint carryadd("10000000000000000000000000000000");
        while(carryadd.any())
        {
            res = a&carryadd;
            a^=carryadd;
            if(res.test(0)) *carry = 1;
            carryadd = res>>1;
        }
    }
    res = 0;
    while(b.any())
    {
        res = a&b;
        a^=b;
        if(res.test(0)) *carry = 1;
        b = res>>1;
    }
    return a;
}

std::ostream& operator<<(std::ostream& os, const apfloat &A)
{
    os << A.sign << " ";
    for(int i = 0 ;i<A.float_segments.size();i++)
    {
        os << binttostr(A.float_segments[i]) <<" ";
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

std::string binttostr(bint a)
{
    std::string str = "";
    for(int j = 0;j<BINT_SIZE;j++) str += a.test(j)?"1":"0";
    return str;
}