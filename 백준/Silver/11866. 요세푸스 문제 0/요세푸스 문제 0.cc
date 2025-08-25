#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int N, K; // N명의 사람, K 번째 사람 제거
queue<int> q; 
vector<int> res; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		if (i % K == 0) res.push_back(i);
		else q.push(i);
	}

	int cur = N + 1;

	while (!q.empty()) {

		int front_people = q.front();
		q.pop();

		if (cur % K == 0) {
			
			res.push_back(front_people);
		}
		else {
			q.push(front_people);
		}

		cur++;
	}
	
	cout << "<";
	for (int i = 0; i < N; i++) {
		if (i == N - 1) cout << res[i] << ">" << "\n";
		else cout << res[i] << ", ";
	}

	return 0;
}