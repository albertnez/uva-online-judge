#include <iostream>
#include <sstream>
using namespace std;
int main() {
	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		ss >> s;
		bool white = true;
		for (int i = 0; i < s.size(); ++i)
			if (s[i] != ' ') white = false;
		
		if (white) s = "";
		int p1 = 0, p2 = 0, digits = 0;
		bool valid = true;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] >= '0' and s[i] <= '9') {
				p1 += s[i]-'0';
				p2 += p1;
				++digits;
			}
			else if (s[i] == 'X') {
				if (digits==9) {
					p1 += 10;
					p2 += p1;
					++digits;
				}
				else valid = false;
			}
			else if (s[i] != '-') {
				valid = false;
			}
		}
		if (valid) valid = (p2%11==0 and digits==10);
		cout << s << " is ";
		if (!valid) cout << "in";
		cout << "correct." << endl;
	}
}