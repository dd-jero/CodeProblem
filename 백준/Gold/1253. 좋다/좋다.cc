#include <iostream>
#include <algorithm>
using namespace std;

int n, res = 0;
int nums[2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n); // 배열 정렬

    for (int i = 0; i < n; i++) {
        int target = nums[i];
        int start = 0, end = n - 1;

        while (start < end) {
            if (start == i) { // 현재 숫자를 제외
                start++;
                continue;
            }
            if (end == i) { // 현재 숫자를 제외
                end--;
                continue;
            }

            int sum = nums[start] + nums[end];

            if (sum == target) { // 두 수의 합이 target인 경우
                res++;
                break; // 한 번 찾으면 종료
            }
            else if (sum < target) {
                start++; // 합이 작으면 start 증가
            }
            else {
                end--; // 합이 크면 end 감소
            }
        }
    }

    cout << res << "\n";

    return 0;
}
