#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string str, bomb;
    cin >> str >> bomb;

    string result;

    for (char c : str) {
        result.push_back(c);

        // 폭발 문자열과 길이가 같거나 길 때만 검사
        if (result.size() >= bomb.size()) {
            bool isMatch = true;
            for (int i = 0; i < bomb.size(); ++i) {
                if (result[result.size() - bomb.size() + i] != bomb[i]) {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch) {
                // 폭발 문자열 제거
                for (int i = 0; i < bomb.size(); ++i) {
                    result.pop_back();
                }
            }
        }
    }

    if (result.empty()) cout << "FRULA\n";
    else cout << result << "\n";

    return 0;
}
