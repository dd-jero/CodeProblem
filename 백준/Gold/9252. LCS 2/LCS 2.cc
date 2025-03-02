#include <iostream>
#include <string>
#include <stack>
using namespace std;

int lcs[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str1, str2, res;

	cin >> str1 >> str2;
	str1 = '0' + str1;
	str2 = '0' + str2;

	int str1_size = str1.size();
	int str2_size = str2.size();

	for (int i = 1;i < str1_size;i++) {
		for (int j = 1;j < str2_size;j++) {
			if (str1[i] == str2[j]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j] : lcs[i][j - 1];
			}
		}
	}

	int i = str1_size - 1;
	int j = str2_size - 1;
	stack<int> st; // 거꾸로 담기니 stack을 이용

	while (lcs[i][j] != 0)
	{

		if (lcs[i][j] == lcs[i][j - 1]) {
			j--;

		}
		// 위쪽으로 이동
		else if (lcs[i][j] == lcs[i - 1][j]) {
			i--;

		}
		// 왼쪽 위쪽 모두 다른 넘버링이라면 대각선 방향으로 이동
		else if (lcs[i][j] - 1 == lcs[i - 1][j - 1])
		{
			st.push(i);
			i--;
			j--;
		}
	}

	cout << lcs[str1_size - 1][str2_size - 1] << "\n";
	while (!st.empty())
	{
		cout << str1[st.top()];
		st.pop();
	}

	return 0;
}