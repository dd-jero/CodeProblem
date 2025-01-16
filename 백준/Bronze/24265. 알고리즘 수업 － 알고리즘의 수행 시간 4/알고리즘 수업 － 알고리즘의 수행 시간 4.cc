#include <iostream>
using namespace std;

int n;
long long cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n - 1;i++) {
		for (int j = i + 1;j <= n;j++) {
			cnt++;
		}
	}

	cout << cnt << "\n" << 2;
	
	return 0;
}