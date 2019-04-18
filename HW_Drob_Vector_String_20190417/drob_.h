#pragma once
#include <iostream>
using namespace std;

class drob_
{
	int x, y;
public:

	// ����������� � �����������
	drob_(int x = 0, int y = 1);

	// ����������� �����������
	drob_(const drob_&o);

	//setters
	void setX(int x);
	void setY(int y);

	//getters
	int getX() const;
	int getY() const;

	// ������
	void print() const;	// ����������� �����
	double getFraction()const;	// ����������� �����

	// ������ �������� ��� �������
	drob_ operator+=(const drob_ & b);
	drob_ operator-=(const drob_ & b);
	drob_ operator*=(const drob_ & b);
	drob_ operator/=(const drob_ & b);
	drob_ & operator++();
	drob_ operator++(int);
	drob_ & operator--();
	drob_ operator--(int);
	
};

// ���������� ���������� ������� �������� ��� �������
drob_ operator+(const drob_& a, const drob_& b);
drob_ operator-(const drob_& a, const drob_& b);
drob_ operator*(const drob_& a, const drob_& b);
drob_ operator/(const drob_& a, const drob_& b);
bool operator==(const drob_& a, const drob_& b);
bool operator!=(const drob_& a, const drob_& b);
bool operator>(const drob_& a, const drob_& b);
bool operator<(const drob_& a, const drob_& b);
bool operator>=(const drob_& a, const drob_& b);
bool operator<=(const drob_& a, const drob_& b);
ostream& operator<<(ostream &os, const drob_ &c);
istream& operator>>(istream &is, drob_ &c);
