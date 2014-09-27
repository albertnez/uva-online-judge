#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
typedef vector<int> vi;


class UnionFind {
private: vi p, rank;
public:
	UnionFind(int N) { rank.assign(N,0); p.assign(N,0);
		for (int i = 0; i < N; ++i) p[i] = i; }

	int findSet(int i) { return (p[i] == i ? p[i] : p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(p[i]) == findSet(p[j]); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x;
			else {
				p[x] = y;
				if (rank[x] == rank[y]) ++rank[y];
			}
		}
	}
};

int main() {
	int ncas; cin >> ncas;
	for (int cas = 0; cas < ncas; ++cas) {
		int n, right = 0, wrong = 0;;
		cin >> n;
		UnionFind uf(n);
		string s;
		getline(cin,s);
		while (getline(cin,s) and s != "") {
			stringstream ss(s);
			int a,b;
			char c; ss >> c >> a >> b; --a; --b;
			if (c == 'c') uf.unionSet(a,b);
			else (uf.isSameSet(a,b) ? ++right : ++wrong);
		}

		if (cas) cout << endl;
		cout << right << ',' << wrong << endl;
	}
}

