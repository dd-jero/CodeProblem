#include <iostream>
#include <stack>
using namespace std;

string input;
stack<char> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> input;

	for (int i = 0;i < input.length();i++) {
		if (!s.empty()) { // 스택이 비어 있지 않으면
			if (s.top() == '(' && input[i] == ')') { // 올바른 괄호열이면 스택의 top 제거 
				s.pop();
			}
			else { // 아니면 삽입 
				s.push(input[i]);
			}
		}
		else { // 비어 있으면 삽입
			s.push(input[i]);
		}
	}

	cout << s.size() << "\n";

	return 0;
}