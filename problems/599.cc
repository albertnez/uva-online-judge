#include <iostream>
#include <bitset>
using namespace std;

int main() {
	int n; cin >> n;
	bitset<26> bit;
	while (n--) {
		int edges = 0;
		bit.reset();
		string s;
		while (cin >> s and s[0] != '*') {
			bit[s[1]-'A'] = bit[s[3]-'A'] = 1;
			++edges;
		}
		cin >> s;
		int v = (s.size()+1)/2;

		cout << "There are " << v-edges - (v - bit.count()) << " tree(s) and " << (s.size()+1)/2-bit.count() << " acorn(s)." << endl;
	}
}
	