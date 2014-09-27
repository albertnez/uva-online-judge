#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	int cases;
	scanf("%d", &cases);
	int killed[1025][1025];
	while (cases--) {
		memset(killed, 0, sizeof(killed[0][0])*1025*1025);
		int d,n;
		scanf("%d %d", &d, &n);
		while (n--) {
			int x,y,p;
			scanf("%d %d %d", &x, &y, &p);
			for (int i = x-d; i <= x+d; ++i) {
				if (i >= 0 and i < 1025) {
					for (int j = y-d; j <= y+d; ++j) {
						if (j >= 0 and j < 1025) killed[i][j] += p;
					}
				}
			}
		}
		int max = 0;
		int mx = 0, my = 0;
		for (int x = 0; x < 1025; ++x) {
			for (int y = 0; y < 1025; ++y) {
				if (killed[x][y] > max) {
					max = killed[x][y];
					mx = x;
					my = y;
				}
			}
		}
		printf("%d %d %d\n", mx, my, max);
	}
}