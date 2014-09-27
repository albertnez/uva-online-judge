#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack> 
using namespace std;
typedef vector<int> Vi;

Vi v, id, p, a;

void print(int i) {
	stack<int> s;
	for (; p[i] >= 0; i = p[i]) s.push(a[i]);
	printf("%d\n", a[i]);
	for (; !s.empty(); s.pop())
		printf("%d\n", s.top());
}

int main() {
	int k, i = 0;
	while (scanf("%d", &k) != EOF) {
		a.push_back(k);
		int pos = lower_bound(v.begin(), v.end(), k)-v.begin();
		if (pos == v.size()) {
			v.push_back(k);
			id.push_back(i);
		}
		else {
			v[pos] = k;
			id[pos] = i;
		}
		p.push_back( pos ? id[pos-1] : -1);
		++i;
	}

	printf("%d\n-\n", int(v.size()));
	print(id[v.size()-1]);
}








/*
Vi p;
Vi lis, a;

void print(int i) {
	if (p[i] >= 0 and p[i] != i)
		print(p[i]);

	printf("%d\n", a[i]);
}

int main() {
	int n, j = 0;
	scanf("%d", &n);
	a.push_back(n);
	p.push_back(0);
	lis.push_back(1);
	int maxlis = 1;
	int maxind = 0;
	while (scanf("%d", &n) != EOF) {
		++j;
		a.push_back(n);
		int ind = -1, mlis = 0;
		for (int i = 0; i < j; ++i) {
			if (lis[i] >= mlis and a[i] < a[j]) {
				ind = i;
				mlis = lis[ind];
			}
		}
		lis.push_back(mlis+1);
		p.push_back(ind);
		if (mlis+1 >= maxlis) {
			maxlis = mlis+1;
			maxind = j;
		}
	}
	++j;

	printf("%d\n-\n", maxlis);
	print(maxind);
}
	*/