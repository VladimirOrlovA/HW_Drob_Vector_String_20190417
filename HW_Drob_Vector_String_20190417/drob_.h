#pragma once
#include <iostream>
using namespace std;

class drob_
{
	int x, y;
public:

	// конструктор с параметрами
	drob_(int x = 0, int y = 1);

	// конструктор копирования
	drob_(const drob_&o);

	//setters
	void setX(int x);
	void setY(int y);

	//getters
	int getX() const;
	int getY() const;

	// методы
	void print() const;	// константный метод
	double getFraction()const;	// константный метод

	// методы операций над дробями
	drob_ operator+=(const drob_ & b);
	drob_ operator-=(const drob_ & b);
	drob_ operator*=(const drob_ & b);
	drob_ operator/=(const drob_ & b);
	drob_ & operator++();
	drob_ operator++(int);
	drob_ & operator--();
	drob_ operator--(int);
	
};

// объявление глобальных функций операций над дробями
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
