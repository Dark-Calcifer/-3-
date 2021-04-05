#pragma once

class Employee : public Payment
{
private:
	char* position;
	int* increase;

public:
	Employee()  //�� ���������
	{
#ifdef DEBUG
		cout << "------�������� ����������� �� ���������(Employee)" << endl << endl;
#endif 
		position = new char[100];
		position[0] = '\0';
		increase = new int(0);
	};

	Employee(char* position, int* increase) // ����������� � �����������
	{
#ifdef DEBUG
		cout << "------�������� ����������� � ����������� (Employee)" << endl << endl;
#endif 

		this->position = new char[strlen(position) + 1];

		memcpy(this->position, position, strlen(position) + 1);

		this->increase = new int(*increase);

	}

	Employee(const Employee& Object)// ����������� �����������
	{
#ifdef DEBUG
		cout << "------�������� ����������� �����������(Employee)" << endl << endl;
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
		cout << "��������� � ���������: " << PaymentForMonth() << endl << endl;
	}
	void ShowInfo()
	{
		Payment::ShowInfo();
		cout << endl << "���������: " << position << endl << endl;
		cout << "��������: " << *increase << endl << endl;
		ShowPaymentForMonth();
	}
};
