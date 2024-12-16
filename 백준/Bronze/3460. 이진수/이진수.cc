#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int T = 0;
	scanf("%d", &T);

	for (int i = 0;i < T;i++) {
		int num, cnt = 0;
		scanf("%d", &num);

		while (1) {

			if (num == 0) break;

			if (num % 2 == 1) {
				printf("%d ", cnt);
			}

			num /= 2;
			cnt++;
		}
		
	}

	return 0;

}