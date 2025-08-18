#include <iostream>
#include <string>
#include <stack>
using namespace std;

int T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++) {
		stack<char> st;
		string str; 

		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			if (st.empty()) st.push(str[i]);
			else if (str[i] == '(') st.push('(');
			else if (str[i] == ')') {
				if (st.top() == '(') st.pop();
				else st.push(')');
			}
		}

		if (st.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";

	}

	return 0;

}