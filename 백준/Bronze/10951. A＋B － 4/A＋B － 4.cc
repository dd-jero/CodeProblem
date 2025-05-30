#include <iostream>
#include <string>
using namespace std;

int A, B;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while (cin >> A >> B) {
		cout << A + B << "\n";
	}
	
	return 0;
}