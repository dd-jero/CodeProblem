#include <iostream>
#include <string>
using namespace std;

string str; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str;

	for (int i = 0;i < str.size();i++) {
		if (isupper(str[i])) {
			str[i] = tolower(str[i]);
		}
		else {
			str[i] = toupper(str[i]);
		}
	}

	cout << str << "\n";

	return 0;
}