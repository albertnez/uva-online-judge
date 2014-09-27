#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> op(3), me(3, 100);
	while (cin >> op[0] >> op[1] >> op[2] >> me[0] >> me[1] and op[0]) {
		vector<bool> used(53);
		used[op[0]] = used[op[1]] = used[op[2]] = used[me[0]] = used[me[1]] = true;
		me[2] = 100;
		sort(op.begin(), op.end());
		sort(me.begin(), me.end());
		//failure case
		if (me[0] < op[1] and me[1] < op[2]) // 1 2 / 1 1
			cout << -1 << endl;
		else if (me[0] > op[1]) { //2 X
			if (me[0] < op[2]) { //2 3 / 2 2
				int i = op[1]+1;
				while (i <= 52 and used[i]) ++i;
				cout << (i <= 52 ? i : -1) << endl;				
			}
			else { // 3 3
				int i = 1;
				while (i <= 52 and used[i]) ++i;
				cout << (i <= 52 ? i: -1) << endl;
			}
		}
		else { // 1 3
			int i = op[2]+1;
			while (i <= 52 and used[i]) ++i;
			cout << (i <= 52 ? i : -1) << endl;
		}
	}
}