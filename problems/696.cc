#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m and (n or m)) {
		int sol = 0;
		if (n==1 or m==1) sol = max(n,m);
		else if (n==2 or m==2) {
			sol = (min((max(n,m) % 4), 2)) * 2 + (max(n,m)/4) * 4;
		}
		else sol = (n*m+1)/2;
		cout << sol << " knights may be placed on a " << n <<  " row " << m << " column board." << endl;
	}
}