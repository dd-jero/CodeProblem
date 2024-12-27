#include <iostream>
#include <vector>
using namespace std;

int calc_num[4]; // 연산자 갯수 배열
int N;
int max_val = -1000000000;
int min_val = 1000000000;
vector<int> numbers; // 숫자 벡터

void recur(int calc_num[], vector<int> calculator);
void calc(vector<int> calculator);

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> calculator; // 연산자 벡터 

	cin >> N; // 수의 개수

	// 수 입력
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		numbers.push_back(num);
	}

	// 연산자 갯수 입력
	for (int i = 0;i < 4;i++) {
		int cnt;
		cin >> cnt;
		calc_num[i] = cnt;
		// 0: +, 1: -, 2: *, 3: /
	}
	
	recur(calc_num, calculator);

	cout << max_val << "\n" << min_val;

	return 0;
}

void recur(int calc_num[], vector<int> calculator) {

	if (calculator.size() == N - 1) { // 모든 연산자가 포함되었을 때
		calc(calculator); // 연산 시작 
		return;
	}

	for (int i = 0;i < 4;i++) {
		if (calc_num[i] == 0) continue; // 해당 연산자를 더 이상 추가할 수 없음

		// 해당 연산자를 사용
		calc_num[i]--;
		calculator.push_back(i);

		// 재귀 
		recur(calc_num, calculator);

		// 원복
		calc_num[i]++;
		calculator.pop_back();
	}
}

void calc(vector<int> calculator) { // 완성된 연산자 순서에 따라 계산하기 

	int cur_num = numbers[0]; // 누적

	for (int i = 0;i < N-1;i++) { // 연산자 개수 만큼
		if (calculator[i] == 0) cur_num += numbers[i + 1]; // 더하기
		else if (calculator[i] == 1) cur_num -= numbers[i + 1]; // 빼기
		else if (calculator[i] == 2) cur_num *= numbers[i + 1]; // 곱셈
		else cur_num /= numbers[i + 1]; // 나누기 
;	}

	// 최소 최대 값 갱신 
	if (cur_num > max_val) max_val = cur_num;
	if (cur_num < min_val) min_val = cur_num;
}

