#include <iostream>
using namespace std;

int N;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1;i <= N;i++) {
		for (int j = 0;j < i;j++) {
			cout << '*';
		}
		cout << "\n";
	}

	return 0;
}