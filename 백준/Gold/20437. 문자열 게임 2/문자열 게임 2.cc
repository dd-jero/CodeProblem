#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits> // For INT_MAX

using namespace std;

int T, K;
string W;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        cin >> W >> K;

        // 각 문자의 등장 위치를 저장
        unordered_map<char, vector<int>> char_positions;
        for (int i = 0; i < W.size(); i++) {
            char_positions[W[i]].push_back(i);
        }

        int min_len = INT_MAX;
        int max_len = 0;

        // 각 문자에 대해 처리
        for (auto& entry : char_positions) {
            const vector<int>& positions = entry.second;

            // 슬라이딩 윈도우로 정확히 K개의 문자를 포함하는 구간 찾기
            for (int i = 0; i + K - 1 < positions.size(); i++) {
                int start = positions[i];
                int end = positions[i + K - 1];
                int length = end - start + 1;

                // 최소 길이 갱신
                min_len = min(min_len, length);

                // 최대 길이 갱신 (첫 번째와 마지막 글자가 동일한 경우)
                if (W[start] == W[end]) {
                    max_len = max(max_len, length);
                }
            }
        }

        if (min_len == INT_MAX || max_len == 0) {
            cout << -1 << "\n";
        }
        else {
            cout << min_len << " " << max_len << "\n";
        }
    }

    return 0;
}
