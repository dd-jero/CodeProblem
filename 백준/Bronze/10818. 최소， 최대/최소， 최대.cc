#include <iostream>
#include <string>
using namespace std;

int N, min_num = 1000001, max_num = -1000001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	int num;
	for (int i = 0;i < N;i++) {
		cin >> num;
		
		if (num > max_num) max_num = num;
		if (num < min_num) min_num = num;
	}

	cout << min_num << " " << max_num << "\n";
	
	return 0;
}