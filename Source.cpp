// Лабораторная работа 2 (3 семестр)

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
		cout << "\tВыберете пункт " << endl << endl;
		cout << "1) Ввести данные сотрудника " << endl;
		cout << "2) Рассчитать зарплату " << endl;
		cout << "3) Рассчитать налог " << endl;
		cout << "4) Рассчитать пенсию " << endl;
		cout << "5) Показать информацию о сотруднике " << endl;
		cout << "6) Удалить сотрудника" << endl << endl;
		cout << "0) Выход\n";
		cin >> choose;
		cout << endl;

		switch (choose)
		{
		case 1: // Ввести данные сотрудника
		{
			Payment Person;

			char A[100] = "";
			int temp, temp1, temp2;

			cout << "Введите ФИО " << endl;

			cin.ignore();
			cin.getline(A, 100);
			Person.setfio(A);

			cout << "Введите оплату за смену " << endl;
			cin >> temp;
			Person.setsalary(&temp);

			cout << "Введите год " << endl;
			cin >> temp1;
			Person.setyear(&temp1);

			cout << "Введите отработанные дни " << endl;
			cin >> temp2;
			Person.setworkday(&temp2);

			payvec.push_back(Person);
			break;
		}
		case 2: // Рассчитать зарплату
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - всех)" << endl;
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
		case 3:  // Рассчитать налог
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - всех)" << endl;
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
		case 4:  // Рассчитать пенсию
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - всех)" << endl;
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
		case 5:  // Показать информацию о сотруднике
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - всех)" << endl;
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
		case 6: // Удалить сотрудника
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - всех)" << endl;
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
		case 0: // Выход
		{
			a = false;
			break;
		}
		default:
			cout << "Повторите ввод" << endl;
			break;
		}

	}
}