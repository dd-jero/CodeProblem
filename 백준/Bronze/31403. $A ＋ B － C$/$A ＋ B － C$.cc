#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	cout << A + B - C << "\n";

	cout << stoi((to_string(A) + to_string(B))) - C << "\n";

	return 0;
}