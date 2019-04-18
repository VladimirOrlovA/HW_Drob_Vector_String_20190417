#include "string_.h"

// ����������� �� ���������
string_::string_()
{
	cout << "constructor default" << endl;
	str = nullptr;
	length = 0;
}

// ����������� � ����������
string_::string_(const char *s)
{
	cout << "constructor with parameter" << endl;
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
}

//����� - ����� ���������� ������ � n-�� �������� ������ n ��������
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

//����� - ����� ���������� ������ �� �������� ����� (��������)
string_::string_(const char * s, size_t n)
{
	this->str = new char[n + 1];
	strcpy_s(this->str, n + 1, s);
	this->length = n;
}

// ����� - ������ � ������ n ��������� �������� ��������� - ���������� ������
string_::string_(size_t n, char c)
{
	this->str = new char[n + 1];
	for (size_t i = 0; i < n; i++)
		this->str[i] = c;
	this->str[n] = '\0';
	this->length = n;
}

// ����������� ����������� �� ������� � ����������� ������
string_::string_(const string_ & obj)
{
	this->length = obj.length;
	// �������� �� ������� ����������� ������ ������
	if (this->length == 0)
	{
		this->str = nullptr;
		return;
	}
	//������ ���� ������ ����������
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str); // strcpy_s - ��� ��������� � ����� ������ \0
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

// ����� - ���������� ��������� ������������ 
string_ & string_::operator=(const char * s)
{
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
	return *this;
}

// ����� - ���������� ��������� ������������ ������� string_ �������� ���������� char
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
	strcpy_s(tmp, length + 1, this->str);
	strcat_s(tmp, length + 1, str.str);
	delete[] this->str;
	this->str = tmp;
	return *this;
}

string_ & string_::operator+=(const char * s)
{
	this->length += strlen(s);
	char *tmp = new char[this->length + 1];
	strcpy_s(tmp, length + 1, this->str);
	strcat_s(tmp, length + 1, s);
	delete[] this->str;
	this->str = tmp;
	return *this;
}

// ������ ��� ������
void string_::setString(const char *s)
{
	if (str != nullptr) delete[] str;	// ���� ������ �� ������ ������� ������ (������ char)
	length = strlen(s);					// ������������� ����� ���������� ������
	str = new char[length + 1];			// �������� ��� ��������� ����� ���������� ������
	strcpy_s(str, length + 1, s);		// ������������� � ������ ���������� ����� ���������� ������ +1 ������ ��� \0 � ���� ������ ��������
}

// ������ ��� ������
const char *string_::getString() const
{
	return str;
}

// ������ ��� ����� ������
int string_::getLength() const
{
	return length;
}

// ����� append
void string_::append(const char *s)
{
	if (str == nullptr) {
		setString(s);
		return;
	}
	length += strlen(s);				// ���������� � ������� ����� ������ ����� ������ ���������
	char* tmp = new char[length + 1];	// ��������� ��������� ��� ��������� ������
	strcpy_s(tmp, length + 1, str);		// ����������� ������ str �� ��������� ������ tmp
	strcat_s(tmp, length + 1, s);		// �� ��������� ������ �������� ������ �������� s
	delete[]str;
	str = tmp;
}


// ����� ������ � �������
void string_::print() const
{
	cout << str << endl;
}

// ����� clear
void string_::clear()
{
	this->~string_();
}

// ����� ��������� ����� 
bool string_::equal(const char * s) const
{
	if (strcmp(str, s) == 0)  // strcmp - ������� ���������� ������� ���� �����, string1 � string2.
		return true;
	return false;
}

// ����� puch_back - ������� ������� � ����� ������
void string_::push_back(char z)
{
	length += 1;
	char *tmp = new char[length + 1];
	strcpy_s(tmp, length + 1, str);
	tmp[length - 1] = z;
	tmp[length] = '\0';
	delete[] str;
	str = tmp;
}


// ����������
string_::~string_()
{
	delete[] this->str;
	this->length = 0;
	this->str = nullptr;
}



// ��. �. - ���������� ��������� ������ << ��� ���� ������ string_
ostream & operator<<(ostream & os, const string_ & c)
{
	if (c.str == nullptr)
	{
		cout << " is empty \n";
		return os;
	}
		os << c.str;
		return os;
}

// ��. �. ���������� ��������� ����� >> ��� ���� ������ string_
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



// ��. �. ���������� ��������� ��������� ��� ���� ������ string_
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

// ��. �. ���������� ��������� ��������� �� �� ��������� ��� ���� ������ string_
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

