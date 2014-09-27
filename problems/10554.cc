#include <iostream>
#include <cmath>
using namespace std;

int get(string s) {
	int res = 0;
	for (int i = 0; i < s.size()-1; ++i) {
		res *= 10;
		res += s[i]-'0';
	}
	return res;
}

int main() {
	string s;
	bool finish = false;
	double fp, fc, np, nc;
	fp = fc = np = nc = 0;
    double totalfc = 0, totalc = 0;

	while (cin >> s) {
		if (s == "-") {
			if (finish) {
				cout << round((totalfc/totalc)* 100) << '%' << endl;
				finish = false;
			}

			totalc = totalfc = 0;

		}
		else {
			fc = fp = nc = np = 0;
			finish = true;
			if (s[s.size()-1] == 'C') fc += get(s);
			else if (s[s.size()-1] == '%') fp += get(s);
			else fc += get(s)*9;

			for (int i = 0; i < 3; ++i) {
				cin >> s;
				if (s[s.size()-1] == 'C') nc += get(s);
				else if (s[s.size()-1] == '%') np += get(s);
				
				else nc += get(s)*4;
			}

			cin >> s;
			if (s[s.size()-1] == 'C') nc += get(s);
			else if (s[s.size()-1] == '%') np += get(s);
			else nc += get(s)*7;


 
			double cpp;
			if (fp+np == 0) cpp = 100;
			else  cpp = (fc+nc)/(100-(fp+np));
			totalfc += fp*cpp + fc;
			totalc += fp*cpp + fc + cpp*np + nc;
		}

	}
}