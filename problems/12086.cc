#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int lsb(int x) { return x & -x; }
vi ft;
int rsq(int b) {
	int t = 0;
	for (; b; b -= (lsb(b))) t += ft[b];
	return t;
}
int interval(int a, int b) {
	return rsq(b) - (a == 1 ? 0 : rsq(a-1));
}
int update(int b, int x) {
	for (; b < ft.size(); b+=lsb(b)) ft[b] += x;
}

int main() {
	int cases = 0;
	int n;
	while (cin >> n and n) {
		if (cases) cout << endl;
		cout << "Case " << ++cases << ':' << endl;
		ft = vi(n+1, 0);
		vi val(n+1);
		for (int i = 1; i <= n; ++i) {
			int k; cin >> val[i]; update(i, val[i]);
		}
		string s;
		while (cin >> s and s != "END") {
			if (s == "M") { 
				int a,b; 
				cin >> a >> b; 
				cout << interval(a,b) << endl; 
			}
			else {
				int a,b; cin >> a >> b;
				update(a,b-val[a]);
				val[a] = b;
			}
		}
	}
}