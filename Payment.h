#pragma once
using namespace std;

bool checkdestr = true;

class Payment 
{
private:
	char* fio; // фио
	int* salary; // оклад за смену
	int* year; // год устройства на работу
	int* workday; // отработанных дней

public:
	static int ndfl;
	static int prs;

	Payment()  //по умолчанию
	{
#ifdef DEBUG
		cout << "------Сработал конструктор по умолчанию" << endl << endl;
#endif 
		fio = new char[100]; // фио
		fio[0] = '\0';
		salary = new int(0); // оклад за смену
		year = new int(0); // год устройства на работу
		workday = new int(0); // отработанных дней

	};

	Payment(char* fio, int* salary, int* year, int* workday) // конструктор с параметрами
	{
#ifdef DEBUG
		cout << "------Сработал конструктор с параметрами" << endl << endl;
#endif 

		this->fio = new char[strlen(fio) + 1]; // фио

		memcpy(this->fio, fio, strlen(fio) + 1);

		this->salary = new int(*salary); // оклад за смену

		this->year = new int(*year); // год устройства на работу

		this->workday = new int(*workday); // отработанных дней
	}

	Payment(const Payment& Object)// конструктор копирования
	{
#ifdef DEBUG
		cout << "------Сработал конструктор копирования" << endl << endl;
#endif 

		fio = new char[strlen(Object.fio) + 1];

		memcpy(this->fio, Object.fio, strlen(Object.fio) + 1);

		salary = new int(*Object.salary);

		year = new int(*Object.year);

		workday = new int(*Object.workday);
	}
	~Payment()
	{
#ifdef DEBUG
		cout << "-----Сработал деструктор" << endl;
#endif
		if (checkdestr)
		{
			delete[] this->fio;
			delete this->salary;
			delete this->year;
			delete this->workday;
		}
	}

	int returnworkday()
	{
		return *this->workday;
	}
	int PaymentForMonth()
	{
		int paymentformonth;
		paymentformonth = *(salary) * *(workday);

		return paymentformonth;
	}

	int Pension()
	{
		int pension;
		pension = PaymentForMonth() / prs;

		return pension;
	}

	int NDFL()
	{
		int nds;
		nds = PaymentForMonth() / prs * this->ndfl;

		return nds;
	}

	void ShowPaymentForMonth()
	{
		cout << endl << "Имя: " << fio << endl << endl;
		cout << "Зарплата за месяц: " << PaymentForMonth() << endl << endl;
	}
	void ShowPension()
	{
		cout << endl << "Имя: " << fio << endl << endl;
		cout << "Отчисления в пенсионный фонд: " << Pension() << endl << endl;
	}
	void ShowNDS()
	{
		cout << endl << "Имя: " << fio << endl << endl;
		cout << "Налог: " << NDFL() << endl << endl;
	}
	void Showfio()
	{
		cout << endl << "Имя: " << fio << endl << endl;
	}
	void ShowInfo()
	{
		cout << endl << "Имя: " << fio << endl << endl;
		cout << "Оклад за смену: " << *salary << endl << endl;
		cout << "Год поступления: " << *year << endl << endl;
		cout << "Отработанных дней: " << *workday << endl << endl;
		cout << "Зарплата за месяц: " << PaymentForMonth() << endl << endl;
		cout << "Отчисления в пенсионный фонд: " << Pension() << endl << endl;
		cout << "Налог: " << NDFL() << endl << endl;
	}
	void ShowInfo(int i)
	{
		cout << endl << "Имя: " << fio << endl << endl;
		cout << "Оклад за смену: " << *salary << endl << endl;
		cout << "Год поступления: " << *year << endl << endl;
		cout << "Отработанных дней: " << *workday << endl << endl;
	}

	void setfio(char* fio)
	{
		this->fio = new char[strlen(fio) + 1];
		memcpy(this->fio, fio, strlen(fio) + 1);
	}
	void setsalary(int* salary)
	{
		*(this->salary) = *salary;
	}
	void setyear(int* year)
	{
		*(this->year) = *year;
	}
	void setworkday(int* workday)
	{
		*(this->workday) = *workday;
	}


	// ----------------------------------Лаба 2----------------------------------

	Payment& operator = (const Payment& Object)
	{
#ifdef DEBUG2
		cout << "------Сработал оператор присваивания" << endl << endl;
#endif 
		this->~Payment();

		fio = new char[strlen(Object.fio) + 1];

		memcpy(this->fio, Object.fio, strlen(Object.fio) + 1);

		salary = new int(*Object.salary);

		year = new int(*Object.year);

		workday = new int(*Object.workday);

		return *this;
	}
	void operator + (int raise_salary)
	{
#ifdef DEBUG2
		cout << "------Сработал оператор сложения" << endl << endl;
#endif 
		* salary = *salary + raise_salary;
	}
	void operator - (int raise_salary)
	{
#ifdef DEBUG2
		cout << "------Сработал оператор вычитания" << endl << endl;
#endif 
		* salary = *salary - raise_salary;
	}
	void operator ++ (int val)  //*если принимает значение - постфиксная форма, если не принимает - префиксная
	{
#ifdef DEBUG2
		cout << "------Сработал оператор инкремента" << endl << endl;
#endif 
		* year = *year + 1;
	}
	void operator -- (int val)
	{
#ifdef DEBUG2
		cout << "------Сработал оператор декремента" << endl << endl;
#endif
		* year = *year - 1;
	}
	void operator () ()
	{
#ifdef DEBUG2
		cout << "------Сработал оператор функиции" << endl << endl;
#endif
		Foo(*this);
	}

	friend void Foo(Payment& Object);

	// ----------------------------------Лаба 3----------------------------------

	friend ostream& operator << (ostream& os, Payment& Object);

	friend istream& operator >> (istream& is, Payment& Object);

	friend ofstream& operator << (ofstream& ofs, Payment& Object);

	friend ifstream& operator >> (ifstream& ifs, Payment& Object);

	friend void ToFile(Payment& worker);

	friend void FromFile(Payment& worker);
};

ostream& operator << (ostream& os, Payment& Object)
{
	os << "Имя: " << Object.fio << endl
		<< "Год устройства: " << *Object.year << endl
		<< "Отработанных дней: " << *Object.workday << endl
		<< "Оклад за смену: " << *Object.salary << endl;
	return os;
}

istream& operator >> (istream& is, Payment& Object)
{
	cout << "Введите имя " << endl;
	char A[100] = "";
	is.ignore();
	is.getline(A, 100);
	Object.setfio(A);

	cout << "Введите оплату за смену " << endl;
	is >> *Object.salary;

	cout << "Введите год " << endl;
	is >> *Object.year;

	cout << "Введите отработанные дни " << endl;
	is >> *Object.workday;

	return is;
}
ofstream& operator << (ofstream& ofs, Payment& Object)
{
	ofs << Object.fio << endl
		<< *Object.year << endl
		<< *Object.workday << endl
	    << *Object.salary << endl;

	return ofs;
}
ifstream& operator >> (ifstream& ifs, Payment& Object)
{
	char A[100] = "";
	ifs.getline(A, 100);
	Object.setfio(A);
	ifs >> *Object.salary;
	ifs >> *Object.year;
	ifs >> *Object.workday;

	return ifs;
}

void ToFile(Payment& worker)
{ 
		ofstream emp_file("employee.dat");
		int qweqrdg = sizeof(Payment);
		emp_file.write((char*)&worker, sizeof(Payment)); 
}

void FromFile(Payment& worker)
{
	ifstream emp_file("employee.dat");
	emp_file.read((char*)&worker, sizeof(Payment));
	worker.ShowInfo();

}
