#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef pair<int,int> ii;
typedef vector<ii> Vii;
typedef vector<Vii> Mii;

int f(char c) { return c - 'A'; }

int INF = 1e9;

int main() {
	int m; 
	while (cin >> m and m) {
		vector<bool> valid(26, false);
		Mi yadj(26, Vi(26, INF)), madj(26, Vi(26, INF));
		for (int i = 0; i < m; ++i) {
			char y, d, a, b;
			int c;
			cin >> y >> d >> a >> b >> c;
			int p = f(a), q = f(b);
			valid[p] = valid[q] = true;
			if (y == 'Y') yadj[p][q] = min(yadj[p][q], c);
			else madj[p][q] = min(madj[p][q], c);
			if (d == 'B') {
				if (y == 'Y') yadj[q][p] = min(yadj[q][p], c);
				else madj[q][p] = min(madj[q][p], c);
			}
		}
		char p, q; cin >> p >> q;
		int x = f(p);
		int y = f(q);

		for (int i = 0; i < 26; ++i) madj[i][i] = yadj[i][i] = 0;

		for (int k = 0; k < 26; ++k)
			for (int i = 0; i < 26; ++i)
				for (int j = 0; j < 26; ++j) {
					madj[i][j] = min(madj[i][j], madj[i][k] + madj[k][j]);
					yadj[i][j] = min(yadj[i][j], yadj[i][k] + yadj[k][j]);
				}
					
					

		int minim = INF;
		for (int k = 0; k < 26; ++k) 
			minim = min(minim, yadj[x][k] + madj[y][k]);
		
		vector<bool> sol(26, false);
		for (int k = 0; k < 26; ++k)
			if (yadj[x][k] + madj[y][k] == minim) sol[k] = true;

		if (minim < INF) {
			cout << minim;
			for (int i = 0; i < 26; ++i)
				if (sol[i]) cout << ' ' << char('A'+i);
			cout << endl;
		}
		else cout << "You will never meet." << endl;			
		
	}	
}