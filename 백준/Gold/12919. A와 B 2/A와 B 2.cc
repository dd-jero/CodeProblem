#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

void dfs(string cur_str);

string S, T;
int res = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> S >> T;

	dfs(T); // T에서 부터 제거 하면서 S 만들기 

	cout << res << "\n";

	return 0;
}

void dfs(string cur_str) {

	// 종료 조건: 같으면 
	if (cur_str == S) {
		res = 1;
		return;
	}
	
	// 가지치기: 현재 길이가 S 길이보다 작으면
	if (cur_str.length() <= S.length()) {
		return;
	}

	// 원본 문자열 손상 방지 
	string tmp = cur_str; 

	// 마지막 단어가 A면
	if (tmp.back() == 'A') {
		tmp.pop_back();
		dfs(tmp);
	}

	tmp = cur_str;
	// 제일 앞 단어가 B이면 
	if (tmp.front() == 'B') {
		reverse(tmp.begin(), tmp.end());
		tmp.pop_back();
		dfs(tmp);
	}
}