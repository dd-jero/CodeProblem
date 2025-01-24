#include <iostream>
#include <string>
using namespace std;

string str;
int cnt_t, cnt_f;
bool flag, res;

bool Check(char c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		cin >> str;

		if (str == "end") break; // 종료 조건 

		cnt_t = 0, cnt_f = 0, res = false, flag = false;

		for (int i = 0;i < str.length();i++) {
			if (Check(str[i])) { // 모음이면
				cnt_t++;
				cnt_f = 0;

				if (cnt_t == 3) { // 모음이 연속 3개이면
					res = true;
					break;
				}
			}
			else { // 자음이면 
				cnt_f++;
				cnt_t = 0;

				if (cnt_f == 3) { // 자음이 연속 3개이면 
					res = true;
					break;
				}
			}

			if (i > 0 && !(str[i] == 'e' || str[i] == 'o') && (str[i] == str[i - 1])) { // 같은 글자가 연속으로 두번 오면 (ee, oo 제외)
				res = true;
				break;
			}
		}

		if (!res && flag) cout << "<" << str << ">" << " is " << "acceptable." << "\n";
		else cout << "<" << str << ">" << " is " << "not acceptable." << "\n";

	}
	return 0;
}

bool Check(char c) { // 모음이면 true, 아니면 false

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		flag = true;
		return true;
	}
	else {
		return false;
	}
}