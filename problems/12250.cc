#include <iostream>
using namespace std;
string words[6] = {"HELLO","HOLA","HALLO","BONJOUR","CIAO","ZDRAVSTVUJTE"}, 
lang[6] = {"ENGLISH","SPANISH","GERMAN","FRENCH","ITALIAN","RUSSIAN"};

int main() {
	string s;
	int n = 0, i;
	while (cin >> s and s != "#") {
		cout << "Case " << ++n << ": ";
		for (i = 0; i < 6; ++i)
			if (s == words[i]) {
				cout << lang[i] << endl;
				break;
			}
		if (i == 6) cout << "UNKNOWN" << endl;
	}
}