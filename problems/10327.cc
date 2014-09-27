#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> Vi;
int main() {
	int n; 
	while (cin >> n) {
		Vi v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		int t = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n-1; ++j) {
				if (v[j] > v[j+1]) {
					++t;
					swap(v[j], v[j+1]);
				}
			}
		}
		cout << "Minimum exchange operations : " << t << endl;
	}
}