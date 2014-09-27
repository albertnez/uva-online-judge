#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <typeinfo>
using namespace std;
typedef vector<int> vi;


vi encode(string s) {
	vi v(26, 0);
	for (int i = 0; i < s.size(); ++i) {
		v[s[i] - 'a']++;
	}
	return v;
}

int main() {
	map<vi,list<string> > m;
	string s;
	list<string> l;
	while (getline(cin,s) and s != "XXXXXX")
		m[encode(s)].push_back(s);

	for (map<vi,list<string> >::iterator it = m.begin(); it != m.end(); ++it) {
		it->second.sort();
	}

	while (getline(cin,s) and s != "XXXXXX")
	{
		l = m[encode(s)];
		if (l.size() > 0) {
			for (list<string>::const_iterator it = l.begin(); it != l.end(); ++it)
				cout << *it << endl; 
		}
		else 
			cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}
}