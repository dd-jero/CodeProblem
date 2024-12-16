#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {

	int N, K = 0; // N의 약수들 중 K번째로 작은 수 

	scanf("%d %d", &N, &K);

	vector<bool> check(N+1, false);

	for (int i = N; i > 0; i--) {
		if (N % i == 0) { // 나머지 0이면
			check[i] = true;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (check[i]) {
			K--;
			
			if (K == 0) {
				printf("%d", i);
				return 0;
			}
		}
	}

	printf("%d", 0);

	return 0;
}