#include <iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n and n) {
		int k = 1;
		while (k < n) k<<=1;
		k>>=1;
		if (n == 1) cout << 1 << endl;
		else cout << (n-k)*2 << endl;
	}
}