#include "drob_.h"


// конструктор с параметрами
drob_::drob_(int x, int y)
{
	this->setX(x);
	this->setY(y);
}

// конструктор копирования
drob_::drob_(const drob_ & o)
{
	this->x = o.x;
	this->y = o.y;
}

// сеттер для параметра x
void drob_::setX(int x)
{
	this->x = x;
}

// сеттер для параметра y
void drob_::setY(int y)
{
	if (y != 0)
		this->y = y;
	else
		this->y = 1;
}

// геттер для параметра x, константный, чтобы исключить изменение параметра x
int drob_::getX() const
{
	return x;
}

// геттер для параметра y, константный, чтобы исключить изменение параметра y
int drob_::getY() const
{
	return y;
}

// метод вывода дроби в консоль, константный
void drob_::print() const
{
	cout << x << " / " << y << " = "
		<< double(x) / y << endl;
}

// метод возвращения дроби ввиде десятичной дроби в консоль, константный
double drob_::getFraction() const
{
	return double(this->x) / this->y;
}

// метод - "+" дробей
drob_ drob_::operator+=(const drob_ & b)
{
	this->x = this->x*b.y + this->y*b.x;
	this->y = this->y * b.y;
	return *this;
}

// метод - "-" дробей
drob_ drob_::operator-=(const drob_ & b)
{
	if (this->y == b.y)
	{
		this->x = this->x - b.x;
		return *this;
	}
	else
	{
		int comDenom = this->y*b.y;
		this->x = this->x*(comDenom / this->y) - b.x*(comDenom / b.y);
		this->y = comDenom;
		return *this;
	}
}

// метод - "*" дробей
drob_ drob_::operator*=(const drob_ & b)
{
	this->x = this->x*b.x;
	this->y = this->y*b.y;
	return *this;
}

// метод - "/" дробей
drob_ drob_::operator/=(const drob_ & b)
{
	this->x = this->x*b.y;
	this->y = this->y*b.x;
	return *this;
}

// метод - prefix incriment
drob_ & drob_::operator++()
{
	this->x += this->y;
	return *this;
}

// метод - postfix incriment
drob_ drob_::operator++(int)
{
	drob_ c = *this;
	this->x += this->y;
	return c;
}

// метод - prefix decriment
drob_ & drob_::operator--()
{
	this->x -= this->y;
	return *this;
}

// метод - postfix decriment
drob_ drob_::operator--(int)
{
	drob_ c = *this;
	this->x -= this->y;
	return c;
}

// глобальная функция оператора "+" для типа данных drob_
drob_ operator+(const drob_ & a, const drob_ & b)
{
	drob_ c = a;
	c += b;
	//drob_ c;
	//c.setX(a.getY()*b.getX() + a.getX()*b.getY());
	//c.setY(a.getY()*b.getY());

	return c;
}

// гл.функция оператора "-" для типа данных drob_
drob_ operator-(const drob_ & a, const drob_ & b)
{
	drob_ c = a;
	c -= b;
	return c;
}

// гл.функция оператора "*" для типа данных drob_
drob_ operator*(const drob_ & a, const drob_ & b)
{
	drob_ c = a;
	c *= b;
	return c;
}

// гл.функция оператора "/" для типа данных drob_
drob_ operator/(const drob_ & a, const drob_ & b)
{
	drob_ c = a;
	c /= b;
	return c;
}


bool operator==(const drob_ & a, const drob_ & b)
{
	return a.getFraction() == b.getFraction();
}

bool operator!=(const drob_ & a, const drob_ & b)
{
	return a.getFraction() != b.getFraction();
}

bool operator>(const drob_ & a, const drob_ & b)
{
	return a.getFraction() > b.getFraction();
}

bool operator<(const drob_ & a, const drob_ & b)
{
	return a.getFraction() < b.getFraction();
}

bool operator>=(const drob_ & a, const drob_ & b)
{
	return a.getFraction() >= b.getFraction();
}

bool operator<=(const drob_ & a, const drob_ & b)
{
	return a.getFraction() <= b.getFraction();
}

// гл.функция оператора вывода "<<" для типа данных drob_ 
ostream & operator<<(ostream & os, const drob_ & c)
{
	
	os << c.getX();
	cout << "/";
	os << c.getY();
	cout << "\n\n";
	return os;
}

// гл.функция оператора ввода ">>" для типа данных drob_
istream & operator>>(istream & is, drob_ & c)
{
	cout << "\n ";
	int x, y;
	cout << "\nEnter value numerator -> ";
	cin >> x;
	cout << "\t /";
	c.setX(x);
	cout << "\nEnter value denumerator -> ";
	cin >> y;
	c.setY(y);
	cout << "\n";

	return is;
}
