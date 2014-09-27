#include <iostream>
using namespace std;
int main() {
	int cas = 0, n, p;
	while (cin >> n >> p and n > 0 and p > 0) {
		string s;
		getline(cin,s);
		for (int i = 0; i < n; ++i)
			getline(cin,s);
		string bestname;
		double bestprice = 1000000000;
		int bestreq = -1;

		for (int j = 0; j < p; ++j) {
			string name;
			double price;
			int req;
			getline(cin, name);
			cin >> price >> req;
			getline(cin,s);
			for (int k = 0; k < req; ++k)
				getline(cin,s);
			if (req > bestreq or (req == bestreq and price < bestprice)) {
				bestname = name;
				bestprice = price;
				bestreq = req;
			}
		}
		if (cas > 0) cout << endl;
		cout << "RFP #" << ++cas << endl << bestname << endl;
	}	
}