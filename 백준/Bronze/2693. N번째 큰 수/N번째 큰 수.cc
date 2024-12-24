#include <iostream>
#include <algorithm>
using namespace std;

int T;
int arr[10];


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	// 테케 수
	cin >> T;

	for (int i = 0; i < T; i++) {

		// 배열 요소 10개 입력 
		for (int j = 0; j < 10; j++) {
			cin >> arr[j];
		}

		sort(arr, arr + 10); // 배열의 메모리는 연속적이어서 이러한 형태 가능함.

		cout << arr[7] << "\n";
	} 
	
	return 0;
}