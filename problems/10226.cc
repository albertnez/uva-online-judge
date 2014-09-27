#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main() {
	int cases; cin >> cases;
	string s; getline(cin,s); getline(cin,s);
	while (cases--) {
		int total = 0;
		map<string,int> m;
		while (getline(cin,s) and s != "") {
			++m[s];
			++total;
		}
		for (map<string,int>::const_iterator it = m.begin(); it != m.end(); ++it) {
			printf("%s %.4lf\n", it->first.c_str(), double(it->second)/total*100);
		}
		if (cases) printf("\n");
	}
}