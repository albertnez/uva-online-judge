#include <iostream>
#include <map>
using namespace std;
typedef unsigned long long ll;
int main() {
	int n;
	while (cin >> n and n) {
		map<int, int> m;
		ll total = 0;
		while (n--) {
			int k; cin >> k;
			while (k--) {
				int x; cin >> x;
				++m[x];
			}
			map<int,int>::iterator itb = m.begin();
			map<int,int>::reverse_iterator ite = m.rbegin();
			total += ite->first-itb->first;
			--ite->second; --itb->second;
			if (ite->first != itb->first)
				if (ite->second == 0) m.erase(ite->first);
			if (itb->second == 0) m.erase(itb);
		}
		cout << total << endl;
	}
}