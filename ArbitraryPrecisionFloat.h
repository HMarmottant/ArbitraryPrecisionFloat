#pragma once
#include <vector>
#include <bitset>
#include <string>
#include <iostream>
#define BINT_SIZE 32

typedef std::bitset<BINT_SIZE> bint;
typedef long unsigned int luint;


class apfloat
{
public:
	apfloat(std::string initvalue, unsigned int size);
	~apfloat();
 
	friend apfloat operator+(const apfloat &A,const apfloat &B);
	friend std::ostream& operator<<(std::ostream& os, const apfloat &A);

private:
	std::vector<bint> float_segments;
	bool sign;
};

bint addcarry(bint a, bint b, bool *carry);

std::string strflip(std::string str);