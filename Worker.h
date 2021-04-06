#pragma once

class Worker : public Payment
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
#ifdef DEBUG3
		cout << "------�������� ���������� (Worker)" << endl << endl;
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
		cout << endl << "���������: " << profession << endl << endl;
		cout << "�������� �� �����: " << PaymentForMonth() << endl << endl;
	}
	void ShowInfo()
	{
		Payment::ShowInfo(0);
		ShowPaymentForMonth();
		cout << "�������� �� ���: " << *salaryperhour << endl << endl;
		cout << "����� � �����: " << *hourpermonth << endl << endl;
		cout << "���������� � ���������� ����: " << Pension() << endl << endl;
		cout << "�����: " << NDFL() << endl << endl;
	}
	Worker& operator = (const Payment& Object)
	{
#ifdef DEBUG3
		cout << "------�������� �������� ������������(Worker)" << endl << endl;
#endif 

		this->Payment::Payment(Object);

		return *this;
	}
};
