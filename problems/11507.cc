#include <iostream>
using namespace std;
int main() {
	int n;
	int yp[6] = {1, 2, 3, 0, 4, 5},
	ym[6] = {3, 0, 1, 2, 4, 5},
	zp[6] = {5, 1, 4, 3, 0, 2},
	zm[6] = {4, 1, 5, 3, 2, 0};
	string pos[6] = {"+x","+y","-x","-y","-z","+z"};
	while (cin >> n and n > 0) {
		string s;
		int p = 0;
		while (--n) {
			cin >> s;
			if (s == "+y") p = yp[p];
			else if (s == "-y") p = ym[p];
			else if (s == "+z") p = zp[p];
			else if (s == "-z") p = zm[p];
		}
		cout << pos[p] << endl;
	}
}