#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int position[25];
int blocks[25][25];
int items[25];


void remove(int p, int x) {
	int i = items[p]-1;
	while (blocks[p][i] != x) {
		int t = blocks[p][i];
		blocks[t][items[t]] = t;
		++items[t];
		--items[p];
		position[t] = t;
		blocks[p][i] = -1;
		--i;
	}
}

void move(int a, int b, int x) {
	int i = 0;
	while (blocks[a][i] != x) ++i;
	int lim = items[a];
	while (i < lim) {
		int y = blocks[a][i];
		blocks[a][i] = -1;
		blocks[b][items[b]] = y;
		++items[b];
		position[y] = b;
		--items[a];
		++i;
	}
}


int main() {
	memset(blocks, -1, sizeof(blocks));
	for (int i = 0; i < 25; ++i) {
		position[i] = i;
		blocks[i][0] = i;
		items[i] = 1;
	}
	int n;
	cin >> n;
	string op1, op2;
	int a,b;
	while (cin >> op1 and op1 != "quit") {
		cin >> a >> op2 >> b;
		if (position[a] != position[b]) {
			if (op1 == "move") remove(position[a], a);
			if (op2 == "onto") remove(position[b], b);
			move(position[a], position[b], a);

		}
	}
	for (int i = 0; i < n; ++i) {
		cout << i << ':';
		for (int j = 0; j < items[i]; ++j) cout << ' ' << blocks[i][j];
		cout << endl;
	}
}