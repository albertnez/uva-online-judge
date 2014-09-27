#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
	cout.precision(2);
	int n;
	cin >> n;
	while (n--) {
		ll t = 0;
		vector<int> v(256, 0);
		int k;
		cin >> k;
		while (k--) {
			unsigned char c;
			int p;
			cin >> c >> p;
			v[int(c)] = p;
		}
		cin >> k;
		string s;
		getline(cin,s);
		while (k--) {
			getline(cin,s);
			for (int i = 0; i < int(s.size()); ++i)	t += v[int((unsigned char)s[i])];
		}
		cout  << fixed << double(t)/100 << '$' << endl;
	}
	return 0;
}