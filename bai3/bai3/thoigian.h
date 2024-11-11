#pragma once
#include<iostream>
using namespace std;
class thoigian
{
private:
	int gio, phut, giay;
public:
	thoigian();
	thoigian(int gio, int phut, int giay);
	
	int sogiay() const;
	void Tinhlaigio(int giay);

	thoigian operator+ (int giay) const;
	thoigian operator -(int giay) const;
	thoigian operator +(const thoigian& tg) const;
	thoigian operator -(const thoigian& tg) const;

	thoigian operator ++(int);
	thoigian operator --(int);

	bool operator ==(const thoigian& tg);
	bool operator !=(const thoigian& tg);
	bool operator >=(const thoigian& tg);
	bool operator <=(const thoigian& tg);
	bool operator >(const thoigian& tg);
	bool operator <(const thoigian& tg);

	friend ostream& operator << (ostream& out, const thoigian& tg);
	friend istream& operator >>(istream& in, thoigian& tg);
};

