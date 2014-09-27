#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef vector<int> vi;



int main() {
	int n;
	while (cin >> n and n) {
		map<vi, int> m;
		while (n--) {
			vi v(5);
			for (int i = 0; i < 5; ++i) cin >> v[i];
			sort(v.begin(), v.end());
			++m[v];
		}
		int sz = m.size();
		vi aux(sz);

		int i = 0;
		for (map<vi,int>::iterator it = m.begin(); it != m.end(); ++it) {
			aux[i++] = it->second;
		}
		sort(aux.begin(), aux.end());



		int total = 0;
		int count = aux[sz-1];
		i = sz-1;
		while (i >= 0 and aux[i] == count) {
			total += count;
			--i;
		}
		cout << total << endl;

	}
}