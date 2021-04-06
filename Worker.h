#pragma once

class Worker : public Payment
{
private:
	char* profession;
	int* salaryperhour;
	int* hourpermonth;

public:
	Worker()  //по умолчанию
	{
#ifdef DEBUG3
		cout << "------Сработал конструктор по умолчанию(Worker)" << endl << endl;
#endif 
		profession = new char[100];
		profession[0] = '\0';
		salaryperhour = new int(0);
		hourpermonth = new int(0);
	};

	Worker(char* profession, int* salaryperhour, int* hourpermonth) // конструктор с параметрами
	{
#ifdef DEBUG3
		cout << "------Сработал конструктор с параметрами (Worker)" << endl << endl;
#endif 

		this->profession = new char[strlen(profession) + 1];

		memcpy(this->profession, profession, strlen(profession) + 1);

		this->salaryperhour = new int(*salaryperhour);
		this->hourpermonth = new int(*hourpermonth);

	}

	Worker(const Worker& Object)// конструктор копирования
	{
#ifdef DEBUG3
		cout << "------Сработал конструктор копирования (Worker)" << endl << endl;
#endif 

		profession = new char[strlen(Object.profession) + 1];

		memcpy(this->profession, Object.profession, strlen(Object.profession) + 1);

		salaryperhour = new int(*Object.salaryperhour);
		hourpermonth = new int(*Object.hourpermonth);

	}

	~Worker()
	{
#ifdef DEBUG3
		cout << "------Сработал деструктор (Worker)" << endl << endl;
#endif
		delete[] this->profession;
		delete this->salaryperhour;
		delete this->hourpermonth;
	}

	void setprofession(char* profession)
	{
		this->profession = new char[strlen(profession) + 1];
		memcpy(this->profession, profession, strlen(profession) + 1);
	}
	void setsalaryperhour(int* salaryperhour)
	{
		*(this->salaryperhour) = *salaryperhour;
	}
	void sethourpermonth(int* hourpermonth)
	{
		*(this->hourpermonth) = *hourpermonth;
	}

	int PaymentForMonth()
	{
		int paymentformonth;
		paymentformonth = *(salaryperhour) * *(hourpermonth);

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
		cout << endl << "Должность: " << profession << endl << endl;
		cout << "Зарплата за месяц: " << PaymentForMonth() << endl << endl;
	}
	void ShowInfo()
	{
		Payment::ShowInfo(0);
		ShowPaymentForMonth();
		cout << "Зарплата за час: " << *salaryperhour << endl << endl;
		cout << "Часов в месяц: " << *hourpermonth << endl << endl;
		cout << "Отчисления в пенсионный фонд: " << Pension() << endl << endl;
		cout << "Налог: " << NDFL() << endl << endl;
	}
	Worker& operator = (const Payment& Object)
	{
#ifdef DEBUG3
		cout << "------Сработал оператор присваивания(Worker)" << endl << endl;
#endif 

		this->Payment::Payment(Object);

		return *this;
	}
};
