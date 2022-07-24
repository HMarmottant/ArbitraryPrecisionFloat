#pragma once
#include <vector>
#include <bitset>
#include <string>
#include <iostream>

typedef unsigned int uint;


struct extendedFloatArray {
	uint size;
	bool sign;
	uint* array;
};

namespace apfloat
{
	#define BASE10APF  (apfloat::apfloat(std::string("000000000000000000000000000001010"),1))
	
	#define BINT_SIZE 32 //addcarry and subborrow need corection if modified
	typedef std::bitset<BINT_SIZE> bint;

	class apfloat
	{
	public:
		apfloat(std::string initvalue, unsigned int size);
		apfloat(std::string initvalue, unsigned int size, apfloat base);
		~apfloat();
		friend void fit(apfloat &A,const apfloat &B);
		void sizechange(int size);//change size this gets rid or increases the least significant bit(left most)
		friend apfloat operator>>(const apfloat &A,uint shift);
		friend apfloat operator<<(const apfloat &A,uint shift);
		friend apfloat operator+(const apfloat &A,const apfloat &B);
		friend apfloat operator-(const apfloat &A,const apfloat &B);
		friend apfloat operator*(const apfloat &A,const apfloat &B);
		friend apfloat operator/(const apfloat &A,const apfloat &B);
		friend std::ostream& operator<<(std::ostream& os, const apfloat &A);
		apfloat extendedRemainderDivRest(apfloat B);
		apfloat extendedRemainderDiv(apfloat D);
		std::string tobasestring(apfloat base);
		int getintegerpart();
		int size() const {return float_segments.size();};
		void flipsign() {sign=!sign;}
		bool null();
		extendedFloatArray getasuintarray();

	private:
		std::vector<bint> float_segments;
		bool sign;
	};


	bint addcarry(bint a, bint b, bool *carry);//add bint a and b with carry

	bint subborrow(bint a, bint b, bool *borrow);//substract b from a with borrow

	std::string strflip(std::string str);

	std::string binttostr(bint a);

}
