#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
int main() {
	int x;
	vi v;
	while (cin >> x) {
		v.push_back(x);
		nth_element(v.begin(), v.begin()+v.size()/2 ,v.end());
		int median = v[v.size()/2];
		if (v.size()%2 == 0) {
			nth_element(v.begin(), v.begin()+v.size()/2-1, v.end());
			median = (median+v[v.size()/2-1])/2;
		}
		cout << median << endl;
	}
}