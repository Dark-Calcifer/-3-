// Лабораторная работа 2 (3 семестр)

#include "Payment.h"
#include <iostream>
#include <vector>

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

		cout << "\tВыберете пункт " << endl << endl;
		cout << "1) Ввести данные сотрудника " << endl;
		cout << "2) Рассчитать зарплату " << endl;
		cout << "3) Рассчитать налог " << endl;
		cout << "4) Рассчитать пенсию " << endl;
		cout << "5) Показать информацию о сотруднике " << endl;
		cout << "6) Удалить сотрудника" << endl << endl;
		cout << "7) Приравнять сотрудников" << endl;
		cout << "8) Изменить оклад" << endl;
		cout << "9) Изменить год поступления" << endl;
		cout << "10) Расчитать зарплату с вычетом процентов" << endl << endl;
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
			check_pause = true;
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
			check_pause = true;
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
			check_pause = true;
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
			check_pause = true;
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
		case(7): //Тест оператора присваивания
		{
			int NumOfWorker;
			int NumOfWorker1;
			cout << "Введите номер работника которого нужно приравнять" << endl;
			cin >> NumOfWorker;
			cout << "Введите номер работника к которому нужно приравнять" << endl;
			cin >> NumOfWorker1;
			/*cout << "\t1ый (до): " << endl; payvec[NumOfWorker - 1].ShowInfo();
			cout << "\t2ой (до): " << endl; payvec[NumOfWorker1 - 1].ShowInfo();*/

			payvec[NumOfWorker - 1] = payvec[NumOfWorker1 - 1];

			/*cout << "\t1ый (после): " << endl; payvec[NumOfWorker - 1].ShowInfo();
			cout << "\t2ой (после): " << endl; payvec[NumOfWorker1 - 1].ShowInfo();*/
			break;
		}
		case(8): // изменить оклад
		{
			int NumOfWorker = 0;
			int change_salary = 0;
			int check = 0;
			cout << "Введите номер работника " << endl;
			cin >> NumOfWorker;
			cout << "Увелить(1) / уменьшить(2)" << endl;
			cin >> check;
			cout << "Насколько? " << endl;
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
		case(9): // Изменить год поступления
		{
			int NumOfWorker = 0;
			int check = 0;
			cout << "Введите номер работника " << endl;
			cin >> NumOfWorker;
			cout << "Увеличить(1) / уменьшить(2)" << endl;
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
		case(10): // Рассчитать ЗП с вычетом процентов
		{
			int NumOfWorker;
			cout << "Введите номер работника" << endl;
			cin >> NumOfWorker;
			payvec[NumOfWorker - 1]();
			check_pause = true;

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

void Foo(Payment& Object) // Показывает зарплату с вычетом всех процентов
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