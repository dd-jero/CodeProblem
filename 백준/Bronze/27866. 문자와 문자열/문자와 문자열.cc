#include <iostream>
#include <string>
using namespace std;

string str;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> str >> N;

	cout << str[N - 1] << "\n";

	return 0;
}