#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

int main(void) {

	int T = 0; // 테케

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {

		int num;
		scanf("%d", &num);

		for (int j = 0; j < 32; j++) { // int형이어서 32비트
			if (num & (1 << j)) { // j번째 위치가 1이면 출력 
				printf("%d ", j);
			}
		}
		printf("\n");
	}

	return 0;
}