#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector<int> want, checked;
void BFS(int start_student);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;

        want.assign(N + 1, 0);
        checked.assign(N + 1, 0);

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
            if (checked[j] == -1) res++;
        }

        cout << res << "\n";
    }

    return 0;
}

void BFS(int start_student) {
    vector<int> prev;
    int cur = start_student;

    while (true) {
        if (checked[cur] == 2) { // 이미 팀 완성된 학생
            return;
        }

        if (checked[cur] == -1) { // 현재 경로에서 이미 방문 = 사이클 발견
            // cur부터 사이클 시작점까지 팀 완성
            bool in_cycle = false;
            for (int student : prev) {
                if (student == cur) in_cycle = true;
                if (in_cycle) checked[student] = 2;
            }
            return;
        }

        checked[cur] = -1; // 현재 경로에서 방문 중 표시
        prev.push_back(cur);

        int nxt = want[cur];
        if (cur == nxt) { // 자기 자신 선택
            checked[cur] = 2;
            return;
        }

        cur = nxt;
    }
}
