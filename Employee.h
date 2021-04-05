#pragma once

class Employee : public Payment
{
private:
	char* position;
	int* increase;

public:
	Employee()  //по умолчанию
	{
#ifdef DEBUG
		cout << "------Сработал конструктор по умолчанию(Employee)" << endl << endl;
#endif 
		position = new char[100];
		position[0] = '\0';
		increase = new int(0);
	};

	Employee(char* position, int* increase) // конструктор с параметрами
	{
#ifdef DEBUG
		cout << "------Сработал конструктор с параметрами (Employee)" << endl << endl;
#endif 

		this->position = new char[strlen(position) + 1];

		memcpy(this->position, position, strlen(position) + 1);

		this->increase = new int(*increase);

	}

	Employee(const Employee& Object)// конструктор копирования
	{
#ifdef DEBUG
		cout << "------Сработал конструктор копирования(Employee)" << endl << endl;
#endif 

		position = new char[strlen(Object.position) + 1];

		memcpy(this->position, Object.position, strlen(Object.position) + 1);

		increase = new int(*Object.increase);

	}

	~Employee()
	{
		delete[] this->position;
		delete this->increase;
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
	void ShowPaymentForMonth()
	{
		cout << "Зарпалата с надбавкой: " << PaymentForMonth() << endl << endl;
	}
	void ShowInfo()
	{
		Payment::ShowInfo();
		cout << endl << "Должность: " << position << endl << endl;
		cout << "Надбавка: " << *increase << endl << endl;
		ShowPaymentForMonth();
	}

	Employee& operator = (const Payment& Object)
	{
#ifdef DEBUG2
		cout << "------Сработал оператор присваивания" << endl << endl;
#endif 

		this-> Payment::Payment(Object);

		return *this;
	}
};
