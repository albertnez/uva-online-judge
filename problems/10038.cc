#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool used[3000];

int main() {
	int n;
	while (scanf("%d",&n)!=EOF) {
		memset(used, false, sizeof(used));
		bool first = true;
		bool jolly = true;
		int old;
		for (int i = 0; i < n; ++i) {
			int k;
			scanf("%d", &k);
			if (first) first = false;
			else if (jolly){
				int num = abs(k-old);
				if (num >= 1 and num <= n-1 and !used[num]) used[num] = true;
				else jolly = false;
			}
			old = k;
		}
		if (jolly) printf("Jolly\n");
		else printf("Not jolly\n");
	}
}