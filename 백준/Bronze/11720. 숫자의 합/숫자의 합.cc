#include <iostream>
#include <string>
using namespace std;

int N, res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	string str;
	cin >> str;

	for (int i = 0;i < N;i++) {
		res += (str[i] - '0');
	}

	cout << res << "\n";

	return 0;
}