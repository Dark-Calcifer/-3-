#pragma once

class Employee : public Payment
{
private:
	char* position;
	int* increase;

public:
	Employee()  //�� ���������
	{
#ifdef DEBUG3
		cout << "------�������� ����������� �� ���������(Employee)" << endl << endl;
#endif 
		position = new char[100];
		position[0] = '\0';
		increase = new int(0);
	};

	Employee(char* position, int* increase) // ����������� � �����������
	{
#ifdef DEBUG3
		cout << "------�������� ����������� � ����������� (Employee)" << endl << endl;
#endif 

		this->position = new char[strlen(position) + 1];

		memcpy(this->position, position, strlen(position) + 1);

		this->increase = new int(*increase);

	}

	Employee(const Employee& Object)// ����������� �����������
	{
#ifdef DEBUG3
		cout << "------�������� ����������� �����������(Employee)" << endl << endl;
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
			cout << "------�������� ���������� (Employee)" << endl << endl;
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
		cout << "��������� � ���������: " << PaymentForMonth() << endl;
	}
	void ShowInfo()
	{
		Payment::ShowInfo(0);
		ShowPaymentForMonth();
		cout << "���������� � ���������� ����: " << Pension() << endl << endl;
		cout << "�����: " << NDFL() << endl << endl;
		cout << "���������: " << position << endl << endl;
		cout << "��������: " << *increase << endl << endl;

	}

	Employee& operator = (const Payment& Object)
	{
#ifdef DEBUG3
		cout << "------�������� �������� ������������ (Employee)" << endl << endl;
#endif 

		this-> Payment::Payment(Object);

		return *this;
	}
};
