#include <iostream>
#include <string>
#include <map>
using namespace std;

int t;
string str;
map<string, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int i = 0;i < t;i++) {
		cin >> str;

		for (int i = 0;i < str.size();i++) {
			if (str[i] == '.') { // . 포험 이전 문자는 삭제 
				str.erase(0, i+1);
			}
		}

		if (m.count(str) == 0) { // 맵에 해당 확장자가 없으면 새로 추가 
			m.insert({ str, 1 });
		}
		else { // 해당 확장자가 있으면 value 1 증가 
			m.at(str)++;
		}
	}

	for (auto i = m.begin(); i != m.end(); i++) {
		cout << i->first << " " << i->second << "\n";
	}

	return 0;

}