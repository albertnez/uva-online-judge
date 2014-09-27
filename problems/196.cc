#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<Mi> Ti;

typedef pair<int,int> ii;
typedef vector<ii> Vii;
typedef vector<Vii> Mii;
typedef vector<Mii> Tii;

int N, M;
int memo[1001][18280];
Tii tb;

int stoi(string s) {
	int n = 0;
	for (int i = 0; i < s.size(); ++i) {
		n *= 10;
		n += s[i]-'0';
	}
	return n;
}

ii parse(string s) {
	size_t found = s.find_first_of("1234567890");
    string a = s.substr(0, found), b = s.substr(found);
    int c = 0;
    for (int i = 0; i < a.size(); ++i) {
    	c *= 26;
    	c += a[i]-'A'+1;
    }
    return ii(stoi(b)-1, c-1);

}


int f(int i, int j) {
	if (memo[i][j] != -1) return memo[i][j];
	int &ans = memo[i][j];
	ans = 0;
	for (int k = 0; k < tb[i][j].size(); ++k) {
		ans += f(tb[i][j][k].first, tb[i][j][k].second);
	}
	return ans;
}

int main() {
	int T; cin >> T;
	while (T--) {
		cin >> M >> N;
		string s;

		tb = Tii(N, Mii(M));

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				string op; cin >> op;
				if (op[0] == '=') {
					memo[i][j] = -1;
					size_t pos = 1, nxt;
					while ((nxt = op.find_first_of("+", pos)) != string::npos) {
						tb[i][j].push_back(ii(parse( op.substr(pos, nxt-pos))));
						pos = nxt+1;
					}
					tb[i][j].push_back(ii(parse(op.substr(pos))));
				}
				else 
					memo[i][j] = stoi(op);
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (j) cout << ' ';
				cout << f(i, j);
			}
			cout << endl;
		}
	}
}