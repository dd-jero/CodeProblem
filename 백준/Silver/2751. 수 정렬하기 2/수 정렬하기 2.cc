#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> numbers;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	int num;
	for (int i = 0;i < N;i++) {
		cin >> num;
		numbers.push_back(num);
	}

	sort(numbers.begin(), numbers.end());

	for (int n : numbers) {
		cout << n << "\n";
	}
	 
	return 0;
}