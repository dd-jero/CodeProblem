#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int N, res = 0;
	vector<int> vec;

	// 수의 개수
	cin >> N;

	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	for (int number : vec) {
		for (int i = 2; i <= number;i++) {

			if (i == number) { // 현재 검사하는 숫자와 동일하면 이전까지 나누어지지 않은 것
				res++;
			}

			if (number % i == 0) { // 나누어 떨어지면 소수 X 
				break;
			}
		}
	}

	cout << res;

}