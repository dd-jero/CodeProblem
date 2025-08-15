#include <iostream>
#include <vector>
using namespace std;

int N, M, res = 0; // 카드 개수, 최대 가능 합
bool ret_flag = false; // 3장이 합이 M이 나올 경우 
vector<int> cards;

void comb(int idx, int sum, int cnt);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int num = 0;
    for (int i = 0; i < N; i++) {
        cin >> num;
        cards.push_back(num);
    }

    comb(0, 0, 0);

    cout << res << "\n";

    return 0;
}

void comb(int idx, int sum, int cnt) { // M에 최대한 가까운 3장의 합 조합 찾기
    // 3장의 합이면
    if (cnt == 3) {
        if (sum < M) {
            res = res < sum ? sum : res; // 기존 합보다 크면 갱신
        }
        else if(sum == M) { // M이면 
            res = sum;
            ret_flag = true; // 더 이상 찾아볼 필요 없음
        }
        return; 
    }

    for (int i = idx; i < N; i++) {
        comb(i+1, sum + cards[i], cnt + 1);
        if (ret_flag) return; 
    }
}