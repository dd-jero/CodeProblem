#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Info {
    int x, y, dist;
    bool crashed;
};

int N, M, map[1001][1001];
bool visited[2][1001][1001]; // 0: 벽을 부수지 않고 방문, 1: 벽을 부수고 방문
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int BFS() {
    queue<Info> q;
    q.push({ 0, 0, 1, false });
    visited[0][0][0] = true;

    while (!q.empty()) {
        auto cur = q.front(); 
        q.pop();

        if (cur.x == N - 1 && cur.y == M - 1)
            return cur.dist;

        for (int d = 0; d < 4; d++) {
            int nxt_x = cur.x + dx[d];
            int nxt_y = cur.y + dy[d];

            if (nxt_x < 0 || nxt_x >= N || nxt_y < 0 || nxt_y >= M) continue;

            // 벽이 아니고, 아직 방문 안 했을 때
            if (map[nxt_x][nxt_y] == 0 && !visited[cur.crashed][nxt_x][nxt_y]) {
                visited[cur.crashed][nxt_x][nxt_y]= true;
                q.push({ nxt_x, nxt_y, cur.dist + 1, cur.crashed });
            }
            // 벽이고, 아직 벽을 안 부쉈을 때
            else if (map[nxt_x][nxt_y] == 1 && !cur.crashed && !visited[1][nxt_x][nxt_y]) {
                visited[1][nxt_x][nxt_y] = true;
                q.push({ nxt_x, nxt_y, cur.dist + 1, true });
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    string line;
    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < M; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    int res = BFS();
    cout << res << "\n";
    return 0;
}
