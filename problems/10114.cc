#include <iostream>
#include <fstream>

using namespace std;
int main() {
	int duration = 1, cases;
	double payment, debt;
//	fstream cin("loan.in");
// fstream out("loan.out");
	while (cin >> duration >> payment >> debt >> cases and duration > 0) {
		double car = payment+debt;
		double pay = double(debt)/double(duration);
		int actual = 0;
		int month;
		double interest;
		cin >> month >> interest;
		car *= 1-interest;
		for (int i = 1; i < cases; ++i) {
			cin >> month;
			while (actual < month-1 and debt >= car) {
				debt -= pay;
				++actual;
				car *= 1-interest;
			}
			cin >> interest;
		}
		while (actual < duration and debt >= car) {
			debt -= pay;
			++actual;
			car *= 1-interest;
		}
		cout << actual << " month" << (actual == 1 ? "":"s") << endl;
	}
//	cin.close();
//	out.close();
}