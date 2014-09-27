#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef vector<int> vi;

class UnionFind {
private: vi p, rank; int disjoint;
public:
	UnionFind(int n) { p.assign(n,0), rank.assign(n,0); for(int i = 0; i < n; ++i) p[i] = i; disjoint = n; }
	int find(int i) { return (p[i] == i ? p[i] : p[i] = find(p[i])); }
	bool same(int i, int j) { return find(i) == find(j); }
	int getDisjoint() { return disjoint; }
	void join(int i, int j) {
		if (!same(i, j)) {
			--disjoint;
			int x = find(i), y = find(j);
			if (rank[x] > rank[y]) p[y] = x;
			else {
				p[x] = y;
				if (rank[x] == rank[y]) ++rank[y];
			}
		}
	}
};

int main() {
	int n;
	while (cin >> n) {
		vector<char> nums(26,-1);
		int current = 0;
		UnionFind uf(n);
		int connections = 0;
		cin >> connections;
		char A,B,C; cin >> A >> B >> C;
		nums[A-'A'] = current++;
		nums[B-'A'] = current++;
		nums[C-'A'] = current++;
		int alive = nums[C-'A'];
		uf.join(nums[A-'A'], nums[B-'A']);
		uf.join(nums[C-'A'], nums[A-'A']);

		//read connections
		vector<vi> con(n, vi(0));
		while(connections--) {
			cin >> A >> B;
			if (nums[A-'A'] == -1) nums[A-'A'] = current++;
			if (nums[B-'A'] == -1) nums[B-'A'] = current++;
			con[nums[A-'A']].push_back(nums[B-'A']);
			con[nums[B-'A']].push_back(nums[A-'A']);
		}

		int years = 0;
		bool change = true;
		stack<int> rm;
		while(change and uf.getDisjoint() > 1) {
			change = false;
			for (int i = 0; i < n; ++i) {
				if (uf.same(i, alive)) continue;
				connections = 0;
				for (int j = 0; j < con[i].size(); ++j) {
					if (uf.same(con[i][j], alive)) ++connections;
				}
				if (connections >= 3) {
					change = true;
					rm.push(i);
				}
			}
			while (!rm.empty()) {
				uf.join(rm.top(), alive);
				rm.pop();
			}
			++years;
		}
		if (uf.getDisjoint() > 1) cout << "THIS BRAIN NEVER WAKES UP" << endl;
		else cout << "WAKE UP IN, " << years << ", YEARS" << endl;
	}
}