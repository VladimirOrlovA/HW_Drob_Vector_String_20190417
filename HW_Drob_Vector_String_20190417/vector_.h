#pragma once
#include<iostream>
using namespace std;

class vector_
{
	int size;
	int *arr;
public:
	vector_();
	vector_(int size, int val = 0);
	vector_(const vector_ & obj);
	void push_back(int num);
	void pop_back();
	void erase(int pos);
	void clear();
	int getSize() const;
	bool empty();
	int getElement(int pos) const;
	void setElement();
	void print();
	
	// методы операций над дроб€ми
	//vector_ operator+=(const vector_ &b);
	//vector_ operator-=(const vector_ & b);
	//vector_ operator*=(const vector_ & b);
	//vector_ operator/=(const vector_ & b);
	vector_ & operator++();
	vector_ operator++(int);
	friend bool operator==(const vector_ & L, const vector_ & R);
	~vector_();
};

// объ€вление глобальных функций операций над массивами
ostream& operator<<(ostream &os, const vector_ &c);
istream& operator>>(istream &is, vector_ &c);
bool operator==(const vector_ & L, const vector_ & R);