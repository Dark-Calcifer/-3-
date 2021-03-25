// ������������ ������ 1 (3 �������)

#include "Payment.h"
#include <iostream>
#include <vector>

using namespace std;

int Payment::nds = 13;
int Payment::prs = 100;

int main()
{
	setlocale(LC_ALL, "Russian");
	int choose = 0;
	bool a = true;
	vector<Payment>payvec;
	while (a)
	{
		cout << "\t�������� ����� " << endl << endl;
		cout << "1) ������ ������ ���������� " << endl;
		cout << "2) ���������� �������� " << endl;
		cout << "3) ���������� ����� " << endl;
		cout << "4) ���������� ������ " << endl;
		cout << "5) �������� ���������� � ���������� " << endl;
		cout << "6) ������� ����������" << endl << endl;
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