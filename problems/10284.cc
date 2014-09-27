#include <iostream>
#include <cstring>
using namespace std;

int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dj[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int table[8][8];

void rook(int n, int m) {
	int i;
	//left
	i = m-1;
	while (i >= 0 and table[n][i] != -1) table[n][i--] = true;
	i = m+1;
	while (i < 8 and table[n][i] != -1) table[n][i++] = true;
	i = n-1;
	while (i >= 0 and table[i][m] != -1) table[i--][m] = true;
	i = n+1;
	while (i < 8 and table[i][m] != -1) table[i++][m] = true;
}

void bishop(int n, int m) {
	int i = 1;
	while (n+i < 8 and m+i < 8 and table[n+i][m+i] != -1) {
		table[n+i][m+i] = true;
		++i;
	}
	i = 1;
	while (n-i >= 0 and m+i < 8 and table[n-i][m+i] != -1) {
		table[n-i][m+i] = true;
		++i;
	}
	i = 1;
	while (n-i >= 0 and m-i >= 0 and table[n-i][m-i] != -1) {
		table[n-i][m-i] = true;
		++i;
	}
	i = 1;
	while (n+i < 8 and m-i >= 0 and table[n+i][m-i] != -1) {
		table[n+i][m-i] = true;
		++i;
	}
}

void knight(int n, int m) {
	if (n+2 < 8 and m+1 < 8 	and table[n+2][m+1] != -1) table[n+2][m+1] = true;
	if (n+2 < 8 and m-1 >= 0	and table[n+2][m-1] != -1) table[n+2][m-1] = true;
	if (n+1 < 8 and m+2 < 8  	and table[n+1][m+2] != -1) table[n+1][m+2] = true;
	if (n+1 < 8 and m-2 >= 0 	and table[n+1][m-2] != -1) table[n+1][m-2] = true;
	if (n-2 >= 0 and m+1 < 8 	and table[n-2][m+1] != -1) table[n-2][m+1] = true;
	if (n-2 >= 0 and m-1 >= 0 	and table[n-2][m-1] != -1) table[n-2][m-1] = true;
	if (n-1 >= 0 and m+2 < 8 	and table[n-1][m+2] != -1) table[n-1][m+2] = true;
	if (n-1 >= 0 and m-2 >= 0 	and table[n-1][m-2] != -1) table[n-1][m-2] = true;
}

void queen(int n, int m) {
	rook(n,m);
	bishop(n,m);
}

void king(int n, int m) {
	for (int i = 0; i < 8; ++i) {
		if (n+di[i] >= 0 and n+di[i] < 8 and m+dj[i] >= 0 and m+dj[i] < 8 and table[n+di[i]][m+dj[i]] != -1) table[n+di[i]][m+dj[i]] = true;
	}
}

void pawn(int n, int m, bool w) {
	if (w and n-1 >= 0) {
		if (m+1 < 8 and table[n-1][m+1] != -1) table[n-1][m+1] = true;
		if (m-1 >= 0 and table[n-1][m-1] != -1) table[n-1][m-1] = true;
	}
	else if (!w and n+1 < 8) {
		if (m+1 < 8 and table[n+1][m+1] != -1) table[n+1][m+1] = true;
		if (m-1 >= 0 and table[n+1][m-1] != -1) table[n+1][m-1] = true;
	}
}


int main() {
	string s;
	while (cin >> s) {
		memset(table, false, sizeof(table));
		int n = 0, m = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] >= '1' and s[i] <= '8') m += s[i]-'0'-1;
			else if (s[i] == 'k' or s[i] == 'K') table[n][m] = -1;
			else if (s[i] == 'r' or s[i] == 'R') table[n][m] = -1;
			else if (s[i] == 'q' or s[i] == 'Q') table[n][m] = -1;
			else if (s[i] == 'b' or s[i] == 'B') table[n][m] = -1;
			else if (s[i] == 'n' or s[i] == 'N') table[n][m] = -1;
			else if (s[i] == 'p' or s[i] == 'P') table[n][m] = -1;
			if (s[i] != '/') ++m;
			n+=m/8;
			m%=8;
		}

		n = m = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] >= '1' and s[i] <= '8') m += s[i]-'0'-1;
			else if (s[i] == 'k' or s[i] == 'K') king(n,m);
			else if (s[i] == 'r' or s[i] == 'R') rook(n,m);
			else if (s[i] == 'q' or s[i] == 'Q') queen(n,m);
			else if (s[i] == 'b' or s[i] == 'B') bishop(n,m);
			else if (s[i] == 'n' or s[i] == 'N') knight(n,m);
			else if (s[i] == 'p' or s[i] == 'P') pawn(n,m,s[i]=='P');
			if (s[i] != '/') ++m;
			n+=m/8;
			m%=8;
		}
		
		int t = 0;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (table[i][j] == 0) ++t;
				//cout << (table[i][j] ? 'X' : ' ');
			}
			//cout << endl;
		}
		cout <<  t << endl;
	}
}