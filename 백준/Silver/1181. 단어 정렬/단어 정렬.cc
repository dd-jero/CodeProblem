#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N;
map<string, int> dict;

bool cmp(const pair<string,int>&a, const pair<string,int>&b) {

	// 길이 같으면 사전 순 
	if (a.second == b.second) return a.first < b.first;

	// 길이 순
	return a.second < b.second;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	string str;
	for (int i = 0;i < N;i++) {
		cin >> str;
		if (dict.count(str) == 0) dict.insert({ str, str.length() });
	}

	// 중복 방지 위해 map, map을 벡터로 만들어 정렬
	vector<pair<string, int>> vec(dict.begin(), dict.end());
	sort(vec.begin(), vec.end(), cmp);

	for (auto s : vec) {
		cout << s.first << "\n";
	}


	return 0;
}