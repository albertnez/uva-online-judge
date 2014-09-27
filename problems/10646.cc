#include <iostream>
#include <vector>
using namespace std;

int val(string s) { return (s[0] >= '2' and s[0] <= '9' ? s[0]-'2':10); }

int main() {
	int n, c = 0;
	cin >> n;
	while (n--) {
		vector<string> cards(52);
		for (int i = 0; i < 52; ++i) cin >> cards[i];
		int pt = 51-25, score = 0;
		for (int i = 0; i < 3; ++i) {
			score += val(cards[pt]);
			pt -= 10-val(cards[pt])+1;
		}
		string sol = (score-1 > pt ? cards[score+(51-25-pt)-1] : cards[score-1]);		
		cout << "Case " << ++c << ": " << sol << endl;
	}
}