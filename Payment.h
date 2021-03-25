#pragma once
#include <iostream>
//#define DEBUG

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
	static int nds;
	static int prs;

	Payment()  //по умолчанию
	{
#ifdef DEBUG
		cout << "------Сработал конструктор по умолчанию" << endl << endl;
#endif 

		fio = new char[1]; // фио
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

	int NDS()
	{
		int nds;
		nds = PaymentForMonth() / prs * this->nds;

		return nds;
	}

	void ShowPaymentForMonth()
	{
		cout << "Имя: " << fio << endl << endl;
		cout << "Зарплата за месяц: " << PaymentForMonth() << endl << endl;
	}
	void ShowPension()
	{
		cout << "Имя: " << fio << endl << endl;
		cout << "Отчисления в пенсионный фонд: " << Pension() << endl << endl;
	}
	void ShowNDS()
	{
		cout << "Имя: " << fio << endl << endl;
		cout << "Налог: " << NDS() << endl << endl;
	}
	void ShowInfo()
	{
		cout << "Имя: " << fio << endl << endl;
		cout << "Год поступления: " << *year << endl << endl;
		cout << "Зарплата за месяц: " << PaymentForMonth() << endl << endl;
		cout << "Отчисления в пенсионный фонд: " << Pension() << endl << endl;
		cout << "Налог: " << NDS() << endl << endl;
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

};


