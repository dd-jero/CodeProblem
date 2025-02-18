#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, K, res = 0;
vector<int> idx_p;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	string str;
	cin >> str;

	for (int i = 0;i < str.length();i++) {
		if (str[i] == 'P') { // 사람이면 
			idx_p.push_back(i);
		}
	}

	for (int i = 0;i < idx_p.size();i++) {
		for (int j = idx_p[i] - K ;j <= idx_p[i] + K;j++) {
			if (j < 0 || j >= N) continue;

			if (str[j] == 'H') {
				res++;
				str[j] = '0';
				break;
			}
		}
	}

	cout << res << "\n";
	

	return 0;
}