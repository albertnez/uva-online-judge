#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		n = (((n*567)/9+7492)*235)/47-498;
		if (n < 0) n*= -1;
		cout << (n/10)%10 << endl;
	}
}