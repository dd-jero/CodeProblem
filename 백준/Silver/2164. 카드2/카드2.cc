#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> card;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1;i <= N;i++) {
		card.push(i);
	}

	while (card.size() > 1) {

		card.pop();

		int c = card.front();
		card.pop();
		card.push(c);
	}

	cout << card.front() << "\n";

	return 0;
}