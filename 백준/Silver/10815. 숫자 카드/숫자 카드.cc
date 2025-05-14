#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M; // 가지고 있는 개수, 확인해야할 개수 
vector<int> numbers, res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	int num;
	for (int i = 0;i < N;i++) {
		cin >> num;
		numbers.push_back(num);
	}


	// 가지고 있는 수 오름차순 정렬 
	sort(numbers.begin(), numbers.end());

	cin >> M;
	res.assign(M, 0);

	for (int i = 0;i < M;i++) {
		cin >> num; 

		int start = 0;
		int end = N - 1;

		while (start<=end) {

			int mid = (start + end) / 2;

			if (numbers[mid] < num) start = mid + 1;
			else if (numbers[mid] > num) end = mid - 1;
			else { // 가지고 있다!
				res[i] = 1;
				break;
			}
		}
	}

	for (int ele : res) {
		cout << ele << " ";
	}

	return 0;
}