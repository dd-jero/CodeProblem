#define INF 2e9
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, res = INF;
int map[101][101];
int visited[101][101];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

// 섬 라벨링 (기존 Divide, BFS 함수)
void labelIslands() {
    int label = 2; // 2부터 시작 (1은 입력에서 사용됨)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1) {
                queue<pair<int, int>> q;
                q.push({ i, j });
                map[i][j] = label;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = cur.first + dx[d];
                        int ny = cur.second + dy[d];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (map[nx][ny] == 1) {
                            map[nx][ny] = label;
                            q.push({ nx, ny });
                        }
                    }
                }
                label++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    // 1. 섬 라벨링
    labelIslands();

    // 2. 모든 섬의 가장자리(육지와 바다 경계)를 큐에 넣고, visited 초기화
    queue<pair<int, int>> q;
    fill(&visited[0][0], &visited[0][0] + 101 * 101, -1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] > 1) {
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d], ny = j + dy[d];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (map[nx][ny] == 0) {
                        q.push({ i, j });
                        visited[i][j] = 0;
                        break; // 이미 가장자리면 한 번만 push
                    }
                }
            }
        }
    }

    // 3. 멀티 소스 BFS
    int ans = INF;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            // 바다라면 확장
            if (map[nx][ny] == 0 && visited[nx][ny] == -1) {
                map[nx][ny] = map[x][y]; // 섬 번호 전파
                visited[nx][ny] = visited[x][y] + 1;
                q.push({ nx, ny });
            }
            // 다른 섬을 만났다면
            else if (map[nx][ny] > 1 && map[nx][ny] != map[x][y]) {
                ans = min(ans, visited[x][y] + visited[nx][ny]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
