#pragma once

class Employee : public Payment
{
private:
	char* position;
	int* increase;

public:
	Employee()  //по умолчанию
	{
#ifdef DEBUG3
		cout << "------Сработал конструктор по умолчанию(Employee)" << endl << endl;
#endif 
		position = new char[100];
		position[0] = '\0';
		increase = new int(0);
	};

	Employee(char* position, int* increase) // конструктор с параметрами
	{
#ifdef DEBUG3
		cout << "------Сработал конструктор с параметрами (Employee)" << endl << endl;
#endif 

		this->position = new char[strlen(position) + 1];

		memcpy(this->position, position, strlen(position) + 1);

		this->increase = new int(*increase);

	}

	Employee(const Employee& Object)// конструктор копирования
	{
#ifdef DEBUG3
		cout << "------Сработал конструктор копирования(Employee)" << endl << endl;
#endif 

		position = new char[strlen(Object.position) + 1];

		memcpy(this->position, Object.position, strlen(Object.position) + 1);

		increase = new int(*Object.increase);

	}

	~Employee()
	{
		if (checkdestr)
		{
#ifdef DEBUG3
			cout << "------Сработал деструктор (Employee)" << endl << endl;
#endif
			delete[] this->position;
			delete this->increase;
		}
	}


	void setposition(char* position)
	{
		this->position = new char[strlen(position) + 1];
		memcpy(this->position, position, strlen(position) + 1);
	}
	void setincrease(int* increase)
	{
		*(this->increase) = *increase;
	}
	int PaymentForMonth()
	{
		int paymentformonth;
		paymentformonth = Payment::PaymentForMonth() + *(increase);
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
		nds = PaymentForMonth() / prs * ndfl;

		return nds;
	}
	void ShowPaymentForMonth()
	{
		cout << "Зарпалата с надбавкой: " << PaymentForMonth() << endl;
	}
	void ShowInfo()
	{
		Payment::ShowInfo(0);
		ShowPaymentForMonth();
		cout << "Отчисления в пенсионный фонд: " << Pension() << endl << endl;
		cout << "Налог: " << NDFL() << endl << endl;
		cout << "Должность: " << position << endl << endl;
		cout << "Надбавка: " << *increase << endl << endl;

	}

	void ShowInfo(int i)
	{
		cout << "Должность: " << position << endl << endl;
		cout << "Надбавка: " << *increase << endl << endl;
		cout << "Отчисления в пенсионный фонд: " << Pension() << endl << endl;
		cout << "Налог: " << NDFL() << endl << endl;
	}

	Employee& operator = (const Payment& Object)
	{
#ifdef DEBUG3
		cout << "------Сработал оператор присваивания (Employee)" << endl << endl;
#endif 

		this-> Payment::Payment(Object);

		return *this;
	}
};
