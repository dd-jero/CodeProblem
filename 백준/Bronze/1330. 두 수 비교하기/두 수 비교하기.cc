#include <iostream>
using namespace std;

int A, B;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> A >> B;

	if (A > B) cout << ">" << "\n";
	else if (A < B) cout << "<" << "\n";
	else cout << "==" << "\n";

	return 0;
}