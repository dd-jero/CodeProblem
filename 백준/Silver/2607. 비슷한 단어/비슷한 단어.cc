#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, res = 0;
int arr[27];
//map<char, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	string str;
	for (int i = 0;i < N;i++) {
		//map<char, int> cur;
		int cur[27];
		cin >> str;

		if (i == 0) {
			for (int i = 0;i < str.length();i++) {
				arr[str[i]-'A']++;
			}
		}
		else {
			copy(arr, arr + 27, cur);

			for (int i = 0;i < str.length();i++) {
				cur[str[i]-'A']--;
			}

			// 한 문자가 더해짐 -> 특정 문자 값: -1, 한 문자 빼짐 -> 특정 문자 값: 1, 한문자 변경 -> 특정 문자 값: 1, 새로운 문자 값: -1 
			// 즉, 특정 문자의 값이 -1, 1인 것이 한 번씩 까지는 허용 
			bool plus = false, minus = false, conti = false;

			for (int i = 0;i < 27;i++) {

				if (cur[i] == 1) {
					if (plus) {
						conti = true;
						break;
					}
					else {
						plus = true;
					}
				}
				else if (cur[i] == -1) {
					if (minus) {
						conti = true;
						break;
					}
					else {
						minus = true;
					}
				}
				else if (cur[i] == 0) {
					continue;
				}
				else {
					conti = true;
					break;
				}
			}

			if (!conti) {
				res++;
			}

		}
	}

	cout << res << "\n";

	return 0;
}