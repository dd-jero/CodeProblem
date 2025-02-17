#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str;

	cin >> str;

	int idx = 0, res = 1; // 지우고 남은 수의 인덱스, 1부터 3000까지 
	bool flag = false;

	while (idx != str.length()) {
		string str_num = to_string(res); // int to string 

		for (int i = 0;i < str_num.length();i++) { // N의 길이만큼 돌면서 비교
			if (str[idx] == str_num[i]) {
				idx++; // 다음 위치의 숫자로 

				if (idx >= str.length()) { // 지우고 남은 수를 모두 다 확인하면 
					flag = true;
					break;
				}
			}
		}

		if (flag) break;

		res++; // 종료 안되면 N을 1 증가 
		
	}

	cout << res << "\n";

	return 0;
}