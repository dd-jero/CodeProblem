#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> vec;
int visited[101];
vector<int> res;

void dfs(int cur, int start);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	vec.resize(N + 1, vector<int>(1)); // 1 ~ N

	int num;
	for (int i = 1;i <= N;i++) {
		cin >> num;
		vec[i][0] = num;
	}

	for (int i = 1;i <= N;i++) {
		dfs(i, i);
		memset(visited, false, sizeof(visited));
	}


	sort(res.begin(), res.end());

	cout << res.size() << "\n";
	for (int i = 0;i < res.size();i++) {
		cout << res[i] << "\n";
	}

	return 0;
}

void dfs(int cur, int start) {

	if (visited[cur]) {

		if (start == cur){
			res.push_back(cur);
		}

		return;
	}

	visited[cur] = true;
	dfs(vec[cur][0], start);
	
}