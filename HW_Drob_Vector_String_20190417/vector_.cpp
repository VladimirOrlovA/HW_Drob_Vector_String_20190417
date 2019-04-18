#include "vector_.h"


vector_::vector_()	// конструктор по умолчанию
{
	this->size = 0;			// размер 0
	this->arr = nullptr;	// указатель на массив 0
}

vector_::vector_(int size, int val)
{
	this->size = size;
	this->arr = new int[this->size];
	for (int i = 0; i < this->size; i++)
		this->arr[i] = val;
}

vector_::vector_(const vector_ & obj)		// конструктор копирования
{
	this->size = obj.size;
	if (this->size == 0)
		this->arr = nullptr;
	else
	{
		this->arr = new int[this->size];
		for (int i = 0; i < this->size; i++)
			this->arr[i] = obj.arr[i];
	}
}

void vector_::push_back(int num)	// добавление в конец массива  одного элемента
{
	if (this->size == 0)
	{
		this->arr = new int[1];
		this->arr[0] = num;
		this->size++;
		return;
	}
	int *tmp = new int[this->size + 1];

	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i] = this->arr[i];
	}
	tmp[this->size] = num;
	delete[]this->arr;
	this->arr = tmp;
	this->size++;

}

void vector_::pop_back()  // удаление последнего элемента
{
	if (this->size == 0)
	{
		cout << "Array is empty!";
	}
	else
	{
		int *tmp = new int[this->size - 1];
		for (size_t i = 0; i < this->size - 1; i++)
		{
			tmp[i] = this->arr[i];
		}
		delete[]this->arr;
		this->arr = tmp;
		this->size--;
	}

}

void vector_::erase(int pos)	//удаление элемента под индексом pos
{
	if (this->size == 0)
	{
		cout << "Array is empty!";
	}
	else
	{
		int *tmp = new int[this->size];

		int j = 0;
		for (size_t i = 0; i < this->size; i++)
		{
			if (i == pos)
			{
				tmp[i] = this->arr[i + 1];
				i++;
			}
			tmp[j] = this->arr[i];
			j++;
		}
		delete[] this->arr;
		this->arr = tmp;
		this->size--;
	}
}

void vector_::clear()
{
	if (this->arr != nullptr)
	{
		delete[] this->arr;
		this->arr = nullptr;
		this->size = 0;
	}
}


int vector_::getSize() const
{
	//cout << "Array size is " << this->size << "\n\n";
	return this->size;
}

bool vector_::empty()
{
	if (this->arr == nullptr)
		return true;
	return false;
}

int vector_::getElement(int pos) const		// метод получения заданного значения элемента в массиве
{
	if (pos > this->size)
	{
		cout << "Wrong input" << endl;
		return 0;
	}
	else
	{
		//cout << "Getting the value of a given element position: pos " << pos << " = value " << this->arr[pos] << "\n\n";
		return this->arr[pos];
	}

}

// сеттер 
void vector_::setElement()
{
	if (this->arr == nullptr)
	{
		cout << "\nThis array is clear \n\n";
		cout << "Set a new array size -> ";
		cin >> this->size;
		this->arr = new int[this->size];

		for (size_t i = 0; i < this->size; i++)
		{
			cout << "\nEnter " << i << " element -> ";
			cin >> this->arr[i];
		}
		cout << " - All array elements values are set -  \n";
	}
	else
	{
		cout << "\nThis array size is " << this->size << " elements \n\n";
		
		cout << "\nDo You want to rezize the array? 1/0 -> ";
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			cout << "Set new array size -> ";
			cin >> this->size;
			delete[] this->arr;
			this->arr = new int[this->size];
		}

		for (size_t i = 0; i < this->size; i++)
		{
			cout << "\nEnter new value of " << i << " element -> ";
			cin >> this->arr[i];
		}
		cout << "\n - All array elements values are set - \n";
	}
}

void vector_::print()
{
	if (this->arr == nullptr)
		cout << "Array is empty!\n";
	else
	{

		for (size_t i = 0; i < this->size; i++)
		{
			cout << this->arr[i] << " ";

		}
	}
	cout << endl;
}

// метод - prefix incriment
vector_ & vector_::operator++()
{
	for (size_t i = 0; i < this->size; i++)
	{
		this->arr[i]++;
	}
	return *this;
}

// метод - postfix incriment
vector_ vector_::operator++(int)
{
	vector_ c = *this;
	for (size_t i = 0; i < size; i++)
	{
		this->arr[i] += 1;
	}
	return c;
}

vector_::~vector_()
{
	if (this->arr != nullptr) {
		delete[]this->arr;
		this->size = 0;
	}
}

// гл.функция оператора вывода "<<" для типа данных vector_ 
ostream & operator<<(ostream & os, const vector_ & vec)
{
	cout << "\n";
	for (size_t i = 0; i < vec.getSize(); i++)
	{
		os << vec.getElement(i);
	}
	cout << "\n\n";
	return os;
}

// гл.функция оператора ввода ">>" для типа данных vector_ 
istream & operator>>(istream & is, vector_ & vec)
{
	vec.setElement();
	return is;
}

bool operator==(const vector_ & L, const vector_ & R)
{
	if (L.size != R.size)
		return false;

	for (size_t i = 0; i < L.size; i++)
		{
			if (L.arr[i] != R.arr[i])
				return false;
		}

	return true;
}
