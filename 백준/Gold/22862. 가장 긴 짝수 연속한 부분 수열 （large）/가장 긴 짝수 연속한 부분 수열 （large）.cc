#include <iostream>
using namespace std;

int N, K, odd_cnt = 0, res = 0; // 수열 길이, 최대 삭제 횟수, 홀수 개수
int arr[1000001];

bool IsOdd(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	int left = 0, right = 0;
	while (right < N) { // right를 끝까지 이동하면서 확인 
		
		if (IsOdd(arr[right])) odd_cnt++; // 해당 right 요소가 홀수면

		// left 인덱스를 이동 시켜 홀수 수를 최대 삭제 가능 수 이하로 줄이기  
		while (odd_cnt > K) {

			if (IsOdd(arr[left])) odd_cnt--; // 현재 left 요소가 홀수면 

			// left 인덱스 이동
			left++;
			
		}

		// 더 길다면 갱신
		res = res < (right - left + 1 - odd_cnt) ? (right - left + 1 - odd_cnt) : res;
		right++;
		
	}

	cout << res << "\n";

	return 0;
}

bool IsOdd(int num) {
	if (num % 2 == 0) return false; // 짝수
	return true; // 홀수
}