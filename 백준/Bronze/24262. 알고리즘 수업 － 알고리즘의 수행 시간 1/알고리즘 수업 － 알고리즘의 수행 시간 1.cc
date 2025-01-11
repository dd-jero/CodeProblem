#include <iostream>
#include <vector>
using namespace std;
int n, cnt = 0, res = 0;
int arr[500001];
int MenOfPassion(int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	res = MenOfPassion(n);
	cout << cnt << "\n";
	cout << res << "\n";
	return 0;
}

int MenOfPassion(int n) {
	cnt++;
	return arr[n / 2];
}
