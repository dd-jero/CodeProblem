#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, K, res = 0;
vector<int> idx_p, idx_h;
bool visited[20001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	string str;
	cin >> str;

	for (int i = 0;i < str.length();i++) {
		if (str[i] == 'H') { // 사람이면 
			idx_p.push_back(i);
		}
		else { // 햄버거이면 
			idx_h.push_back(i);
		}
	}

	for (int i = 0;i < idx_p.size();i++) {
		for (int j = 0;j < idx_h.size();j++) {
			if (idx_h[j] >= idx_p[i] - K && idx_h[j] <= idx_p[i] + K && !visited[j]) {
				res++;
				visited[j] = true;
				break;
			}
		}
	}

	cout << res << "\n";
	

	return 0;
}