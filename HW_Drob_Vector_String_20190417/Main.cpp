#include"drob_.h"
#include"string_.h"
#include"vector_.h"
#include<locale>


void main()
{
	setlocale(LC_ALL, "RUS");
	
	/*drob_ dr(3, 4);
	dr.print();

	string_ str("Hello World");
	str.print();

	vector_ vec1(3, 5);
	vector_ vec2(2, 5);

	string_ str1 ("Hello");
	string_ str2 ("Hell");

	cout << dr;
	cin >> dr;
	cout << dr;

	vec++;
	vec.print();

	vector_ a;
	cin >> vec;
	cout << vec;

	cout << vec1;
	cin >> vec2;

	cout << vec1 << vec2;
	
	if (vec1 == vec2)
		cout << "Arrays are equal\n";
	else cout << "Arrays are not equal\n";*/

	/*string_ c("Hello");
	cout << "Source string : " << c;
	cin >> c;
	cout << "String after change: " << c << endl;*/

	//str1.push_back('z');
	//str1.print();

	//string_ copy(str2);
	//copy.print();

	/*if (str1 == str2)
		cout << "Strings are equal\n";
	else cout << "Strings are not equal\n";*/

	/*if (str1 != str2)
		cout << "True Strings are not equal\n";
	else cout << "False Strings are equal\n";*/

	//string_ s(5,'q');
	//cout << s;
	/*string_ s;*/
	//s = 's';
	//cout << s << endl;

	string_ s1 ("Привет"); // длина строки Hello - 5 символов Привет - 6
	string_ s2(" World!");

	s1 += s2;
	s1 += " test";
	cout << s1 << endl;
	
	s1 = " test 2";
	cout << s1 << endl;
	//cout << s1.getSize() << endl;
	//string_ *pstr = &s1;

	//cout << "Object string_ s1 - " << sizeof(s1) << "\t Object string_ *pstr - " << sizeof(*pstr) << endl;

	//size_t char_size = sizeof(char);

	//cout << "Current char size "<<char_size << endl;

	//cout << s1 << endl;
	//cout << "Size of string_ s1 -> " << s1.getSize() <<" bytes"<< endl;

	/*if (s1.empty())
		cout << "\n -= String empty =- \n";
	else
		cout << "\n -= String not empty =- \n";*/

	system("pause");
}