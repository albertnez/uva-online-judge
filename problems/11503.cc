#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef vector<int> vi;

class UnionFind {
private: vi p, rank, size;
	int disjoint;
public:
	UnionFind(int n) {
		disjoint = n;
		p.assign(n,0); rank.assign(n,0), size.assign(n,1);
		for (int i = 0; i < n; ++i) p[i] = i;
	}
	int findSet(int i) {return (p[i] == i ? p[i] : p[i] = findSet(p[i]));}
	int isSameSet(int i, int j) {return findSet(i) == findSet(j);}
	void unionSet(int i, int j) {
		if (!isSameSet(i,j)) {
			--disjoint;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				size[x] += size[y];
			}
			else {
				p[x] = y;
				size[y] += size[x];
				if (rank[x] == rank[y]) ++rank[y];
			}
		}
	}
	int numDisjoint() {return disjoint;}
	int sizeOfSet(int i) {return size[findSet(i)];}
};


int main() {
	int cas; cin >> cas;
	while (cas--) {
		int n; cin >> n;
		UnionFind uf(2*n);
		int currInd = 0;
		map<string,int> names;
		while (n--) {
			string a,b; cin >> a >> b;
			if (names.find(a) == names.end()) names[a] = currInd++;
			if (names.find(b) == names.end()) names[b] = currInd++;
			uf.unionSet(names[a], names[b]);
			cout << uf.sizeOfSet(names[a]) << endl;
		}
	}
}