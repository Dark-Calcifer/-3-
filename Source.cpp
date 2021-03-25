// ������������ ������ 3 (3 �������)

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif  // ��� ������ ������������ ������� ("������������!"_s)

#include <iostream>
#include <vector>
#include "Payment.h"

using namespace std;

int Payment::ndfl = 13;
int Payment::prs = 100;

int main()
{
	setlocale(LC_ALL, "Russian");
	int check_pause = false;
	int choose = 0;
	bool a = true;
	vector<Payment>payvec;

	while (a)
	{
		if (check_pause)
		{
			system("pause");
			system("cls");
		}
		check_pause = false;

		cout << "\t�������� ����� " << endl << endl;
		cout << "1) ������ ������ ���������� " << endl;
		cout << "2) ���������� �������� " << endl;
		cout << "3) ���������� ����� " << endl;
		cout << "4) ���������� ������ " << endl;
		cout << "5) �������� ���������� � ���������� " << endl;
		cout << "6) ������� ����������" << endl << endl;
		cout << "7) ���������� �����������" << endl;
		cout << "8) �������� �����" << endl;
		cout << "9) �������� ��� �����������" << endl;
		cout << "10) ��������� �������� � ������� ���������" << endl << endl;
		cout << "11) �������� � ����" << endl;
		cout << "0) �����\n";
		cin >> choose;
		cout << endl;

		switch (choose)
		{
		case 1: // ������ ������ ����������
		{
			Payment Person;

			char A[100] = "";
			int temp, temp1, temp2;

			cout << "������� ��� " << endl;

			cin.ignore();
			cin.getline(A, 100);
			Person.setfio(A);

			cout << "������� ������ �� ����� " << endl;
			cin >> temp;
			Person.setsalary(&temp);

			cout << "������� ��� " << endl;
			cin >> temp1;
			Person.setyear(&temp1);

			cout << "������� ������������ ��� " << endl;
			cin >> temp2;
			Person.setworkday(&temp2);

			payvec.push_back(Person);
			break;
		}
		case 2: // ���������� ��������
		{
			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker == 0)
			{
				for (unsigned int i = 0; i < payvec.size(); i++)
				{
					payvec[i].ShowPaymentForMonth();
				}
			}
			else payvec[NumOfWorker - 1].ShowPaymentForMonth();
			check_pause = true;
			break;
		}
		case 3:  // ���������� �����
		{
			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker == 0)
			{
				for (unsigned int i = 0; i < payvec.size(); i++)
				{
					payvec[i].ShowNDS();
				}
			}
			else payvec[NumOfWorker - 1].ShowNDS();
			check_pause = true;
			break;
		}
		case 4:  // ���������� ������
		{
			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker == 0)
			{
				for (unsigned int i = 0; i < payvec.size(); i++)
				{
					payvec[i].ShowPension();
				}
			}
			else payvec[NumOfWorker - 1].ShowPension();
			check_pause = true;
			break;
		}
		case 5:  // �������� ���������� � ����������
		{
			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker == 0)
			{
				for (unsigned int i = 0; i < payvec.size(); i++)
				{
					payvec[i].ShowInfo();
				}
			}
			else payvec[NumOfWorker - 1].ShowInfo();
			check_pause = true;
			break;
		}
		case 6: // ������� ����������
		{
			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker == 0)
			{
				for (unsigned int i = 0; i < payvec.size(); i++)
				{
					checkdestr = true;
					(payvec.begin() + i)->~Payment();
					checkdestr = false;
				}
				payvec.clear();
			}
			else
			{
				checkdestr = true;
				(payvec.begin() + NumOfWorker - 1)->~Payment();
				checkdestr = false;
				payvec.erase(payvec.begin() + NumOfWorker - 1);
			}
			checkdestr = true;
			break;
		}
		case(7): //���� ��������� ������������
		{
			int NumOfWorker;
			int NumOfWorker1;
			cout << "������� ����� ��������� �������� ����� ����������" << endl;
			cin >> NumOfWorker;
			cout << "������� ����� ��������� � �������� ����� ����������" << endl;
			cin >> NumOfWorker1;
			/*cout << "\t1�� (��): " << endl; payvec[NumOfWorker - 1].ShowInfo();
			cout << "\t2�� (��): " << endl; payvec[NumOfWorker1 - 1].ShowInfo();*/

			payvec[NumOfWorker - 1] = payvec[NumOfWorker1 - 1];

			/*cout << "\t1�� (�����): " << endl; payvec[NumOfWorker - 1].ShowInfo();
			cout << "\t2�� (�����): " << endl; payvec[NumOfWorker1 - 1].ShowInfo();*/
			break;
		}
		case(8): // �������� �����
		{
			int NumOfWorker = 0;
			int change_salary = 0;
			int check = 0;
			cout << "������� ����� ��������� " << endl;
			cin >> NumOfWorker;
			cout << "�������(1) / ���������(2)" << endl;
			cin >> check;
			cout << "���������? " << endl;
			cin >> change_salary;
			if (check == 1)
			{
				payvec[NumOfWorker - 1] + change_salary;
			}
			if (check == 2)
			{
				payvec[NumOfWorker - 1] - change_salary;
			}

			break;
		}
		case(9): // �������� ��� �����������
		{
			int NumOfWorker = 0;
			int check = 0;
			cout << "������� ����� ��������� " << endl;
			cin >> NumOfWorker;
			cout << "���������(1) / ���������(2)" << endl;
			cin >> check;
			if (check == 1)
			{
				payvec[NumOfWorker - 1]++;
			}
			if (check == 2)
			{
				payvec[NumOfWorker - 1]--;
			}

			break;
		}
		case(10): // ���������� �� � ������� ���������
		{
			int NumOfWorker;
			cout << "������� ����� ���������" << endl;
			cin >> NumOfWorker;
			payvec[NumOfWorker - 1]();
			check_pause = true;

			break;
		}
		case(11):
		{
			int NumOfWorker;
			cout << "������� ����� ���������" << endl;
			cin >> NumOfWorker;
			cout << payvec[NumOfWorker - 1] << endl;
			break;
		}
		case 0: // �����
		{
			a = false;
			break;
		}
		default:
			cout << "��������� ����" << endl;
			break;
		}

	}
}

void Foo(Payment& Object) // ���������� �������� � ������� ���� ���������
{
	int result = 0;
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	i1 = Object.PaymentForMonth();
	i2 = Object.Pension();
	i3 = Object.NDFL();
	result = i1 + i2 + i3;
	cout << i1 - (i2 + i3) << endl << endl;
}

ostream& operator << (ostream& os, Payment& Object)
{
	os << "���: " << Object.fio << endl
		<< "��� ����������: " << *Object.year << endl
		<< "������������ ����: " << *Object.workday << endl
		<< "����� �� �����: " << *Object.salary << endl;
	return os;
}