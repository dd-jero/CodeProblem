#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm> // sort 메서드 위해
#include <iostream>
using namespace std;

int arr[9];
vector<int> vec;
void recur(int idx, vector<int> memnbers); // 함수의 원형을 반드시 맨 위에 선언해주어야함!

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	// 입력 
	for (int i = 0;i < 9;i++) {
		//scanf("%d", &arr[i]);
		cin >> arr[i];
	}
	
	// 재귀 시작 
	// 파라미터: 인덱스, 현재 고려한 난쟁이들의 키 벡터 
	recur(0, vec);

	return 0; 
}

void recur(int idx, vector<int> members) {

	if (members.size() == 7) { // 7명의 난쟁이이면
			
		int sum_mem = 0;

		// 키 합 구하기 
		for (int num : members) {
			sum_mem += num;
		}

		if (sum_mem == 100) { // 키의 합이 100이 되면 
			sort(members.begin(), members.end());

			for (int num : members) {
				//printf("%d\n", num);
				cout << num << "\n";
			}
			exit(0); // 종료 
			
		}
		else { // 키의 합의 100이 아니면
			return; // 다시 되돌아감
		}
	}

	for (int i = idx; i < 9;i++) {

		members.push_back(arr[i]);

		recur(idx+1, members);

		// 되돌아 왔을 때 마지막 요소 제거 
		members.pop_back();
	}
}