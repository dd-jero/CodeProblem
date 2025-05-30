#include <iostream>
#include <string>
using namespace std;

int T, A, B;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	for (int t = 0;t < T;t++) {
		cin >> A >> B;
		cout << A + B << "\n";
	}
	
	return 0;
}