#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main () {
	int s, l;
	int  left[100002];
	int right[100002];
	while (scanf("%d %d", &s, &l) and (s|l)) {
		//vii v(s+2);
		for (int i = 1; i < s+1; ++i) {
			left[i] = i-1;
			right[i] = i+1;
		}
		right[0] = 0;
		left[s+1] = s+1;
		while (l--) {
			int x,y;
			scanf("%d %d", &x, &y);
			right[left[x]] = right[y];
			left[right[y]] = left[x];

			if (left[x] > 0) printf("%d ", left[x]);
			else printf("* ");
			if (right[y] < s+1) printf("%d\n", right[y]);
			else printf("*\n");
		}
		printf("-\n");
	}
}