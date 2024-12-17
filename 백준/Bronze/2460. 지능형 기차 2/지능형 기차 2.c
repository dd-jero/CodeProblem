#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int total_num = 0; // 현재 기차 안의 총인원 
	int max_num = 0; // 기차 안에서 최대 인원
	int out_num, in_num; // 내리는 인원 수, 타는 인원 수 

	for (int i = 0; i < 10; i++) {
		scanf("%d %d", &out_num, &in_num);

		// 먼저 내리고 탐
		total_num = total_num - out_num + in_num;

		if (total_num > max_num) {
			max_num = total_num;
		}
	}

	printf("%d", max_num);

	return 0;
}