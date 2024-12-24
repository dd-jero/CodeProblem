#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int heights[9];
    int total_sum = 0;

    // 키 입력 및 전체 합 계산
    for (int i = 0; i < 9; i++) {
        cin >> heights[i];
        total_sum += heights[i];
    }

    // 이중 반복문으로 2명의 키 찾기
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            // 전체 합에서 2명의 키를 뺐을 때 100이 되면
            if (total_sum - heights[i] - heights[j] == 100) {
                // 정렬을 위한 임시 배열
                vector<int> result;
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j) {
                        result.push_back(heights[k]);
                    }
                }

                // 오름차순 정렬
                sort(result.begin(), result.end());

                // 7명의 키 출력
                for (int num : result) {
                    cout << num << '\n';
                }

                return 0;
            }
        }
    }

    return 0;
}
