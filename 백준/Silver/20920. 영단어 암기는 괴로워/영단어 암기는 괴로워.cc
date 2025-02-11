#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M; // 단어의 개수, 외울 단어의 길이 기준 
map<string, int> m; // 기본적으로 key의 알파벳 순으로 출력 확인 

bool Compare(pair<string,int> e1, pair<string,int> e2) {

	// 우선순위 1 빈도수
	if(e1.second != e2.second){
		return e1.second > e2.second;
	}

	// 우선순위 2 단어 길이
	if (e1.first.length() != e2.first.length()) {
		return e1.first.length() > e2.first.length();
	}

	// 우선순위 3 사전순
	return e1.first < e2.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	
	string word;
	for (int i = 0;i < N;i++) {
		cin >> word;

		// 해당 단어의 길이가 M 미만이면 무시
		if (word.length() < M) continue;

		// 해당 단어가 이미 map에 존재하는지
		if (m.count(word) > 0) m[word]++; // 해당 요소의 값 1증가 
		else m[word] = 1;
	}

	vector<pair<string, int>> vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), Compare); 

	// 반복자 활용 map의 요소 출력 
	/*for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << "\n";
	}*/

	for (const auto& it : vec) {
		cout << it.first << "\n";
	}
	return 0;
}