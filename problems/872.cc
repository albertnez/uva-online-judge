#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<vi> vii;

map<char,int> mp;
vi res;
vii adj;
vc letters;
bool posible;

void f(vi& in,int p) {
	if (p == in.size()) {
		posible = true;
		for (int i = 0; i < p; ++i) cout << (i == 0 ? "" : " ") << letters[res[i]];
		cout << endl;
	}
	for (int i = 0; i < in.size(); ++i) {
		if (in[i] == 0) {
			in[i] = -1;
			for (int j = 0; j < adj[i].size(); ++j) --in[adj[i][j]];
			res[p] = i;
			f(in, p+1);
			for (int j = 0; j < adj[i].size(); ++j) ++in[adj[i][j]];
			in[i] = 0;
		}
	}
}

int main() {
	
	int cases; cin >> cases;
	string line; getline(cin,line);
	while (cases--) {
		posible = false;
		getline(cin,line);
		getline(cin,line);
		stringstream ss(line);
		char c;
		letters = vector<char>();
		while(ss>>c) letters.push_back(c);
		sort(letters.begin(), letters.end());
		int n = letters.size();
				
		vi ind(26);
		for (int i = 0; i < n; ++i) ind[ letters[i]-'A' ] = i; 
		res = vi(n);
		adj = vii(n);
		vi in(n, 0);
		
		//Get edges
		getline(cin,line);
		ss.clear();
		ss.str(line);
		string edge;
		while (ss>>edge) {
			adj[ ind[edge[0]-'A'] ].push_back( ind[edge[2]-'A'] );
			++in[ind[edge[2]-'A']];
		}

		f(in, 0);
		if (!posible) cout << "NO" << endl;
		if (cases) cout << endl;
		
	}
}
