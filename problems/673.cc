#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	getline(cin,s);

	for (int i = 0; i < n; ++i) {
		stack<int> st;
		int j = 0;
		bool pos = true;
		getline(cin,s);
		while (j < s.size() and pos) {
			if (s[j] == ')') {
				if (st.empty())
					pos = false;
				else {
					
					pos = (st.top() == '(');
					st.pop();
				}
			}
			else if (s[j] == ']'){
				if (st.empty())
					pos = false;
				else{
				pos = (st.top() == '[');
					st.pop();
				}
			}
			else 
				st.push(s[j]);

			++j;
		}
		if (pos and st.empty()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}