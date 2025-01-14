#include <iostream>
using namespace std;

int n, cnt = 0;
long long res = -1;

// 최대 9876543210
void dfs(int len, long long  num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0;i <= 10;i++) { // 자리의 개수 
		dfs(i, 0);
	}

	cout << res;
	return 0;
}

void dfs(int len, long long num) {

	if (len == 0) { // 정해진 자리 수 만큼 다 채웠으면 
		if (cnt == n) {
			res = num;
		}
		cnt++;
		return;
	}

	int last_num = num % 10; // 현재 마지막 자리의 숫자
	if (num == 0) last_num = 10; // 초기 dfs 호출 시 

	for (int i = 0;i < last_num;i++) // 마지막 수보다 작은 수를 추가함. 
	{
		long long next_num = num * 10 + i;
		if (num == 0 && i == 0) continue; // 0으로 시작 방지 

		dfs(len - 1, next_num);
	}
}