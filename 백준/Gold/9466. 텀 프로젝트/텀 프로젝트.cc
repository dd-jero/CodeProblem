#include <iostream>
using namespace std;

int T, N;
int want[100001], checked[100001]; // vector → 정적 배열
int path[100001]; // 경로 추적용 배열
void BFS(int start_student);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;

        // 배열 초기화
        for (int j = 0; j <= N; j++) {
            want[j] = 0;
            checked[j] = 0;
        }

        for (int j = 1; j <= N; j++) {
            cin >> want[j];
        }

        for (int j = 1; j <= N; j++) {
            if (checked[j] == 0) {
                BFS(j);
            }
        }

        int res = 0;
        for (int j = 1; j <= N; j++) {
            if (checked[j] == 1) res++;
        }

        cout << res << "\n";
    }

    return 0;
}

void BFS(int start_student) {
    int path_size = 0;
    int cur = start_student;

    while (true) {
        if (checked[cur] == 2) { // 이미 팀 완성된 학생
            return;
        }

        if (checked[cur] == 1) { // 현재 경로에서 이미 방문 = 사이클 발견
            // cur부터 사이클 시작점까지 팀 완성
            bool in_cycle = false;
            for (int i = 0; i < path_size; i++) {
                if (path[i] == cur) in_cycle = true;
                if (in_cycle) checked[path[i]] = 2;
            }
            return;
        }

        checked[cur] = 1; // 현재 경로에서 방문 중 표시
        path[path_size++] = cur;

        int nxt = want[cur];
        if (cur == nxt) { // 자기 자신 선택
            checked[cur] = 2;
            return;
        }

        cur = nxt;
    }
}
