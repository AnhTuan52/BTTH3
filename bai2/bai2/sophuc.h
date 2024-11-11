#pragma once
#include<iostream>
using namespace std;
class Sophuc
{
private:
		float thuc;
		float ao;
public:
	Sophuc();
	Sophuc(float Thuc, float Ao);

	Sophuc operator +(const Sophuc& S) const ;
	Sophuc operator -(const Sophuc& S) const ;
	Sophuc operator *(const Sophuc& S) const ;
	Sophuc operator /(const Sophuc& S) const ;

	bool operator ==(const Sophuc& S);
	bool operator !=(const Sophuc& S);

	friend ostream& operator<<(ostream& out, const Sophuc& S);
	friend istream& operator >>(istream& in, Sophuc& S);
};

