#include <iostream>
#include <string>
using namespace std;

int N, numbers[10001], cur_size = 0;

void push(int X);
int pop();
int size();
bool empty();
int top();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	string cmd; 
	int X;
	for (int i = 0;i < N;i++) {
		cin >> cmd;

		if (cmd == "push") {
			cin >> X;
			push(X);
			cur_size++;
		}
		else if (cmd == "pop") {
			cout << pop() << "\n";

			if (cur_size > 0) cur_size--;
		}
		else if (cmd == "size") cout << size() << "\n";
		else if (cmd == "empty") cout << empty() << "\n";
		else cout << top() << "\n";
	}

	return 0;
}

void push(int X) {
	numbers[cur_size] = X;
}

int pop() {
	if (cur_size == 0) return -1;
	
	return numbers[cur_size-1];
}

int size() {
	return cur_size;
}

bool empty() {
	if (cur_size == 0) return true;
	return false;
}

int top() {
	if (cur_size == 0) return -1;
	return numbers[cur_size-1];
}