#include <iostream>
using namespace std;
int main() {
	unsigned int n;
	while (cin >> n and n) {
		unsigned int a = 0, b = 0;
		bool flip = true;
		unsigned int i = 0;
		while (n >= (1<<i)) {
			if (n & (1<<i)) {
				if (flip) a += 1<<i;
				else b += 1<<i;
				flip = !flip;
			}
			++i;
		}
		cout << a << ' ' << b << endl;
	}
}