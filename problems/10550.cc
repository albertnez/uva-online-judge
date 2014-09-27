#include <iostream>
using namespace std;
int main() {
	int a,b,c,d;
	while (cin >> a >> b >> c >> d and (a|b|c|d)) {
		int t = 360*3;
		t += (a-b)*9;
		if (a-b < 0) t += 360;
		t += (c-b)*9;
		if (c-b < 0) t += 360;
		t += (c-d)*9;
		if (c-d < 0) t += 360;
	cout << t << endl;
	}
}