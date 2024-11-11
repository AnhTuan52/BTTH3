#pragma once
#include<iostream>
using namespace std;
class lich
{
private:
	int ngay, thang, nam;
	bool lanamnhuan(int nam) const;
	int so_ngay_trong_thang(int thang, int nam) const;
public:
	lich();
	lich(int ngay, int thang, int nam);
	int tinhngay() const;
	lich operator +(int ngay);
	lich operator -(int ngay);

	int operator -( const lich& n) const;
	lich operator ++(int);
	lich operator--(int);

	bool operator==(const lich& n) const;
	bool operator!=(const lich& n) const;
	bool operator>=(const lich& n) const;
	bool operator<=(const lich& n) const;
	bool operator > (const lich& n) const;
	bool operator < (const lich& n) const;

	friend ostream& operator <<(ostream& out, const lich& n);
	friend istream& operator>>(istream& in, lich& n);


};

