#include <iostream>
#include <stack>
using namespace std;

int K; // 정수 개수
stack<long long> st;
long long sum = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> K;

	long long num;
	for (int i = 0;i < K;i++) {
		cin >> num;

		if (num != 0) { // 0 아니면 삽입 
			st.push(num);
			sum += num;
		}
		else { // 0이면 top 제거
			long long t = st.top();
			st.pop();

			sum -= t;
		}
	}

	cout << sum << "\n";

	return 0;
}
