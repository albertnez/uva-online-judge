#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n;
	while (cin >> n and n) {
		priority_queue<int> pq;
		for (int i = 0; i < n; ++i) {
			int k; cin >> k; pq.push(-k);
		}
		int cost = 0;
		while (!pq.empty()) {
			int a = -pq.top(); pq.pop();
			int b = -pq.top(); pq.pop();
			cost += a+=b;
			if (!pq.empty()) pq.push(-a);
		}
		cout << cost << endl;
	}
}