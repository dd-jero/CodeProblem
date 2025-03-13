#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    long long arr[51];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N); // 오름차순 정렬

    long long res = 0;
    int left = 0, right = N - 1;

    // 1. 음수 쌍 처리 
    while (left < right && arr[left] < 0 && arr[left + 1] < 0) {
        res += arr[left] * arr[left + 1]; // 두 음수를 곱해 양수로 변환
        left += 2;
    }

    // 남은 음수와 0이 있으면 처리
    if (left < right && arr[left] < 0 && arr[left + 1] == 0) {
        left += 2; // 음수와 0을 곱하면 0이므로 더할 필요 없음
    }

    // 2. 양수 처리 (오른쪽에서부터 큰 수들 먼저)
    while (right > 0 && arr[right] > 1 && arr[right - 1] > 1) {
        res += arr[right] * arr[right - 1]; // 큰 양수들끼리 곱해 더 큰 수를 만듦
        right -= 2;
    }

    // 3. 남은 숫자들 더하기
    for (int i = left; i <= right; i++) {
        res += arr[i];
    }

    cout << res << "\n";
    return 0;
}
