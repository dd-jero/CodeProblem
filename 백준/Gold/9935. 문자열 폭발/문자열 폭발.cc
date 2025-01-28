#include <iostream>
#include <string>
using namespace std;

string str, bomb;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str >> bomb;
	int len_str = str.length();
	int len_bomb = bomb.length();

	string tmp= ""; // 한글자씩 추가하면서 폭발 문자열과 확인하기 위함.
	for(int idx=0;idx < len_str; idx++) {

		tmp += str[idx]; 
		if (tmp.length() >= len_bomb) { // 폭발 문자열의 길이와 같거나 크면 

			bool is_bomb = true; // 폭발이 일어날지 여부 

			for (int i = 0;i < len_bomb;i++) {
				if (tmp[tmp.length() - len_bomb + i] != bomb[i]) { // 해당 단어와 폭발 문자열의 단어가 다르면 
					is_bomb = false;
					break;
				}
			}

			if (is_bomb) { // 폭발 문자열과 같으면 
				tmp.erase(tmp.length() - len_bomb, len_bomb); // 첫번째 인자의 위치부터 두번째 인자의 길이만큼 제거 
			}
		}
	}

	if (tmp.empty()) { /// 남아있는 문자 없는 경우
		cout << "FRULA" << "\n";
	}
	else {
		cout << tmp << "\n";
	}

	return 0;
}