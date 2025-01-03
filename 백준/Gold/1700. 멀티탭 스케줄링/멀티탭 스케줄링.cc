#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K, res = 0; // N: 멀티탭 구멍 수, K: 전기용품 사용 횟수, res: 플러그 뽑은 횟수
    cin >> N >> K;

    vector<int> multitap(N, 0); // 멀티탭 상태 저장 (0은 빈 구멍)
    vector<int> schedule(K); // 전기용품 사용 스케줄

    // 스케줄 입력 받기
    for (int i = 0; i < K; i++) {
        cin >> schedule[i];
    }

    // 전기용품 사용 순서대로 처리
    for (int i = 0; i < K; i++) {
        bool plugged = false;

        // 1. 이미 꽂혀있는지 또는 빈 구멍이 있는지 확인
        for (int j = 0; j < N; j++) {
            if (multitap[j] == schedule[i]) { // 이미 꽂혀있는 경우
                plugged = true;
                break;
            }
            if (multitap[j] == 0) { // 빈 구멍이 있는 경우
                multitap[j] = schedule[i];
                plugged = true;
                break;
            }
        }
        if (plugged) continue; // 이미 꽂혀있거나 빈 구멍에 꽂았으면 다음으로

        // 2. 모든 구멍이 사용 중이라면, 가장 나중에 사용될 기기 찾기
        int idx = -1, last_use = -1;
        for (int j = 0; j < N; j++) {
            int next = K; // 현재 꽂혀있는 기기의 다음 사용 시점
            for (int k = i + 1; k < K; k++) {
                if (multitap[j] == schedule[k]) {
                    next = k;
                    break;
                }
            }
            // 가장 나중에 사용될 기기 갱신
            if (next > last_use) {
                idx = j;
                last_use = next;
            }
        }

        // 3. 가장 나중에 사용될 기기를 뽑고 새 기기 꽂기
        multitap[idx] = schedule[i];
        res++; // 플러그를 뽑은 횟수 증가
    }

    cout << res; // 결과 출력
    return 0;
}
