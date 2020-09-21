#include "Test.h"

using namespace std;

void Test::testw() {
	cout << "Worker1 test\n";
	Worker1 w("À À À", Sex(0), 10000.0, 5000.0, 8.0);
	w.setName("");
	w.setNormalHours(124);
	w.setNormalHours(0);
	w.setNormalHours(-12964);
	w.setOverPayment(50);
	w.setOverPayment(0);
	w.setOverPayment(-25);
	w.setPayment(15);
	w.setPayment(0);
	w.setPayment(-474);
	w.setSex(Sex(5));

	cout << "construction test\n";
	if (w.getName() != "" && w.getNormaHours() > 0 && w.getOverPayment() >= 0 && w.getPayment() > 0 && (w.getSex() == "male" || w.getSex() == "female" || w.getSex() == "undefined" || w.getSex() == "combet helicopter MI-8"))
		cout << "all goes good\n";
	else cout << "something wrong\n";
	cout << w.getName() << " " << w.getSex() << " " << w.getNormaHours() << " " << w.getOverPayment() << " " << w.getPayment() << "\n";

	cout << "work test\n";
	w.work(10);
	w.work(-10);
	if (10 == w.getFinalHours())
		cout << "all goes good\n";
	else cout << "something wrong\n";

	cout << "pay test\n";
	w.setNormalHours(9);
	w.setPayment(1000);
	w.setOverPayment(500);
	float pay = w.pay();
	if (w.getFinalHours() == 0 && pay == 1000 + 500)
		cout << pay << " all goes good\n";
	else cout << "something wrong\n";
	cout << "end of the test\n";
}

void Test::testw2() {
	cout << "Worker2 test\n";
	Worker2 w("À À À", Sex(0), 10000.0, 0.5);
	w.setName("");
	w.setStaticPayment(124);
	w.setStaticPayment(0);
	w.setStaticPayment(-12964);
	w.setPercent(0.7);
	w.setPercent(0);
	w.setPercent(25);
	w.setSex(Sex(5));

	cout << "construction test\n";
	if (w.getName() != "" && w.getStaticPayment() > 0 && w.getPercent() > 0 && w.getPercent() <= 1 && (w.getSex() == "male" || w.getSex() == "female" || w.getSex() == "undefined" || w.getSex() == "combet helicopter MI-8"))
		cout << "all goes good\n";
	else cout << "something wrong\n";
	cout << w.getName() << " " << w.getSex() << " " << w.getPercent() << " " << w.getStaticPayment() << endl;

	cout << "sells test\n";
	w.sell(10);
	w.sell(-10);
	if (10 == w.getSells())
		cout << "all goes good\n";
	else cout << "something wrong\n";

	cout << "payment test\n";
	w.setPercent(0.5);
	w.setStaticPayment(1000);
	float save = w.pay();
	if (w.getSells() == 0 && save == 1005)
		cout << "all goes good\n";
	else cout << "something wrong\n";
	cout << "end of the test\n";
}
