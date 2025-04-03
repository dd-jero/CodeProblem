#include <iostream>
#include <algorithm>
using namespace std;

int N, res = 0; // 숲 크기, 최대 이동 칸 수 
int forest[501][501]; // 대나무 숲
int visited[501][501]; // (i,j)에서 시작 시 이동 할 수 있는 최대 칸 수를 저장 

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int DFS(int x, int y);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            cin >> forest[i][j];
        }
    }

    // 각 칸을 시작 점으로 
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            res = max(res, DFS(i, j));
        }
    }

    cout << res << "\n";
    return 0;
}

int DFS(int x, int y) {

    // 이미 해당 칸에 접근했으면
    if (visited[x][y] != 0) return visited[x][y];

    // 첫 접근이면 
    visited[x][y] = 1; 

    for (int d = 0;d < 4;d++) {
        int nxt_x = x + dx[d];
        int nxt_y = y + dy[d];

        if (nxt_x < 0 || nxt_x >= N || nxt_y < 0 || nxt_y >= N) continue; // 범위 초과
        if (forest[x][y] < forest[nxt_x][nxt_y]) {
            visited[x][y] = max(visited[x][y], DFS(nxt_x, nxt_y) + 1);
        }

    }

    // 상하좌우로 더 이상 이동 불가능 하면 
    return visited[x][y];

}