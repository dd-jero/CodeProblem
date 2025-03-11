#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second; // 데드라인, 컵라면 개수 입력
    }

    // 데드라인 기준 오름차순 정렬
    sort(arr.begin(), arr.end());

    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙
    for (int i = 0; i < n; i++) {
        if (pq.size() < arr[i].first) {
            // 아직 데드라인 내에 추가 가능하면 push
            pq.push(arr[i].second);
        }
        else if (pq.top() < arr[i].second) {
            // 더 좋은 컵라면 개수를 가진 문제로 교체
            pq.pop();
            pq.push(arr[i].second);
        }
    }

    int sum = 0;
    while (!pq.empty()) {
        sum += pq.top(); // 최소 힙에 남아 있는 모든 컵라면 개수를 합산
        pq.pop();
    }

    cout << sum << "\n";
    return 0;
}
