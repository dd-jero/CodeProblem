#include <iostream>
using namespace std;

int N; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1;i <= 9;i++) {
		cout << N << " * " << i << " = " << N * i << "\n";
	}

	return 0;
}