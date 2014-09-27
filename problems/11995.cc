#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		bool bst, bq, bpq;
		bst = bq = bpq = true;
		stack<int> st;
		queue<int> q;
		priority_queue<int> pq;
		while (n--) {
			int op, k; cin >> op >> k;
			if (op == 1) {
				st.push(k); q.push(k); pq.push(k);
			}
			else {
				if (st.empty()) bst = bq = bpq = false;
				else {
					int tmp = st.top(); st.pop();
					if (tmp != k) bst = false;
					tmp = q.front(); q.pop();
					if (tmp != k) bq = false;
					tmp = pq.top(); pq.pop();
					if (tmp != k) bpq = false;
				}
			}
		}
		if (bst and !bpq and !bq) cout << "stack" << endl;
		else if (!bst and bpq and !bq) cout << "priority queue" << endl;
		else if (!bst and !bpq and bq) cout << "queue" << endl;
		else if (!bst and !bpq and !bq) cout << "impossible" << endl;
		else cout << "not sure" << endl;
	}
}