#pragma once
#include<iostream>
using namespace std;

class string_
{
	char *str;
	int length;
public:
	string_();
	string_(const char*s);
	string_(const string_ & str, size_t pos, size_t len);
	string_(const char * s, size_t n);
	string_(size_t n, char c); 
	string_(const string_&obj);
	string_& operator= (const string_ & str);
	string_& operator= (const char* s);
	string_& operator= (char c);

	string_& operator+= (const string_& str);
	string_& operator+= (const char* s);

	void setString(const char*s);
	const char* getString() const;
	int getLength() const;
	void append(const char*s);
	
	
	void print() const;
	void clear();
	bool equal(const char*s) const;
	void push_back(char z);
	
	~string_();
	
	
	// объ€вление дружественных функции
	friend ostream& operator<<(ostream &os, const string_ &c);
	friend istream& operator>>(istream &is, string_ &c);
	friend bool operator==(string_ & L, string_ & R);
	friend bool operator!=(string_ & L, string_ & R);
};

// объ€вление глобальных функций операций над строками
ostream& operator<<(ostream &os, const string_ &c);
istream& operator>>(istream &is, string_ &c);

bool operator==(string_ & L, string_ & R);
bool operator!=(string_ & L, string_ & R);