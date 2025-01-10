#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	queue<int> q;
	string cmd;
	int num;

	for (int i = 0;i < n;i++) {
		cin >> cmd;

		if (cmd == "push") {
			cin >> num;
			q.push(num);
		}
		else if (cmd == "pop") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (cmd == "size") {
			cout << q.size() << "\n";
		}
		else if (cmd == "empty") {
			if (q.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (cmd == "front") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (cmd == "back") {
			if (q.empty()) {
				cout <<  -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
	}
	return 0;
}