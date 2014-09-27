#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

int main() {
	int n;
	while (cin >> n and n != -1) {
		string s;
		cin >> s;
		vb v(26, false), used(v);
		int letters = 0, tries = 7;
		for (int i = 0; i < s.size(); ++i) {
			if (!v[s[i]-'a']) {
				v[s[i]-'a'] = true;
				++letters;
			}
		}
		cin >> s;
		int i = 0;
		while (i < s.size() and tries and letters) {
			int ind = s[i]-'a';
			if (!used[ind]) {
				used[ind] = true;
				if (v[ind]) --letters;
				else --tries;
			}
			++i;
		}
		cout << "Round " << n << endl;
		if (!tries) cout << "You lose." << endl;
		else if (!letters) cout << "You win." << endl;
		else cout << "You chickened out." << endl;
	}
}