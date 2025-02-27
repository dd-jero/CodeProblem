#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int N, M;
int compIndex = 1; // 지역 번호 1번 부터 시작 
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    // 맵 입력 (문자열 형태)
    vector<string> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    // 각 빈 칸이 속한 영역 번호 저장 (아직 미방문이면 0)
    vector<vector<int>> region(N, vector<int>(M, 0));
    // 각 영역의 크기를 저장 (영역 번호는 1부터 시작)
    vector<int> region_size;
    region_size.push_back(0); // 인덱스 0은 사용하지 않음

    // 빈 칸 영역(연결 컴포넌트) 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vec[i][j] == '0' && region[i][j] == 0) {
                queue<pair<int, int>> q;
                q.push({ i, j });
                region[i][j] = compIndex;
                int cnt = 1;

                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    int x = cur.first, y = cur.second;

                    // 4방향 탐색
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                        if (vec[nx][ny] == '0' && region[nx][ny] == 0) {
                            region[nx][ny] = compIndex;
                            q.push({ nx, ny });
                            cnt++;
                        }
                    }
                }
                // 현재 영역의 크기 저장 후 번호 증가
                region_size.push_back(cnt);
                compIndex++;
            }
        }
    }

    // 결과를 저장할 int형 2차원 배열 생성
    vector<vector<int>> result(N, vector<int>(M, 0));

    // 각 칸을 순회하며 벽(‘1’)이면 인접한 영역의 크기를 합산하여 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vec[i][j] == '1') {
                int sum = 1; // 벽 자체를 부수면 이동 가능한 칸이므로 1부터 시작
                set<int> uniqueComps;  // 인접 영역 중복 처리를 위한 set

                // 4방향 검사
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;

                    if (vec[ni][nj] == '0') {
                        int id = region[ni][nj];
                        if (uniqueComps.count(id) == 0) {
                            uniqueComps.insert(id);
                            sum += region_size[id];
                        }
                    }
                }
                result[i][j] = sum % 10;
            }
            // 빈 칸은 이미 0으로 초기화되어 있음
        }
    }

    // 결과 출력 (각 행을 공백없이 출력)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << result[i][j];
        }
        cout << "\n";
    }

    return 0;
}
