#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
	
int main(void) {
	
	int N = 0; // 정수 개수
	int max_val = -1000000; // 최댓값 갱신 위한 변수
	int min_val = 1000000; // 최솟값 갱신 위한 변수 

	scanf("%d", &N);


	for (int i = 0;i < N;i++) {
		int num;
		scanf("%d", &num);

		if (max_val < num) max_val = num;
		if (min_val > num) min_val = num;
	}


	printf("%d %d", min_val, max_val);
	
	return 0;
}