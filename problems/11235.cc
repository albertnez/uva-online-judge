#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int N = 100000;

class SegmentTree {
private: 
	vi st, A;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }

	void build(int p, int L, int R) {
		if (L == R)	st[p] = L;
		else {
			build (left(p), L, (L+R)/2); //left
			build (right(p), (L+R)/2+1, R); //right
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] >= A[p2]) ? p1 : p2;
		}
	}

	int rmq(int p, int L, int R, int i, int j) {
		if (i > R or j < L) return -1;
		if (L >= i and R <= j) return st[p];

		int p1 = rmq(left(p), L, (L+R)/2, i, j);
		int p2 = rmq(right(p), (L+R)/2+1, R, i, j);

		if (p1 == -1) return p2;
		if (p2 == -1) return p1;
		return (A[p1] >= A[p2]) ? p1 : p2;
	}
public:
	SegmentTree(const vi &_A) {
		A = _A; n = int(A.size());
		st.assign(4*n, 0);
		build(1, 0, n-1);
	}
	int rmq(int i, int j) { return rmq(1, 0, n-1, i, j); }	
};

int main() {
	int n, q;
	while (cin >> n and n) {
		cin >> q;
		vi rep(2*N+1, 0);
		vii pos(2*N+1);
		vi v(n+1);
		int old = -2*N;
		int k; 
		for (int i = 0; i < n; ++i) {
			cin >> k;
			++rep[k+N];
			v[i+1] = k; //vector starting at 1
			if (k != old) {
				pos[k+N].first = i+1;
				if (i > 0) pos[old+N].second = i;
				old = k;
			}
		}
		pos[old+N].second = n;

		SegmentTree st(rep);

		while (q--) {
			int a,b; cin >> a >> b;
			int x = v[a], y = v[b];
			if (x == y) cout << b-a+1;
			else {

				cout << max(max(rep[st.rmq(x+1+N, y-1+N)], pos[x+N].second - a +1), b-pos[y+N].first+1);
			}
			cout << endl;
		}
	}
}