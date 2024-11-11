#pragma once
#include<bits/bits-stdc++.h>
using namespace std;
class Phanso
{
private:
	int tu;
	int mau;
	int gcd(int a, int b);
public:
	Phanso();
	Phanso(int hoang, int tung);
	void rutgon();

	Phanso operator +(const Phanso& P)const;
	Phanso operator -(const Phanso& P)const;
	Phanso operator *(const Phanso& P)const;
	Phanso operator / (const Phanso& P)const;

	//ham so sanh
	bool operator ==(const Phanso& P)const;
	bool operator !=(const Phanso& P)const;
	bool operator >=(const Phanso& P)const;
	bool operator <=(const Phanso& P)const;
	bool operator >(const Phanso& P)const;
	bool operator <(const Phanso& P)const;

	friend ostream& operator<<(ostream& out, const Phanso& P);
	friend istream& operator >> (istream& in,  Phanso &P);
};



