#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (1) {
		cin >> num;

		if (num == "0") break;

		// 해당 단어의 길이가 짝수/홀수 여부에 따라 달라짐.
		int mid_idx = num.size() % 2 == 0 ? num.size() / 2 : num.size() / 2 + 1;
		string a = num.substr(0, mid_idx);

		mid_idx = num.size() / 2;
		string b = num.substr(mid_idx, num.size());

		mid_idx = num.size() % 2 == 0 ? num.size() / 2 : num.size() / 2 + 1;
		reverse(b.begin(), b.begin() + mid_idx);

		if (a == b) cout << "yes" << "\n";
		else cout << "no" << "\n";

	}
	return 0;
}