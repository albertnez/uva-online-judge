#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<vi> vii;

void f(int p, vi& in, vi& res, const vii& adj, const vc& letters) {
	if (p == in.size()) {
		for (int i = 0; i < in.size(); ++i) cout << letters[res[i]];
		cout << endl;
	}

	for (int i = 0; i < in.size(); ++i) {
		if (in[i] == 0) {
			res[p] = i;
			in[i] = -1;
			for (int j = 0; j < adj[i].size(); ++j) --in[adj[i][j]];
			f(p+1, in, res, adj, letters);
			for (int j = 0; j < adj[i].size(); ++j) ++in[adj[i][j]];
			in[i] = 0;
		}
	}
}

int main() {
	bool first = true;
	string s;
	while (getline(cin, s)) {
		if (first) first = false;
		else cout << endl;

		stringstream ss(s);
		vc letters;
		vi ind(26);
		while (ss>>s) letters.push_back(s[0]);
		sort(letters.begin(), letters.end());
		int n = letters.size();
		vii adj(n);
		vi in(n, 0), res(n);
		for (int i = 0; i < n; ++i) ind[ letters[i]-'a' ] = i;
		getline(cin,s);
		ss.clear();
		ss.str(s);
		string sa,sb;
		while(ss>>sa>>sb) {
			adj[ ind[sa[0]-'a'] ].push_back(ind[sb[0]-'a']);
			++in[ind[sb[0]-'a']];
		}
		f(0, in, res, adj, letters);
	}
}