// ������������ ������ 7 (3 �������)

// ���������, ���������� ��7 ���������� � "#define Lab7" �� 48 �������. 
// ��� ����������, ��� ���������� (����� ��5) � �������� ����� Deque ��� ���������, ����� �� ������� � ����� 
// ����� ������, ������� ����� ���������������� ��������� ������ ������ �� ��������

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif  // ��� ������ ������������ ������� ("������������"!_s)

//#define DEBUG
//#define DEBUG2
//#define DEBUG3
//#define OldLab
//#define Lab6
#define Lab7

#define P Worker

#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include <Windows.h>
#include "Exception.h"
#include "MemException.h"
#include "OutOfRangeEx.h"
#include "Payment.h"
#include "Employee.h"
#include "Worker.h"
#include "Deque.h"

using namespace std;

int Payment::ndfl = 13;
int Payment::prs = 100;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int check_pause = false;
	int choose = 0;
	bool a = true;
	vector<Payment>payvec;
	Deque<P>paydeq;
	Deque<int>intdeq;

#ifdef Lab7

	bool check19 = true;
	bool check_pause19 = false;
	int PersonCounter[100] = { '\0' };
	bool IsItInt(char const* A1);
	void PrintEx();
	int MaxMem = 1000;
	while (check19)
	{
		if (check_pause19)
		{
			system("pause");
			system("cls");
			check_pause19 = false;
		}
		cout << "���������� �������� � ����: " << paydeq.size() << endl << endl;
		cout << "1) �������� ���������� " << endl;
		cout << "2) �������� ���������� � ���������� " << endl;
		cout << "3) ������� ����������" << endl;
		cout << "4) �������� � ��� �����(int) " << endl;
		cout << "5) �������� ��� ����� " << endl << endl;
		cout << "0) �����\n";
		int choose19;
		cin >> choose19;
		if (choose19 > 5 || choose19 < 0)
		{
			cout << "������ � ����� ������� ���, ���������� ��� ���" << endl << endl;
			check_pause19 = true;
			continue;
		}
		cout << endl;

		switch (choose19)
		{
		case 1: // ������ ������ ����������
		{
			P Person;
			char A[100] = "";
			int temp, temp1, temp2;

			// ------------------------------------���� ���
			cout << "������� ��� " << endl;
			cin.ignore();
			cin.getline(A, 100);
			Person.setfio(A);
			// ------------------------------------���� ������
			char A1[100] = "";
			cout << "������� ������ �� ����� " << endl;
			cin.getline(A1, 100);
			try
			{
				if (IsItInt(A1))
				{
					Exception ex("��������� �������� �� �������� ������");
					throw ex;
					break;
				}
				else
				{
					temp = atoi(A1);
					Person.setsalary(&temp);
				}
			}
			catch (Exception ex)
			{
				PrintEx();
				cout << ex.GetDescription() << endl;
				check_pause19 = true;
				break;
			}
			// ------------------------------------���� ����
			char A2[100] = "";
			cout << "������� ��� " << endl;
			cin.getline(A2, 100);
			try
			{
				if (IsItInt(A2))
				{
					Exception ex("��������� �������� �� �������� ������");
					throw ex;
					break;
				}

				else
				{
					temp1 = atoi(A2);
					Person.setyear(&temp1);
				}
			}
			catch (Exception ex)
			{
				PrintEx();
				cout << ex.GetDescription() << endl;
				check_pause19 = true;
				break;
			}
			// ------------------------------------���� ����
			char A3[100] = "";
			cout << "������� ������������ ��� " << endl;
			cin.getline(A3, 100);
			try
			{
				if (IsItInt(A3))
				{
					Exception ex("��������� �������� �� �������� ������");
					throw ex;
					break;
				}

				else
				{
					temp2 = atoi(A3);
					Person.setworkday(&temp2);
				}
			}
			catch (Exception ex)
			{
				PrintEx();
				cout << ex.GetDescription() << endl;
				check_pause19 = true;
				break;
			}
			// ------------------------------------���� r
			cout << "���������������� ��� Payment (1) / Employee(2) / Worker(3)? " << endl;
			char A4[100] = "";
			cin.getline(A4, 100);
			int r;
			r = atoi(A4);
			if (r == 1) {}
			else if (r == 2)
			{
				int increase = 100;
				char A1[100] = "";
				cout << "������� ��������� ���������� " << endl;
				cin.ignore();
				cin.getline(A1, 100);
				Person.setposition(A1);
				cout << "�������� 100 �� ���������* " << endl;
				Person.setincrease(&increase);
			}
			else if (r == 3)
			{
				int a2 = 9 * temp2;
				int a1 = 1000;
				char A1[100] = "";
				cout << "������� ��������� ��������� " << endl;
				cin.ignore();
				cin.getline(A1, 100);
				Person.setprofession(A1);
				cout << "��/� = 1000 �� ��������� " << endl;
				Person.setsalaryperhour(&a1);
				cout << "����� � ���� �� ��������� 9, ������� ���� � ������ � Payment" << endl;
				Person.sethourpermonth(&a2);
			}
			else
			{
				cout << "������� �������� �����." << endl;
				check_pause19 = true;
				continue;
			}
			paydeq.push_back(Person);
			PersonCounter[paydeq.size() - 1] = r;
			cout << "���������" << endl;
			check_pause19 = true;
			break;
		}
		case 2:  // �������� ���������� � ����������
		{
			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����)" << endl;
			cin >> NumOfWorker;
			try
			{
				if (NumOfWorker > paydeq.size() || NumOfWorker < 0)
				{
					OutOfRangeEx ex("������� ������ �� ������� ���������� ������", "paydeq[]");
					throw ex;
				}
				else if (NumOfWorker == 0)
				{
					for (unsigned int i = 0; i < paydeq.size(); i++)
					{
						paydeq[i].ShowInfo(PersonCounter[i]);
					}
				}
				else paydeq[NumOfWorker - 1].ShowInfo(PersonCounter[NumOfWorker - 1]);
				check_pause19 = true;
			}
			catch (OutOfRangeEx & ex)
			{
				PrintEx();
				cout << ex.GetDescription() << endl << "���������������� ";
				ex.ShowSpace();
				check_pause19 = true;
				break;
			}

			break;
		}
		case 3: // ������� ����������
		{
			int check;
			char D[100] = "";
			cout << "������� ������� (1)/ ������� ����������(2): " << endl;
			cin.getline(D, 100);
			try
			{
				if (IsItInt(D))
				{
					Exception ex("��������� �������� �� �������� ������");
					throw ex;
					break;
				}
				else
				{
					check = atoi(D);
				}
			}
			catch (Exception ex)
			{
				PrintEx();
				cout << ex.GetDescription() << endl;
				check_pause19 = true;
				break;
			}
			try {
				if (check == 1)
				{
					paydeq.pop_front();
					cout << "�������" << endl;
					for (int i = 0; i < paydeq.size(); i++)
					{
						PersonCounter[i] = PersonCounter[i + 1];
					}
					PersonCounter[paydeq.size()] = '\0';
					check_pause19 = true;
					break;
				}
				else if (check == 2)
				{
					paydeq.pop_back();
					cout << "�������" << endl;
					PersonCounter[paydeq.size()] = '\0';
					check_pause19 = true;
					break;
				}
				else
				{
					cout << "������� �������� �����" << endl;
					check_pause19 = true;
					break;
				}
			}
			catch(Exception ex) 
			{
				PrintEx();
				cout << ex.GetDescription() << endl;
				check_pause19 = true;
				break;
			}
			break;
		}		
		case 4:
		{
			int Num;
			char d[100] = "";
			cout << "������� �����: " << endl;
			cin.ignore();
			cin.getline(d, 100);
			try
			{
				if (IsItInt(d))
				{
					Exception ex("��������� �������� �� �������� ������");
					throw ex;
					break;
				}
				else
				{
					Num = atoi(d);
					intdeq.push_back(Num);
					cout << "����� ���������. " << endl;
					check_pause19 = true;
					break;
				}
			}
			catch (Exception ex)
			{
				PrintEx();
				cout << ex.GetDescription() << endl;
				check_pause19 = true;
				break;
			}

		}
		case 5:
		{

			int NumOfWorker;
			cout << "������� ����� ����� (0 - ����)" << endl;
			cin >> NumOfWorker;
			try
			{
				if (NumOfWorker > intdeq.size() || NumOfWorker < 0)
				{
					OutOfRangeEx ex("������� ������ �� ������� ���������� ������", "intdeq[]");
					throw ex;
				}
				else if (NumOfWorker == 0)
				{
					for (unsigned int i = 0; i < intdeq.size(); i++)
					{
						cout << intdeq[i] << endl;
					}
				}
				else cout << intdeq[NumOfWorker - 1] << endl;;
				check_pause19 = true;
			}
			catch (OutOfRangeEx & ex)
			{
				PrintEx();
				cout << ex.GetDescription() << endl << "���������������� ";
				ex.ShowSpace();
				check_pause19 = true;
				break;
			}

			break;

		}
		case 0:
		{
			check19 = false;
			break;
		}
		default:
			cout << "��������� ����" << endl;
			break;
		}
	}
