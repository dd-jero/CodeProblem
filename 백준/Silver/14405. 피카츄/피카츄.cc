#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str;

	while (!str.empty()) {

		// 지워지만 앞으로 땡겨져서 인덱스 0됨
		if (str[0] == 'p' && str[1] == 'i') {
			str.erase(0, 2);
		}
		else if (str[0] == 'k' && str[1] == 'a') {
			str.erase(0, 2);
		}
		else if (str[0] == 'c' && str[1] == 'h' && str[2] == 'u') {
			str.erase(0, 3);
		}
		else { // 피카츄가 발음 못하면 루프 종료
			break;
		}
	}


	if (str.empty()) cout << "YES" << "\n";
	else cout << "NO" << "\n";

	return 0;
}