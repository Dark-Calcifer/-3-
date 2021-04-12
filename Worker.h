#pragma once

bool check123 = true;

class Worker : public Employee
{
private:
	char* profession;
	int* salaryperhour;
	int* hourpermonth;

public:
	Worker()  //�� ���������
	{
#ifdef DEBUG3
		cout << "------�������� ����������� �� ���������(Worker)" << endl << endl;
#endif 
		profession = new char[100];
		profession[0] = '\0';
		salaryperhour = new int(0);
		hourpermonth = new int(0);
	};

	Worker(char* profession, int* salaryperhour, int* hourpermonth) // ����������� � �����������
	{
#ifdef DEBUG3
		cout << "------�������� ����������� � ����������� (Worker)" << endl << endl;
#endif 

		this->profession = new char[strlen(profession) + 1];

		memcpy(this->profession, profession, strlen(profession) + 1);

		this->salaryperhour = new int(*salaryperhour);
		this->hourpermonth = new int(*hourpermonth);

	}

	Worker(const Worker& Object)// ����������� �����������
	{
#ifdef DEBUG3
		cout << "------�������� ����������� ����������� (Worker)" << endl << endl;
#endif 
		profession = new char[strlen(Object.profession) + 1];

		memcpy(this->profession, Object.profession, strlen(Object.profession) + 1);

		salaryperhour = new int(*Object.salaryperhour);
		hourpermonth = new int(*Object.hourpermonth);

	}

	~Worker()
	{
		if (checkdestr && check123)
		{
#ifdef DEBUG3
			cout << "------�������� ���������� (Worker)" << endl << endl;
#endif
			delete[] this->profession;
			delete this->salaryperhour;
			delete this->hourpermonth;
		}
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
		//cout << endl << "���������: " << profession << endl << endl;
		cout << "�������� �� �����: " << PaymentForMonth() << endl << endl;
	}
	void ShowInfo()
	{
		Payment::ShowInfo(0);
		cout << endl << "���������: " << profession << endl << endl;
		ShowPaymentForMonth();
		cout << "�������� �� ���: " << *salaryperhour << endl << endl;
		cout << "����� � �����: " << *hourpermonth << endl << endl;
		cout << "���������� � ���������� ����: " << Pension() << endl << endl;
		cout << "�����: " << NDFL() << endl << endl;
	}
	int ShowInfo(int i)
	{
		if (i == 1)
		{
			Payment::ShowInfo(0);
			return 0;
		}
		else if (i == 2)
		{
			Payment::ShowInfo(0);
			Employee::ShowInfo(0);
			Employee::ShowPaymentForMonth();
			cout << endl;
			return 0;
		}
		else if (i == 3)
		{
			Payment::ShowInfo(0);
			ShowInfo(0);
			return 0;
		}
		else if (i == 0)
		{
			cout << "���������: " << profession << endl << endl;
			cout << "�������� �� ���: " << *salaryperhour << endl << endl;
			cout << "����� � �����: " << *hourpermonth << endl << endl;
			ShowPaymentForMonth();
			cout << endl;
			return 0;
		}
		else
		{
			return 0;
		}
		return 0;
	}
	Worker& operator = (const Payment& Object)
	{
#ifdef DEBUG3
		cout << "------�������� �������� ������������(Worker)" << endl << endl;
#endif 

		this->Payment::Payment(Object);

		return *this;
	}

	Worker& operator = (const Worker& Object)
	{
#ifdef DEBUG3
		cout << "------�������� �������� ������������(Worker = Worker)" << endl << endl;
#endif 
		this->Employee::Employee(Object);
		this->Payment::Payment(Object);
		int i = 0;
		while (Object.profession[i] != '\0')
		{
			this->profession[i] = Object.profession[i];
			i++;
		}
		this->profession[i] = '\0';
		*this->salaryperhour = *Object.salaryperhour;
		*this->hourpermonth = *Object.hourpermonth;

		return *this;
	}
};
