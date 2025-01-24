#include <iostream>
#include <set>
#include <string>
using namespace std;

int n, game;
set<string> people;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	char tmp;
	cin >> n >> tmp;

	if (tmp == 'Y') game = 1;
	else if (tmp == 'F') game = 2;
	else game = 3;

	string p;
	for (int i = 0;i < n;i++) {
		cin >> p;

		if (people.count(p) == 0) {
			people.insert(p);
;		}
	}

	cout << people.size() / game << "\n";

	return 0;
}