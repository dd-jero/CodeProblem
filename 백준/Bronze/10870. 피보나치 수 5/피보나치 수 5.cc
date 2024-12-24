#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 전역으로 선언하면 선언 시 0으로 초기화
int arr[21];
// 지역으로 선언하면 선언 시 쓰레기 값을 가짐

int main(void)
{
	int n = 0;
	scanf("%d", &n);

	arr[0] = 0;
	arr[1] = 1;

	// fn = fn-1 + fn-2
	for (int i = 2;i <= (sizeof(arr) / sizeof(*arr)); i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	printf("%d", arr[n]);

	return 0;
}