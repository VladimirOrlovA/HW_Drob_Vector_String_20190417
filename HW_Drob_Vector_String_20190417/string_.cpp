#include "string_.h"

// конструктор по умолчанию
string_::string_()
{
	cout << "constructor default" << endl;
	str = nullptr;
	length = 0;
}

// конструктор с параметром
string_::string_(const char *s)
{
	cout << "constructor with parameter" << endl;
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
}

//Метод - вывод переданной строки с n-го элемента строки n символов
string_::string_(const string_ & str, size_t pos, size_t len)
{
	if (len == 0 || str.str == nullptr)
	{
		this->str = nullptr;
		this->length = 0;
		return;
	}
	this->str = new char[len + 1];
	this->length = len;
	for (size_t i = pos; (i < pos + len); i++)//2+2+1
		this->str[i - pos] = str.str[i];

	this->str[len] = '\0';
}

//Метод - вывод переданной строки до заданной длины (элемента)
string_::string_(const char * s, size_t n)
{
	this->str = new char[n + 1];
	strcpy_s(this->str, n + 1, s);
	this->length = n;
}

// Метод - создает строку, состоящую из n символов c
string_::string_(size_t n, char c)
{
	this->str = new char[n + 1];
	for (size_t i = 0; i < n; i++)
		this->str[i] = c;
	this->str[n] = '\0';
	this->length = n;
}

// конструктор копирования из объекта в назначенный объект
string_::string_(const string_ & obj)
{
	this->length = obj.length;
	// проверка на попытку копирования пустой строки
	if (this->length == 0)
	{
		this->str = nullptr;
		return;
	}
	//значит есть откуда копировать
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str); // strcpy_s - сам добавляет в конец сторки \0
}


string_ & string_::operator=(const string_ & str)
{
	if (this == &str)
	{
		return *this;
	}
	if (str.str == nullptr)
	{
		delete[]this->str;
		this->length = 0;
		this->str = nullptr;
		return *this;
	}
	if (this->length != str.length)
	{
		delete[]this->str;
		this->str = new char[str.length + 1];
		this->length = str.length;
	}
	strcpy_s(this->str, str.length + 1, str.str);
	return *this;
}

// метод - перегрузка оператора присваивания 
string_ & string_::operator=(const char * s)
{
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
	return *this;
}

// метод - перегрузка оператора присваивания объекту string_ значение переменной char
string_ & string_::operator=(char c)
{
	if (this->str != nullptr)
		clear();

	length = 1;
	this->str = new char[2];
	this->str[0]=c;
	this->str[1] = '\0';
	return *this;
}

string_ & string_::operator+=(const string_ & str)
{
	if (this->str == nullptr) 
	{
		this->str = new char[str.length];
		this->length = str.length;
		strcpy_s(this->str, this->length + 1, str.str);
		return *this;
	}
	
	this->length += str.length;
	char *tmp = new char[this->length + 1];
	strcpy_s(tmp, this->length + 1, this->str);
	strcat_s(tmp, this->length + 1, str.str);
	delete[] this->str;
	this->str = tmp;
	return *this;
}

string_ & string_::operator+=(const char * s)
{
	if (this->str == nullptr)
	{
		this->str = new char[strlen(s)+1];
		this->length = strlen(s);
		strcpy_s(this->str, this->length + 1, s);
		return *this;
	}

	this->length += strlen(s);
	char *tmp = new char[this->length + 1];
	strcpy_s(tmp, length + 1, this->str);
	strcat_s(tmp, length + 1, s);
	delete[] this->str;
	this->str = tmp;
	return *this;
}

// сеттер для строки
void string_::setString(const char *s)
{
	if (str != nullptr) delete[] str;	// если строка не пустая удаляем строку (массив char)
	length = strlen(s);					// устанавливаем длину переданной строки
	str = new char[length + 1];			// выделяем под указатель длину переданной строки
	strcpy_s(str, length + 1, s);		// устанавливаем в строку назначения длину переданной строки +1 символ для \0 и саму строку источник
}

// геттер для строки
const char *string_::getString() const
{
	return str;
}

// геттер для длины строки
int string_::getLength() const
{
	return this->length;
}

int string_::getSize() const
{
	if (this->str == nullptr)
		return 0;
		
	size_t char_size = sizeof(char); // выясняем размер char в текущей системе
	int size = (strlen(this->str)+1)*char_size;
	return size;
}

// метод append
void string_::append(const char *s)
{
	if (str == nullptr) {
		setString(s);
		return;
	}
	length += strlen(s);				// прибавляем к текущей длине строки длину строки источника
	char* tmp = new char[length + 1];	// объявляем указатель для временной строки
	strcpy_s(tmp, length + 1, str);		// копирование строки str во временную строку tmp
	strcat_s(tmp, length + 1, s);		// во временную строку передаем строку источник s
	delete[]str;
	str = tmp;
}


// вывод строки в консоль
void string_::print() const
{
	cout << str << endl;
}

// метод clear
void string_::clear()
{
	this->~string_();
}

// метод сравнения строк 
bool string_::equal(const char * s) const
{
	if (strcmp(str, s) == 0)  // strcmp - функция сравнивает символы двух строк, string1 и string2.
		return true;
	return false;
}

// метод puch_back - вставка символа в конец строки
void string_::push_back(const char z)
{
	if (this->str == nullptr)
	{
		this->length = 1;
		this->str = new char[this->length + 1];
		str[length-1] = z;
		str[length] = '\0';
		return;
	}

	this->length += 1;
	char *tmp = new char[this->length + 1];
	strcpy_s(tmp, this->length + 1, str);
	tmp[this->length - 1] = z;
	tmp[this->length] = '\0';
	delete[] str;
	str = tmp;
}

bool string_::empty() const
{
	if (this->str == nullptr)
		return true;
	return false;
}


// деструктор
string_::~string_()
{
	cout << "destructor" << endl;
	delete[] this->str;
	this->length = 0;
	this->str = nullptr;
}



// гл. ф. - перегрузка оператора вывода << для типа данных string_
ostream & operator<<(ostream & os, const string_ & c)
{
	if (c.str == nullptr)
	{
		cout << "str is empty \n";
		return os;
	}
		os << c.str;
		return os;
}

// гл. ф. перегрузка оператора ввода >> для типа данных string_
istream & operator>>(istream & is, string_ & c)
{
	cout << "\nEnter string: ";
	char s[1024];
	cin >> s;
	c.clear();
	c.str = new char[strlen(s) + 1];
	c.length = strlen(s);
	strcpy_s(c.str, c.length + 1, s);
	return is;
}



// гл. ф. перегрузка оператора сравнения для типа данных string_
bool operator==(string_ & L, string_ & R)
{
	if (L.length != R.length)
		return false;
	
	for (size_t i = 0; i < L.length; i++)
		{
		if (L.str[i] != R.str[i])
			return false;
		}
	
	return true;

}

// гл. ф. перегрузка оператора сравнения на не равенство для типа данных string_
bool operator!=(string_ & L, string_ & R)
{
	if (L.length != R.length)
		return true;

	for (size_t i = 0; i < L.length; i++)
	{
		if (L.str[i] != R.str[i])
			return true;
	}

	return false;
}

