// Лабораторная работа 6 (3 семестр)

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#endif  // для работы классических функций ("НЕБЕЗОПАСНЫХ"!_s)

//#define DEBUG
//#define DEBUG2
//#define DEBUG3

#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
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
	Deque<Worker>paydeq;

	/*bool ch = true;
	while (ch)
	{
		Worker W;
		int a = 999;
		checkdestr = false;
		W.setsalary(&a);
		W.setworkday(&a);
		W.setyear(&a);
		W.setsalaryperhour(&a);
		W.sethourpermonth(&a);

		paydeq.push_back(W);

		paydeq[0].ShowInfo();
		system("pause");
	}*/



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
		cout << " Колличество сотрудников: " << payvec.size() << endl << endl;
		cout << "     Выберете пункт: " << endl << endl;

		cout << "\t(Лаба 1) " << endl;
		cout << "1) Ввести данные сотрудника " << endl;
		cout << "2) Рассчитать зарплату " << endl;
		cout << "3) Рассчитать налог " << endl;
		cout << "4) Рассчитать пенсию " << endl;
		cout << "5) Показать информацию о сотруднике " << endl;
		cout << "6) Удалить сотрудника" << endl << endl;
		cout << "\t(Лаба 2) " << endl;
		cout << "7) Приравнять сотрудников" << endl;
		cout << "8) Изменить оклад" << endl;
		cout << "9) Изменить год поступления" << endl;
		cout << "10) Расчитать зарплату с вычетом процентов" << endl << endl;
		cout << "\t(Лаба 3) " << endl;
		cout << "11) Поместить в выходной поток / Вывод в поток" << endl;
		cout << "12) Получить из входного потока / Ввод из потока" << endl;
		cout << "13) Добавить данные о работнике в файл" << endl;
		cout << "14) Добавить данные о работнике из файла" << endl;
		cout << "15) Запись в бинарный файл" << endl;
		cout << "16) Добавить из бинарного файла" << endl << endl;
		cout << "\t(Лаба 4) " << endl;
		cout << "17) Демонстрация класса \"Employee\"" << endl;
		cout << "18) Демонстрация класса \"Worker\"" << endl << endl;
		cout << "\t(Лаба 4) " << endl;
		cout << "19) Демонстрация работы дека" << endl;
		cout << "0) Выход\n";
		cin >> choose;
		if (choose > 19 || choose < 0)
		{
			cout << "Пункта с таким номером нет, попробуйте еще раз" << endl << endl;
			check_pause = true;
			continue;
		}
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
			cout << "Добавлено" << endl;
			check_pause = true;
			break;
		}
		case 2: // Рассчитать зарплату
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - всех)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
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
		case 3:  // Рассчитать налог
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - всех)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
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
		case 4:  // Рассчитать пенсию
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - всех)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
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
		case 5:  // Показать информацию о сотруднике
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - всех)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
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
		case 6: // Удалить сотрудника
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - всех)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
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
				cout << "Удалено" << endl;
				check_pause = true;
			}
			else
			{
				checkdestr = true;
				(payvec.begin() + NumOfWorker - 1)->~Payment();
				checkdestr = false;
				payvec.erase(payvec.begin() + NumOfWorker - 1);
				cout << "Удалено" << endl;
				check_pause = true;
			}
			checkdestr = true;
			break;
		}

		// ----------------------------------Лаба 2---------------------------------- 

		case(7): //Тест оператора присваивания
		{
			int NumOfWorker;
			int NumOfWorker1;
			cout << "Введите номер работника которого нужно приравнять" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker <= 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
				check_pause = true;
				break;
			}
			cout << "Введите номер работника к которому нужно приравнять" << endl;
			cin >> NumOfWorker1;
			if (NumOfWorker1 > payvec.size() || NumOfWorker1 <= 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
				check_pause = true;
				break;
			}
			/*cout << "\t1ый (до): " << endl; payvec[NumOfWorker - 1].ShowInfo();
			cout << "\t2ой (до): " << endl; payvec[NumOfWorker1 - 1].ShowInfo();*/   // "ДЕБАГ"

			payvec[NumOfWorker - 1] = payvec[NumOfWorker1 - 1];
			cout << "Присвоено" << endl;
			check_pause = true;

			/*cout << "\t1ый (после): " << endl; payvec[NumOfWorker - 1].ShowInfo();
			cout << "\t2ой (после): " << endl; payvec[NumOfWorker1 - 1].ShowInfo();*/
			break;
		}
		case(8): // изменить оклад
		{
			int NumOfWorker;
			int unsigned change_salary;
			int check;
			cout << "Введите номер работника " << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
				check_pause = true;
				break;
			}
			cout << "Увелить(1) / уменьшить(2)" << endl;
			cin >> check;
			cout << "Насколько? " << endl;
			cin >> change_salary;
			if (check == 1)
			{
				payvec[NumOfWorker - 1] + change_salary;
				cout << "Увеличено" << endl;
				check_pause = true;
			}
			else if (check == 2)
			{
				payvec[NumOfWorker - 1] - change_salary;
				cout << "Уменьшено" << endl;
				check_pause = true;
			}
			else
			{
				cout << "Введено неверное число" << endl;
				check_pause = true;
				break;
			}

			break;
		}
		case(9): // Изменить год поступления
		{
			int NumOfWorker = 0;
			int check = 0;
			cout << "Введите номер работника " << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
				check_pause = true;
				break;
			}
			cout << "Увеличить(1) / уменьшить(2)" << endl;
			cin >> check;
			if (check == 1)
			{
				payvec[NumOfWorker - 1]++;
				cout << "Увеличено" << endl;
				check_pause = true;
			}
			else if (check == 2)
			{
				payvec[NumOfWorker - 1]--;
				cout << "Уменьшено" << endl;
				check_pause = true;
			}
			else
			{
				cout << "Введено неверное число" << endl;
				check_pause = true;
				break;
			}

			break;
		}
		case(10): // Рассчитать ЗП с вычетом процентов
		{
			int NumOfWorker;
			cout << "Введите номер работника" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker <= 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
				check_pause = true;
				break;
			}
			payvec[NumOfWorker - 1]();
			check_pause = true;

			break;
		}

		// ----------------------------------Лаба 3----------------------------------

		case(11): // Поместить в выходной поток / Вывод в поток
		{
			int NumOfWorker;
			cout << "Введите номер работника" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker <= 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
				check_pause = true;
				break;
			}
			cout << payvec[NumOfWorker - 1] << endl;
			break;
		}
		case(12): // Получить из входного потока / Ввод из потока
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - новый работник)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
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
		case(13): // Добавить данные о работнике в файл
		{
			int NumOfWorker;
			cout << "Введите номер работника" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker <= 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
				check_pause = true;
				break;
			}
			cout << payvec[NumOfWorker - 1] << endl;
			ofstream ofs;
			ofs.open("MyFile.txt"/*, ofstream :: app*/);
			if (ofs.is_open())
			{
				ofs << payvec[NumOfWorker - 1];
				cout << "Добавлено" << endl;
				check_pause = true;
			}
			else
			{
				cout << "Файл не был открыт" << endl;
			}

			break;
		}
		case(14):
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - новый работник)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
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
					cout << "Добавлено" << endl;
					check_pause = true;
				}
				else
				{
					cout << "Файл не был открыт" << endl;
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
					cout << "Добавлено" << endl;
					check_pause = true;
				}
				else
				{
					cout << "Файл не был открыт" << endl;
				}
				break;
			}
			break;
		}
		case(15): // запись в бинарный файл
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - новый работник)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
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

					cout << "Введите ФИО " << endl;

					cin.ignore();
					cin.getline(A, 100);
					Person.setfio(A);

					cout << "Введите оплату за смену " << endl;
					cin >> temp;
					//cout << "Зарплата = 100 " << endl;
					//temp = 100;
					Person.setsalary(&temp);

					cout << "Введите год " << endl;
					cin >> temp1;
					/*cout << "Год = 100 " << endl;
					temp1 = 100;*/
					Person.setyear(&temp1);

					cout << "Введите отработанные дни " << endl;
					cin >> temp2;
					/*cout << "Отработанные дни = 100 " << endl;
					temp2 = 100;*/
					Person.setworkday(&temp2);

					payvec.push_back(Person);
					//checkdestr = false;
					ToFile(payvec[payvec.size() - 1]);
					cout << "Добавлено" << endl;
					check_pause = true;
					break;
				}
				else
				{
					//checkdestr = false;
					ToFile(payvec[NumOfWorker - 1]);
					cout << "Добавлено" << endl;
					check_pause = true;
					break;
				}
				break;
			}
			break;
		}
		case(16): // Добавить из бинарного файла
		{
			int NumOfWorker;
			cout << "Введите номер работника (0 - новый работник)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
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
					cout << "Добавлено" << endl;
					check_pause = true;
				}
				else
				{
					FromFile(payvec[NumOfWorker - 1]);
					cout << "Добавлено" << endl;
					check_pause = true;
				}
				break;
			}
		}

		// ----------------------------------Лаба 4----------------------------------

		case 17: // демонстрация класса "Employee"
		{
			system("cls");
			Employee employee;
			int increase = 100;
			char A[100] = "";

			int NumOfWorker;
			cout << "Введите номер работника (0 - новый работник)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
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

					employee = Person;

					cout << "Введите должность сотрудника " << endl;
					cin.ignore();
					cin.getline(A, 100);
					employee.setposition(A);
					cout << "надбавка 100 по умолчанию* " << endl;
					employee.setincrease(&increase);
					//employee.ShowPaymentForMonth();
					employee.ShowInfo();
					payvec.push_back(employee);
					cout << "Добавлено" << endl;
					check_pause = true;
				}
				else
				{
					employee = payvec[NumOfWorker - 1];
					cout << "Введите должность " << endl;
					cin.ignore();
					cin.getline(A, 100);
					employee.setposition(A);
					cout << "надбавка 100 по умолчанию* " << endl;
					employee.setincrease(&increase);
					employee.setposition(A);
					//employee.ShowPaymentForMonth();
					employee.ShowInfo();
					cout << "Добавлено" << endl;
					check_pause = true;
				}
				break;
			}
		}
		case 18: // демонстрация класса "Worker"
		{
			system("cls");
			Worker worker;
			char A[100] = "";
			int a1 = 1000;

			int NumOfWorker;
			cout << "Введите номер работника (0 - новый работник)" << endl;
			cin >> NumOfWorker;
			if (NumOfWorker > payvec.size() || NumOfWorker < 0)
			{
				cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
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

					worker = Person;
					int a2 = 9 * temp2;

					cout << "Введите должность работника " << endl;
					cin.ignore();
					cin.getline(A, 100);
					worker.setprofession(A);
					cout << "ЗП/Ч = 1000 по умолчанию " << endl;
					worker.setsalaryperhour(&a1);
					cout << "Часов в день по умолчанию 9, дней в месяце в Payment" << endl;
					worker.sethourpermonth(&a2);
					//worker.ShowPaymentForMonth();
					worker.ShowInfo();
					payvec.push_back(worker);
					cout << "Добавлено" << endl;

					check_pause = true;
				}
				else
				{
					worker = payvec[NumOfWorker - 1];
					int a2 = 9 * payvec[NumOfWorker - 1].returnworkday();
					cout << "Введите должность " << endl;
					cin.ignore();
					cin.getline(A, 100);
					worker.setprofession(A);
					cout << "ЗП/Ч = 1000 по умолчанию " << endl;
					worker.setsalaryperhour(&a1);
					cout << "Часов в день по умолчанию 9, дней в месяце в Payment" << endl;
					worker.sethourpermonth(&a2);
					//worker.ShowPaymentForMonth();
					worker.ShowInfo();
					cout << "Добавлено" << endl;
					check_pause = true;
				}
				break;
			}
		}

		// ----------------------------------Лаба 5----------------------------------

		case 19: // Демонстрация работы дека
		{
			system("cls");
			bool check19 = true;
			bool check_pause19 = false;
			int PersonCounter[100] = {'\0'};
			while (check19)
			{
				if (check_pause19)
				{
					system("pause");
					system("cls");
					check_pause19 = false;
				}
				cout << "Количество объектов в деке: " << paydeq.size() << endl << endl;
				cout << "1) Ввести данные сотрудника " << endl;
				cout << "2) Показать информацию о сотруднике " << endl;
				cout << "3) Удалить сотрудника" << endl << endl;
				cout << "0) Выход\n";
				int choose19;
				cin >> choose19;
				if (choose19 > 3 || choose19 < 0)
				{
					cout << "Пункта с таким номером нет, попробуйте еще раз" << endl << endl;
					check_pause19 = true;
					continue;
				}
				cout << endl;

				switch (choose19)
				{
				case 1: // Ввести данные сотрудника
				{
					Worker Person;

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

					cout << "Зарегестрировать как Payment (1) / Employee(2) / Worker(3)? " << endl;
					int r;
					cin >> r;

					if (r == 1){}
					else if (r == 2)
					{
						int increase = 100;
						char A1[100] = "";
						cout << "Введите должность сотрудника " << endl;
						cin.ignore();
						cin.getline(A1, 100);
						Person.setposition(A1);
						cout << "Надбавка 100 по умолчанию* " << endl;
						Person.setincrease(&increase);
					}
					else if (r == 3)
					{
						int a2 = 9 * temp2;
						int a1 = 1000;
						char A1[100] = "";
						cout << "Введите должность работника " << endl;
						cin.ignore();
						cin.getline(A1, 100);
						Person.setprofession(A1);
						cout << "ЗП/Ч = 1000 по умолчанию " << endl;
						Person.setsalaryperhour(&a1);
						cout << "Часов в день по умолчанию 9, дней в месяце в Payment" << endl;
						Person.sethourpermonth(&a2);
					}
					else
					{
						cout << "Введено неверное число." << endl;
						check_pause19 = true;
						continue;
					}
					paydeq.push_back(Person);
					PersonCounter[paydeq.size() - 1] = r;
					cout << "Добавлено" << endl;
					check_pause19 = true;
					break;
				}
				case 2:  // Показать информацию о сотруднике
				{
					int NumOfWorker;
					cout << "Введите номер работника (0 - всех)" << endl;
					cin >> NumOfWorker;
					if (NumOfWorker > paydeq.size() || NumOfWorker < 0)
					{
						cout << "Работника с таким номером нет, попробуйте еще раз" << endl;
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
				case 3: // Удалить сотрудника
				{
					int check;
					cout << "Удалить первого (1)/ Удалить последнего(2): " << endl;
					cin >> check;
					if (check == 1)
					{
						paydeq.pop_front();
						cout << "Удалено" << endl;
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
						cout << "Удалено" << endl;
						PersonCounter[paydeq.size()] = '\0';
						check_pause19 = true;
						break;
					}
					else
					{
						cout << "Введено неверное число" << endl;
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
					cout << "Повторите ввод" << endl;
					break;
				}
			}
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
	return 0;

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




