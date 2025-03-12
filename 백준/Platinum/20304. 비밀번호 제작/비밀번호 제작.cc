#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;  // N: 비밀번호 최대값, M: 로그인 시도 횟수

    vector<bool> vis(N + 1, false);  // 방문 여부를 저장하는 배열
    queue<int> Q; 

    for (int i = 0; i < M; ++i) {
        int p;
        cin >> p;
        vis[p] = true; 
        Q.push(p); 
    }

    int max_safety = 0;  // 최대 안전도를 저장할 변수
    while (!Q.empty()) { 
        int size = Q.size();  // 현재 레벨의 노드 수
        max_safety++;

        for (int i = 0; i < size; ++i) {  // 현재 레벨의 모든 노드에 대해
            int curr = Q.front(); Q.pop(); 

            
            for (int b = 1; b <= N; b <<= 1) {  // 1, 2, 4, 8, ... 순으로 비트 체크
                int next = curr ^ b;  // XOR 연산으로 비트 반전 (서로 다른 경우 1을 나타냄)
                if (next <= N && !vis[next]) {  // 새 숫자가 범위 내이고 방문하지 않았다면
                    vis[next] = true;  
                    Q.push(next);  
                }
            }
        }
    }

    cout << max_safety - 1;  // 최대 안전도 출력 (초기값 0을 빼주기 위해 1 감소)
    return 0;
}
