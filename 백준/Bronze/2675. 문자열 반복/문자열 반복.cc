#include <iostream>
#include <string>
using namespace std;

int T, R;
string S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	for (int tc = 0;tc < T;tc++) {
		cin >> R >> S;

		for (int i = 0;i < S.length();i++) {
			for (int r = 0;r < R;r++) {
				cout << S[i];
			}
		}
		cout << "\n";
	}

	return 0;
}