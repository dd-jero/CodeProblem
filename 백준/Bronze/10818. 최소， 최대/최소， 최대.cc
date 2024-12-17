#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std; 

int main(void) {
	
	int N = 0; // 정수 개수

	scanf("%d", &N);

	vector<int> vec;

	for (int i = 0;i < N;i++) {
		int tmp;
		scanf("%d", &tmp);
		vec.push_back(tmp);
	}

	// 최소값
	int min_idx = min_element(vec.begin(), vec.end()) - vec.begin();
	int min_val = *min_element(vec.begin(), vec.end());

	// 최대값 
	int max_idx = max_element(vec.begin(), vec.end()) - vec.begin();
	int max_val = *max_element(vec.begin(), vec.end());

	printf("%d %d", min_val, max_val);

	return 0;
}