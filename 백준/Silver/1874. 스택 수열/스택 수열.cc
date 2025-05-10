#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N; // 1 ~ N 까지의 수 
vector<int> vec; // 수열 
stack<int> st; 
vector<char> res; 
int num_idx = 1; // 1 ~ N 까지 수에서 현재 넣을 수 있는 수 (N 이상이 되면 NO)
int vec_idx = 0; // 수열을 위해 현재 필요한 값 인덱스 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	int num;
	for (int i = 0;i < N;i++) {
		cin >> num;
		vec.push_back(num);
	}

	while (1) {
		if (st.empty()) { // 스택 비어 있으면 넣어야 됨.
			st.push(num_idx); 
			num_idx++;

			res.push_back('+');

		}

		if (st.top() == vec[vec_idx]) { // 스택 top == 수열에 현재 필요한 수 
			st.pop();
			res.push_back('-');
			vec_idx++;

			if (vec_idx == N) {
				break;
			}
		}
		else { // 아니면
			if (num_idx == N + 1) break;

			st.push(num_idx);
			num_idx++;

			res.push_back('+');
		}
	}

	if (vec_idx != N) cout << "NO" << "\n";
	else {
		for (char c : res) {
			cout << c << "\n";
		}
	}

	return 0;
}