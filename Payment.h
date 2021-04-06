#pragma once
using namespace std;

bool checkdestr = true;

class Payment
{
private:
	char* fio; // ���
	int* salary; // ����� �� �����
	int* year; // ��� ���������� �� ������
	int* workday; // ������������ ����

public:
	static int ndfl;
	static int prs;

	Payment()  //�� ���������
	{
#ifdef DEBUG
		cout << "------�������� ����������� �� ���������" << endl << endl;
#endif 
		fio = new char[100]; // ���
		fio[0] = '\0';
		salary = new int(0); // ����� �� �����
		year = new int(0); // ��� ���������� �� ������
		workday = new int(0); // ������������ ����

	};

	Payment(char* fio, int* salary, int* year, int* workday) // ����������� � �����������
	{
#ifdef DEBUG
		cout << "------�������� ����������� � �����������" << endl << endl;
#endif 

		this->fio = new char[strlen(fio) + 1]; // ���

		memcpy(this->fio, fio, strlen(fio) + 1);

		this->salary = new int(*salary); // ����� �� �����

		this->year = new int(*year); // ��� ���������� �� ������

		this->workday = new int(*workday); // ������������ ����
	}

	Payment(const Payment& Object)// ����������� �����������
	{
#ifdef DEBUG
		cout << "------�������� ����������� �����������" << endl << endl;
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
		cout << "-----�������� ����������" << endl;
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
		cout << endl << "���: " << fio << endl << endl;
		cout << "�������� �� �����: " << PaymentForMonth() << endl << endl;
	}
	void ShowPension()
	{
		cout << endl << "���: " << fio << endl << endl;
		cout << "���������� � ���������� ����: " << Pension() << endl << endl;
	}
	void ShowNDS()
	{
		cout << endl << "���: " << fio << endl << endl;
		cout << "�����: " << NDFL() << endl << endl;
	}
	void ShowInfo()
	{
		cout << endl << "���: " << fio << endl << endl;
		cout << "����� �� �����: " << *salary << endl << endl;
		cout << "��� �����������: " << *year << endl << endl;
		cout << "������������ ����: " << *workday << endl << endl;
		cout << "�������� �� �����: " << PaymentForMonth() << endl << endl;
		cout << "���������� � ���������� ����: " << Pension() << endl << endl;
		cout << "�����: " << NDFL() << endl << endl;
	}
	void ShowInfo(int i)
	{
		cout << endl << "���: " << fio << endl << endl;
		cout << "����� �� �����: " << *salary << endl << endl;
		cout << "��� �����������: " << *year << endl << endl;
		cout << "������������ ����: " << *workday << endl << endl;
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


	// ----------------------------------���� 2----------------------------------

	Payment& operator = (const Payment& Object)
	{
#ifdef DEBUG2
		cout << "------�������� �������� ������������" << endl << endl;
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
		cout << "------�������� �������� ��������" << endl << endl;
#endif 
		* salary = *salary + raise_salary;
	}
	void operator - (int raise_salary)
	{
#ifdef DEBUG2
		cout << "------�������� �������� ���������" << endl << endl;
#endif 
		* salary = *salary - raise_salary;
	}
	void operator ++ (int val)  //*���� ��������� �������� - ����������� �����, ���� �� ��������� - ����������
	{
#ifdef DEBUG2
		cout << "------�������� �������� ����������" << endl << endl;
#endif 
		* year = *year + 1;
	}
	void operator -- (int val)
	{
#ifdef DEBUG2
		cout << "------�������� �������� ����������" << endl << endl;
#endif
		* year = *year - 1;
	}
	void operator () ()
	{
#ifdef DEBUG2
		cout << "------�������� �������� ��������" << endl << endl;
#endif
		Foo(*this);
	}

	friend void Foo(Payment& Object);

	// ----------------------------------���� 3----------------------------------

	friend ostream& operator << (ostream& os, Payment& Object);

	friend istream& operator >> (istream& is, Payment& Object);

	friend ofstream& operator << (ofstream& ofs, Payment& Object);

	friend ifstream& operator >> (ifstream& ifs, Payment& Object);

	friend void ToFile(Payment& worker);

	friend void FromFile(Payment& worker);
};

ostream& operator << (ostream& os, Payment& Object)
{
	os << "���: " << Object.fio << endl
		<< "��� ����������: " << *Object.year << endl
		<< "������������ ����: " << *Object.workday << endl
		<< "����� �� �����: " << *Object.salary << endl;
	return os;
}

istream& operator >> (istream& is, Payment& Object)
{
	cout << "������� ��� " << endl;
	char A[100] = "";
	is.ignore();
	is.getline(A, 100);
	Object.setfio(A);

	cout << "������� ������ �� ����� " << endl;
	is >> *Object.salary;

	cout << "������� ��� " << endl;
	is >> *Object.year;

	cout << "������� ������������ ��� " << endl;
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
