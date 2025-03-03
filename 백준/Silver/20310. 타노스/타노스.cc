#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string str;
	cin >> str;

	int one_cnt = 0, zero_cnt = 0;

	for (int i = 0;i < str.size();i++) {
		if (str[i] == '0') zero_cnt++;
		else one_cnt++;
	}

	zero_cnt /= 2;
	one_cnt /= 2;

	// 0은 뒤에서 부터 제거
	while (zero_cnt != 0) {
		int idx = str.rfind('0');
		if (idx != -1) { // 위치 찾으면
			str.erase(idx, 1);
			zero_cnt--;
		}
	}

	// 1은 앞에서 부터 제거
	while (one_cnt != 0) {
		int idx = str.find('1');
		if (idx != -1) { // 위치 찾으면
			str.erase(idx, 1);
			one_cnt--;
		}
	}

	cout << str << "\n";

	return 0;
}