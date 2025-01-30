#include <iostream>
#include <string>
using namespace std;

string str;
int arr[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str;

	for (int i = 0;i < str.length();i++) {

		arr[str[i] - 'a']++;
	}

	for (int i = 0;i < 26;i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	return 0;
}