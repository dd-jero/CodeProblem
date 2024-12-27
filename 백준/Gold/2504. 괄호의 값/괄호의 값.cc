#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> stack;
    int tmp = 1, res = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            stack.push(str[i]);
            tmp *= 2;
        }
        else if (str[i] == '[') {
            stack.push(str[i]);
            tmp *= 3;
        }
        else if (str[i] == ')') {
            if (stack.empty() || stack.top() != '(') { // 올바르지 않는 괄호 
                cout << 0;
                return 0;
            }

            if (i > 0 && str[i - 1] == '(') { // 바로 붙어있으면 더하기 
                res += tmp;
            }

            stack.pop();
            tmp /= 2; // 해당 괄호 쌍이 완성되어서 
        }
        else if (str[i] == ']') {
            if (stack.empty() || stack.top() != '[') { // 올바르지 않는 괄호 
                cout << 0;
                return 0;
            }

            if (i > 0 && str[i - 1] == '[') { // 바로 붙어있으면 더하기 
                res += tmp;
            }

            stack.pop();
            tmp /= 3; // 해당 괄호 쌍이 완성되어서 
        }
    }

    if (!stack.empty()) {
        cout << 0;
    }
    else {
        cout << res;
    }

    return 0;
}
