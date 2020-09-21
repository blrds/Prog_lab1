#include <locale.h> 
#include "Worker1.h"
#include "Worker2.h"
#include"Test.h"

#include <iostream>
#include <string>

using namespace std;

void clearCin() // функция очистки потока ввода
{
	cin.clear(); 
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void enterDataWorker1()
{
	Worker1 w1("А А А", Sex(0), 10000.0, 5000.0, 8.0);

	string fullName;
	Sex sex;
	int n;
	float payment, finalHours, normalHours, overPayment;

	cout << "Введите ФИО работника: ";
	cin >> fullName; 
	w1.setName(fullName);
	cout << endl;

	cout << "Пол работника:\n\t1 - мужской \n\t2 - женский \n\t3 - не определён \n\t4 - боевой вертолёт" << endl;
	clearCin();
	cin >> n;
	w1.setSex(Sex(n-1));
	cout << endl;

	cout << "Основная ставка: (>0)";
	clearCin();
	cin >> payment;
	w1.setPayment(payment);
	cout << endl;

	cout << "Ставка за переработанные часы (руб/ч): (>0)";
	clearCin();
	cin >> overPayment;
	w1.setOverPayment(overPayment);
	cout << endl;

	cout << "Количество обязательных к отработке часов: (>0)";
	clearCin();
	cin >> normalHours;
	w1.setNormalHours(normalHours);
	cout << endl;

	cout << "Введите количество отработанных часов (признаком окончания ввода является 0): (>0)";
	do 
	{
		clearCin();
		cin >> n;
		w1.work(n);
		cout << endl;
	} while (n != 0);

	cout << "Заработная плата работника составляет " << w1.pay() << " рублей"; 
	
}

void enterDataWorker2()
{

	Worker2 w2("А А А", Sex(0), 10000.0, 0.5);

	string fullName;
	Sex sex;
	int n;
	float staticPayment, percent, sells;

	cout << "Введите ФИО работника: ";
	cin >> fullName;
	w2.setName(fullName);
	cout << endl;

	cout << "Пол работника:\n\t1 - мужской \n\t2 - женский \n\t3 - не определён \n\t4 - боевой вертолёт" << endl;
	clearCin();
	cin >> n;
	w2.setSex(Sex(n-1));
	cout << endl;

	cout << "Размер фиксированной платы: (>0)" << endl;
	clearCin();
	cin >> staticPayment; 
	w2.setStaticPayment(staticPayment);
	cout << endl;

	cout << "Процент: (0<x<1)" << endl;
	clearCin();
	cin >> percent;
	w2.setPercent(percent);
	cout << endl;

	cout << "Введите количество выручки (признаком окончания ввода является 0): (>0)";
	do
	{
		clearCin();
		cin >> sells;
		w2.sell(sells);
		cout << endl;
	} while (sells != 0);
	
	cout << "Заработная плата работника составляет " << w2.pay() << " рублей";
}


int main()
{
	setlocale(LC_ALL, "Rus");
	string a;
	getline(cin, a);
	cout << "\n" << a << "\n";
	int n;

	cout << "Данная программа расчитывает заработную плату. ";
	cout << "Выберите способ выплаты зарплаты\n" << "\n 1. Почасовая.\n 2. Комиссионная." << endl;
	do
	{
		cin >> n;
		cout << endl;
		if (n != 1 && n != 2) cout << "Введен неверный способ выплаты зарплаты, повторите попытку: ";
	} while (n != 1 && n != 2);

	if (n == 1)
		enterDataWorker1();
	else
		enterDataWorker2();
}