#include <cstdio>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int count = 0;
		for (int i = n+1; i <= n*2; ++i)
			if ((i*n)%(i-n)==0)
				++count;
		printf("%d\n", count);
		for (int i = n+1; i <= n*2; ++i)
			if ((i*n)%(i-n)==0)
				printf("1/%d = 1/%d + 1/%d\n", n, (i*n)/(i-n), i);
	}	
}