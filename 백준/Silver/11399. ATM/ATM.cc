#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, res = 0;
vector<int> p;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	int time;
	for (int i = 0;i < N;i++) {
		cin >> time;
		p.push_back(time);
	}

	sort(p.begin(), p.end());

	int cur_time = 0;
	for (int i = 0;i < N;i++) {
		cur_time += p[i];
		res += cur_time; 
	}

	cout << res << "\n";
	return 0;
}