#endif //Lab7 


#ifdef OldLab
	while (a)
	{
		if (check_pause)
		{
			system("pause");
			system("cls");
		}
		check_pause = false;
		checkdestr = true;
		choose = 0;
		cout << " ����������� �����������: " << payvec.size() << endl << endl;
		cout << "     �������� �����: " << endl << endl;

		cout << "\t(���� 1) " << endl;
		cout << "1) ������ ������ ���������� " << endl;
		cout << "2) ���������� �������� " << endl;
		cout << "3) ���������� ����� " << endl;
		cout << "4) ���������� ������ " << endl;
		cout << "5) �������� ���������� � ���������� " << endl;
		cout << "6) ������� ����������" << endl << endl;
		cout << "\t(���� 2) " << endl;
		cout << "7) ���������� �����������" << endl;
		cout << "8) �������� �����" << endl;
		cout << "9) �������� ��� �����������" << endl;
		cout << "10) ��������� �������� � ������� ���������" << endl << endl;
		cout << "\t(���� 3) " << endl;
		cout << "11) ��������� � �������� ����� / ����� � �����" << endl;
		cout << "12) �������� �� �������� ������ / ���� �� ������" << endl;
		cout << "13) �������� ������ � ��������� � ����" << endl;
		cout << "14) �������� ������ � ��������� �� �����" << endl;
		cout << "15) ������ � �������� ����" << endl;
		cout << "16) �������� �� ��������� �����" << endl << endl;
		cout << "\t(���� 4) " << endl;
		cout << "17) ������������ ������ \"Employee\"" << endl;
		cout << "18) ������������ ������ \"Worker\"" << endl << endl;
		cout << "\t(���� 4) " << endl;
		cout << "19) ������������ ������ ����" << endl;
		cout << "0) �����\n";
		cin >> choose;
		if (choose > 19 || choose < 0)
		{
			cout << "������ � ����� ������� ���, ���������� ��� ���" << endl << endl;
			check_pause = true;
			continue;
		}
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
			cout << "���������" << endl;
			check_pause = true;
			break;
		}
		case 2: // ���������� ��������
		{
			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
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
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
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
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
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
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			if (NumOfWorker == 0)
			{
				for (unsigned int i = 0; i < payvec.size(); i++)
				{
					payvec[i].ShowInfo(0);
				}
			}
			else payvec[NumOfWorker - 1].ShowInfo(0);
			check_pause = true;
			break;
		}
		case 6: // ������� ����������
		{
			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			if (NumOfWorker == 0)
			{
				for (unsigned int i = 0; i < payvec.size(); i++)
				{
					checkdestr = true;
					(payvec.begin() + i)->~Payment();
					checkdestr = false;
				}
				payvec.clear();
				cout << "�������" << endl;
				check_pause = true;
			}
			else
			{
				checkdestr = true;
				(payvec.begin() + NumOfWorker - 1)->~Payment();
				checkdestr = false;
				payvec.erase(payvec.begin() + NumOfWorker - 1);
				cout << "�������" << endl;
				check_pause = true;
			}
			checkdestr = true;
			break;
		}

		// ----------------------------------���� 2---------------------------------- 

		case(7): //���� ��������� ������������
		{
			int NumOfWorker;
			int NumOfWorker1;
			cout << "������� ����� ��������� �������� ����� ����������" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker <= 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			cout << "������� ����� ��������� � �������� ����� ����������" << endl;
			cin >> NumOfWorker1;
			if (NumOfWorker1 > payvec.size() || NumOfWorker1 <= 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			/*cout << "\t1�� (��): " << endl; payvec[NumOfWorker - 1].ShowInfo();
			cout << "\t2�� (��): " << endl; payvec[NumOfWorker1 - 1].ShowInfo();*/   // "�����"

			payvec[NumOfWorker - 1] = payvec[NumOfWorker1 - 1];
			cout << "���������" << endl;
			check_pause = true;

			/*cout << "\t1�� (�����): " << endl; payvec[NumOfWorker - 1].ShowInfo();
			cout << "\t2�� (�����): " << endl; payvec[NumOfWorker1 - 1].ShowInfo();*/
			break;
		}
		case(8): // �������� �����
		{
			int NumOfWorker;
			int unsigned change_salary;
			int check;
			cout << "������� ����� ��������� " << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			cout << "�������(1) / ���������(2)" << endl;
			cin >> check;
			cout << "���������? " << endl;
			cin >> change_salary;
			if (check == 1)
			{
				payvec[NumOfWorker - 1] + change_salary;
				cout << "���������" << endl;
				check_pause = true;
			}
			else if (check == 2)
			{
				payvec[NumOfWorker - 1] - change_salary;
				cout << "���������" << endl;
				check_pause = true;
			}
			else
			{
				cout << "������� �������� �����" << endl;
				check_pause = true;
				break;
			}

			break;
		}
		case(9): // �������� ��� �����������
		{
			int NumOfWorker = 0;
			int check = 0;
			cout << "������� ����� ��������� " << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			cout << "���������(1) / ���������(2)" << endl;
			cin >> check;
			if (check == 1)
			{
				payvec[NumOfWorker - 1]++;
				cout << "���������" << endl;
				check_pause = true;
			}
			else if (check == 2)
			{
				payvec[NumOfWorker - 1]--;
				cout << "���������" << endl;
				check_pause = true;
			}
			else
			{
				cout << "������� �������� �����" << endl;
				check_pause = true;
				break;
			}

			break;
		}
		case(10): // ���������� �� � ������� ���������
		{
			int NumOfWorker;
			cout << "������� ����� ���������" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker <= 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			payvec[NumOfWorker - 1]();
			check_pause = true;

			break;
		}

		// ----------------------------------���� 3----------------------------------

		case(11): // ��������� � �������� ����� / ����� � �����
		{
			int NumOfWorker;
			cout << "������� ����� ���������" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker <= 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			cout << payvec[NumOfWorker - 1] << endl;
			break;
		}
		case(12): // �������� �� �������� ������ / ���� �� ������
		{
			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����� ��������)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			if (NumOfWorker != 0)
			{
				cin >> payvec[NumOfWorker - 1];
				break;
			}
			if (NumOfWorker == 0)
			{
				Payment Person1;
				cin >> Person1;
				payvec.push_back(Person1);
				break;
			}
			break;
		}
		case(13): // �������� ������ � ��������� � ����
		{
			int NumOfWorker;
			cout << "������� ����� ���������" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker <= 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			cout << payvec[NumOfWorker - 1] << endl;
			ofstream ofs;
			ofs.open("MyFile.txt"/*, ofstream :: app*/);
			if (ofs.is_open())
			{
				ofs << payvec[NumOfWorker - 1];
				cout << "���������" << endl;
				check_pause = true;
			}
			else
			{
				cout << "���� �� ��� ������" << endl;
			}

			break;
		}
		case(14):
		{
			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����� ��������)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			ifstream ifs;
			ifs.open("MyFile.txt");
			if (NumOfWorker != 0)
			{
				if (ifs.is_open())
				{
					ifs >> payvec[NumOfWorker - 1];
					cout << "���������" << endl;
					check_pause = true;
				}
				else
				{
					cout << "���� �� ��� ������" << endl;
				}
				break;
			}
			if (NumOfWorker == 0)
			{
				Payment Person1;
				if (ifs.is_open())
				{
					ifs >> Person1;
					payvec.push_back(Person1);
					cout << "���������" << endl;
					check_pause = true;
				}
				else
				{
					cout << "���� �� ��� ������" << endl;
				}
				break;
			}
			break;
		}
		case(15): // ������ � �������� ����
		{
			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����� ��������)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			else
			{
				if (NumOfWorker == 0)
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
					//cout << "�������� = 100 " << endl;
					//temp = 100;
					Person.setsalary(&temp);

					cout << "������� ��� " << endl;
					cin >> temp1;
					/*cout << "��� = 100 " << endl;
					temp1 = 100;*/
					Person.setyear(&temp1);

					cout << "������� ������������ ��� " << endl;
					cin >> temp2;
					/*cout << "������������ ��� = 100 " << endl;
					temp2 = 100;*/
					Person.setworkday(&temp2);

					payvec.push_back(Person);
					//checkdestr = false;
					ToFile(payvec[payvec.size() - 1]);
					cout << "���������" << endl;
					check_pause = true;
					break;
				}
				else
				{
					//checkdestr = false;
					ToFile(payvec[NumOfWorker - 1]);
					cout << "���������" << endl;
					check_pause = true;
					break;
				}
				break;
			}
			break;
		}
		case(16): // �������� �� ��������� �����
		{
			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����� ��������)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			else
			{
				if (NumOfWorker == 0)
				{
					Payment worker;
					checkdestr = false;
					FromFile(worker);
					payvec.push_back(worker);
					cout << "���������" << endl;
					check_pause = true;
				}
				else
				{
					FromFile(payvec[NumOfWorker - 1]);
					cout << "���������" << endl;
					check_pause = true;
				}
				break;
			}
		}

		// ----------------------------------���� 4----------------------------------

		case 17: // ������������ ������ "Employee"
		{
			system("cls");
			Employee employee;
			int increase = 100;
			char A[100] = "";

			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����� ��������)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			else
			{
				if (NumOfWorker == 0)
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

					employee = Person;

					cout << "������� ��������� ���������� " << endl;
					cin.ignore();
					cin.getline(A, 100);
					employee.setposition(A);
					cout << "�������� 100 �� ���������* " << endl;
					employee.setincrease(&increase);
					//employee.ShowPaymentForMonth();
					employee.ShowInfo();
					payvec.push_back(employee);
					cout << "���������" << endl;
					check_pause = true;
				}
				else
				{
					employee = payvec[NumOfWorker - 1];
					cout << "������� ��������� " << endl;
					cin.ignore();
					cin.getline(A, 100);
					employee.setposition(A);
					cout << "�������� 100 �� ���������* " << endl;
					employee.setincrease(&increase);
					employee.setposition(A);
					//employee.ShowPaymentForMonth();
					employee.ShowInfo();
					cout << "���������" << endl;
					check_pause = true;
				}
				break;
			}
		}
		case 18: // ������������ ������ "Worker"
		{
			system("cls");
			Worker worker;
			char A[100] = "";
			int a1 = 1000;

			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����� ��������)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
				check_pause = true;
				break;
			}
			else
			{
				if (NumOfWorker == 0)
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

					worker = Person;
					int a2 = 9 * temp2;

					cout << "������� ��������� ��������� " << endl;
					cin.ignore();
					cin.getline(A, 100);
					worker.setprofession(A);
					cout << "��/� = 1000 �� ��������� " << endl;
					worker.setsalaryperhour(&a1);
					cout << "����� � ���� �� ��������� 9, ���� � ������ � Payment" << endl;
					worker.sethourpermonth(&a2);
					//worker.ShowPaymentForMonth();
					worker.ShowInfo();
					payvec.push_back(worker);
					cout << "���������" << endl;

					check_pause = true;
				}
				else
				{
					worker = payvec[NumOfWorker - 1];
					int a2 = 9 * payvec[NumOfWorker - 1].returnworkday();
					cout << "������� ��������� " << endl;
					cin.ignore();
					cin.getline(A, 100);
					worker.setprofession(A);
					cout << "��/� = 1000 �� ��������� " << endl;
					worker.setsalaryperhour(&a1);
					cout << "����� � ���� �� ��������� 9, ���� � ������ � Payment" << endl;
					worker.sethourpermonth(&a2);
					//worker.ShowPaymentForMonth();
					worker.ShowInfo();
					cout << "���������" << endl;
					check_pause = true;
				}
				break;
			}
		}

		// ----------------------------------���� 5----------------------------------

		case 19: // ������������ ������ ����
		{
			system("cls");
			bool check19 = true;
			bool check_pause19 = false;
			int PersonCounter[100] = { '\0' };
			while (check19)
			{
				if (check_pause19)
				{
					system("pause");
					system("cls");
					check_pause19 = false;
				}
				cout << "���������� �������� � ����: " << paydeq.size() << endl << endl;
				cout << "1) ������ ������ ���������� " << endl;
				cout << "2) �������� ���������� � ���������� " << endl;
				cout << "3) ������� ����������" << endl << endl;
				cout << "0) �����\n";
				int choose19;
				cin >> choose19;
				if (choose19 > 3 || choose19 < 0)
				{
					cout << "������ � ����� ������� ���, ���������� ��� ���" << endl << endl;
					check_pause19 = true;
					continue;
				}
				cout << endl;

				switch (choose19)
				{
				case 1: // ������ ������ ����������
				{
					Worker Person;

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

					cout << "���������������� ��� Payment (1) / Employee(2) / Worker(3)? " << endl;
					int r;
					cin >> r;

					if (r == 1) {}
					else if (r == 2)
					{
						int increase = 100;
						char A1[100] = "";
						cout << "������� ��������� ���������� " << endl;
						cin.ignore();
						cin.getline(A1, 100);
						Person.setposition(A1);
						cout << "�������� 100 �� ���������* " << endl;
						Person.setincrease(&increase);
					}
					else if (r == 3)
					{
						int a2 = 9 * temp2;
						int a1 = 1000;
						char A1[100] = "";
						cout << "������� ��������� ��������� " << endl;
						cin.ignore();
						cin.getline(A1, 100);
						Person.setprofession(A1);
						cout << "��/� = 1000 �� ��������� " << endl;
						Person.setsalaryperhour(&a1);
						cout << "����� � ���� �� ��������� 9, ���� � ������ � Payment" << endl;
						Person.sethourpermonth(&a2);
					}
					else
					{
						cout << "������� �������� �����." << endl;
						check_pause19 = true;
						continue;
					}
					paydeq.push_back(Person);
					PersonCounter[paydeq.size() - 1] = r;
					cout << "���������" << endl;
					check_pause19 = true;
					break;
				}
				case 2:  // �������� ���������� � ����������
				{
					int NumOfWorker;
					cout << "������� ����� ��������� (0 - ����)" << endl;
					cin >> NumOfWorker;
					if (NumOfWorker > paydeq.size() || NumOfWorker < 0)
					{
						cout << "��������� � ����� ������� ���, ���������� ��� ���" << endl;
						check_pause19 = true;
						break;
					}
					if (NumOfWorker == 0)
					{
						for (unsigned int i = 0; i < paydeq.size(); i++)
						{
							paydeq[i].ShowInfo(PersonCounter[i]);
						}
					}
					else paydeq[NumOfWorker - 1].ShowInfo(PersonCounter[NumOfWorker - 1]);
					check_pause19 = true;
					break;
				}
				case 3: // ������� ����������
				{
					int check;
					cout << "������� ������� (1)/ ������� ����������(2): " << endl;
					cin >> check;
					if (check == 1)
					{
						paydeq.pop_front();
						cout << "�������" << endl;
						for (int i = 0; i < paydeq.size(); i++)
						{
							PersonCounter[i] = PersonCounter[i + 1];
						}
						PersonCounter[paydeq.size()] = '\0';
						check_pause19 = true;
						break;
					}
					else if (check == 2)
					{
						paydeq.pop_back();
						cout << "�������" << endl;
						PersonCounter[paydeq.size()] = '\0';
						check_pause19 = true;
						break;
					}
					else
					{
						cout << "������� �������� �����" << endl;
						check_pause19 = true;
						break;
					}
					break;
				}
				case 0:
				{
					check19 = false;
					break;
				}
				default:
					cout << "��������� ����" << endl;
					break;
				}
			}
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
#endif // OldLab

	// ----------------------------------���� 6----------------------------------

#ifdef Lab6
	
	system("cls");
	bool check19 = true;
	bool check_pause19 = false;
	int PersonCounter[100] = { '\0' };
	bool IsItInt(char const* A1);
	void PrintEx();
	int deqsizefunc(Deque<Worker>& const paydeq);
	int MaxMem = 1000;
	while (check19)
	{
		if (check_pause19)
		{
			system("pause");
			system("cls");
			check_pause19 = false;
		}
		cout << "���������� ��������: " << paydeq.size() << " (������ ������: " << deqsizefunc(paydeq) << " �� " <<  MaxMem << ")" << endl << endl;
		cout << "1) �������� ���������� " << endl;
		cout << "2) �������� ���������� � ���������� " << endl;
		cout << "3) ������ ����� ������ ��� �������� ������� " << endl << endl;
		cout << "0) �����\n";
		int choose19;
		cin >> choose19;
		if (choose19 > 3 || choose19 < 0)
		{
			cout << "������ � ����� ������� ���, ���������� ��� ���" << endl << endl;
			check_pause19 = true;
			continue;
		}
		cout << endl;

		switch (choose19)
		{
		case 1: // ������ ������ ����������
		{
			try
			{
				if (deqsizefunc(paydeq) + 36 >= MaxMem)
				{
					MemException ex(1);
					throw ex;
				}
			}
			catch (MemException ex)
			{
				PrintEx();
				cout << ex.GetDescription() << " Code: " << ex.code() << endl;
				break;
			}
			Worker Person;

			char A[100] = "";
			int temp, temp1, temp2;

			// ------------------------------------���� ���
			cout << "������� ��� " << endl;
			cin.ignore();
			cin.getline(A, 100);
			Person.setfio(A);
			// ------------------------------------���� ������
			char A1[100] = "";
			cout << "������� ������ �� ����� " << endl;
			cin.getline(A1, 100);
			try
			{
				if (IsItInt(A1))
				{
					Exception ex("��������� �������� �� �������� ������");
					throw ex;
					break;
				}
				else
				{
					temp = atoi(A1);
					Person.setsalary(&temp);
				}
			}
			catch (Exception ex)
			{
				PrintEx();
				cout << ex.GetDescription() << endl;
				check_pause19 = true;
				break;
			}
			// ------------------------------------���� ����
			char A2[100] = "";
			cout << "������� ��� " << endl;
			cin.getline(A2, 100);
			try
			{
				if (IsItInt(A2))
				{
					Exception ex("��������� �������� �� �������� ������");
					throw ex;
					break;
				}

				else
				{
					temp1 = atoi(A2);
					Person.setyear(&temp1);
				}
			}
			catch (Exception ex)
			{
				PrintEx();
				cout << ex.GetDescription() << endl;
				check_pause19 = true;
				break;
			}
			// ------------------------------------���� ����
			char A3[100] = "";
			cout << "������� ������������ ��� " << endl;
			cin.getline(A3, 100);
			try
			{
				if (IsItInt(A3))
				{
					Exception ex("��������� �������� �� �������� ������");
					throw ex;
					break;
				}

				else
				{
					temp2 = atoi(A3);
					Person.setworkday(&temp2);
				}
			}
			catch (Exception ex)
			{
				PrintEx();
				cout << ex.GetDescription() << endl;
				check_pause19 = true;
				break;
			}
			// ------------------------------------���� r
			cout << "���������������� ��� Payment (1) / Employee(2) / Worker(3)? " << endl;
			char A4[100] = "";
			cin.getline(A4, 100);
			int r;
			r = atoi(A4);
			if (r == 1) {}
			else if (r == 2)
			{
				int increase = 100;
				char A1[100] = "";
				cout << "������� ��������� ���������� " << endl;
				cin.ignore();
				cin.getline(A1, 100);
				Person.setposition(A1);
				cout << "�������� 100 �� ���������* " << endl;
				Person.setincrease(&increase);
			}
			else if (r == 3)
			{
				int a2 = 9 * temp2;
				int a1 = 1000;
				char A1[100] = "";
				cout << "������� ��������� ��������� " << endl;
				cin.ignore();
				cin.getline(A1, 100);
				Person.setprofession(A1);
				cout << "��/� = 1000 �� ��������� " << endl;
				Person.setsalaryperhour(&a1);
				cout << "����� � ���� �� ��������� 9, ������� ���� � ������ � Payment" << endl;
				Person.sethourpermonth(&a2);
			}
			else
			{
				cout << "������� �������� �����." << endl;
				check_pause19 = true;
				continue;
			}
			paydeq.push_back(Person);
			PersonCounter[paydeq.size() - 1] = r;
			cout << "���������" << endl;
			check_pause19 = true;
			break;
		}

		case 2:  // �������� ���������� � ����������
		{
			int NumOfWorker;
			cout << "������� ����� ��������� (0 - ����)" << endl;
			cin >> NumOfWorker;
			try
			{
				if (NumOfWorker > paydeq.size() || NumOfWorker < 0)
				{
					OutOfRangeEx ex("������� ������ �� ������� ���������� ������", "paydeq[]");
					throw ex;
				}
				else if (NumOfWorker == 0)
				{
					for (unsigned int i = 0; i < paydeq.size(); i++)
					{
						paydeq[i].ShowInfo(PersonCounter[i]);
					}
				}
				else paydeq[NumOfWorker - 1].ShowInfo(PersonCounter[NumOfWorker - 1]);
				check_pause19 = true;
			}
			catch (OutOfRangeEx & ex)
			{
				PrintEx();
				cout << ex.GetDescription() << endl << "���������������� ";
				ex.ShowSpace();
				check_pause19 = true;
				break;
			}

			break;
		}

		case 3: // ������ ����� ������
		{
			cout << "������� ����� ������ � ������ (1 ������ 36 ����)" << endl;
			char Temp[100] = "";
			cin.ignore();
			cin.getline(Temp, 100);
			try
			{
				if (!IsItInt(Temp))
				{
					int tempMaxMem;
					tempMaxMem = atoi(Temp);
					if (tempMaxMem < deqsizefunc(paydeq))
					{
						MemException Mex("������������ ����������.", 2);
						throw Mex;
					}
					else
					{
						MaxMem = tempMaxMem;
					}
					break;
				}
				else
				{
					Exception ex("��������� �������� �� �������� ������");
					throw ex;
					break;
				}
			}
			catch (MemException & ex)
			{
				cout << ex.GetDescription() << " ��� ������: " << ex.code() << endl;
				check_pause19 = true;
				break;
			}
			catch (Exception & ex)
			{
				PrintEx();
				cout << ex.GetDescription() << endl;
				check_pause19 = true;
				continue;
			}
			check_pause19 = true;
			break;
		}

		case 0:
		{
			check19 = false;
			break;
		}
		default:
			cout << "��������� ����" << endl;
			break;
		}
	}
	
#endif // Lab6
	return 0;
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

bool IsItInt(char const* A1)
{
	return !regex_match(A1, regex("([0-9]*)"));
}
void PrintEx()
{
	cout << "----------�������� ���������� �������������� ��������----------" << endl;
}

 int deqsizefunc(Deque<Worker>& const paydeq)
{
	int deqsize = 0;
	for (int i = 0; i < paydeq.size(); i++)
	{
		deqsize = deqsize + sizeof(paydeq[i]);
	}
	return deqsize;
}



