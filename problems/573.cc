#include <iostream>
using namespace std;
int main() {
	int h,u,d,f;
	while (cin >> h >> u >> d >> f and h > 0) {
		double act = 0, v = u;
		int day = 0;
		while (act >= 0 and act <= h) {
			++day;
			act += v;
			if (act > h) break;
			v -= u*(double(f)/100);
			if (v < 0) v = 0;
			act -= d;
		}
		if (act < 0) cout << "failure on day " << day << endl;
		else cout << "success on day " << day << endl;
	}
}