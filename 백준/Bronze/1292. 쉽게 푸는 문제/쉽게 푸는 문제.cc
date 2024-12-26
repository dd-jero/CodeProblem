#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(void) {

	int A, B;
	vector<int> vec;

	cin >> A >> B;

	int num = 1; // 벡터에 삽입할 숫자 
	vec.push_back(0); // 0번째 삽입

	while (vec.size() < 1001) {

		for (int i = 0; i < num;i++) { // 삽입 숫자번 만큼 삽입
			vec.push_back(num);
		}

		num++; // 다음 숫자로 
	}

	int res = accumulate(vec.begin() + A, vec.begin() + B + 1, 0); // A번째 부터 B번째까지의 합
	
	cout << res;
	return 0;
}