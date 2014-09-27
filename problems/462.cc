#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int cards[52];
int suits[4];
int stopped[4];

int val(string s) {
	int v = 0;
	if (s[0] >= '2' and s[0] <= '9') v += s[0] - '2';
	else if (s[0] == 'T') v += 8;
	else if (s[0] == 'J') v += 9;
	else if (s[0] == 'Q') v += 10;
	else if (s[0] == 'K') v += 11;
	else if (s[0] == 'A') v += 12;

	if (s[1] == 'D') v += 13;
	else if (s[1] == 'H') v += 26;
	else if (s[1] == 'S') v += 39;
	return v;
}

int main() {
	string card;
	while (cin >> card) {
		bool first = true;
		memset(cards, 0, sizeof(cards));
		memset(suits,0, sizeof(suits));
		memset(stopped,0, sizeof(stopped));
		int points = 0, points2 = 0;

		for (int i = 0; i < 13; ++i) {
			if (!first) cin >> card;
			else first = false;
			++cards[val(card)];
		}

		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 13; ++j) {
				if (cards[i*13+j]) ++suits[i];
			}
		}
		//points
		int aux = 0;
		for (int i = 0; i < 4; ++i) {
			//add
			if (cards[i*13+12]) points+=4;
			if (cards[i*13+11]) points+=3;
			if (cards[i*13+10]) points+=2;
			if (cards[i*13+9]) ++points;
			//substr
			if (cards[i*13+11] and suits[i] <= 1) --points;
			if (cards[i*13+10] and suits[i] <= 2) --points;
			if (cards[i*13+9]  and suits[i] <= 3) --points;
			//add points2
			if (suits[i] == 2) ++aux;
			else if (suits[i] <= 1) aux+=2;
			if (cards[i*13+12] or (cards[i*13+11] and suits[i] >= 2) or (cards[i*13+10] and suits[i] >= 3)) stopped[i] = 1;
		}
		points2 = points;
		points += aux;

		if (points < 14) cout << "PASS" << endl;
		else {
			if (points2 >= 16 and stopped[0] and stopped[1] and stopped[2] and stopped[3]) cout << "BID NO-TRUMP" << endl;
			else {
				cout << "BID ";
				int maxim = max(suits[0], max(suits[1], max(suits[2], suits[3])));
				if (suits[3] == maxim) cout << 'S' << endl;
				else if (suits[2] == maxim) cout << 'H' << endl;
				else if (suits[1] == maxim) cout << 'D' << endl;
				else cout << 'C' << endl;
			}
		}
	}
}