#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct step{
	int cur_loc;
	int cur_time;

	bool operator<(const step& other) const { // 시간에 따른 오름차순 
		return  this->cur_time > other.cur_time;
	}
};

void bfs(int location, int time);
int n, m, fastest_time = -1, find_cnt = 0; // 수빈 위치, 동생 위치, 가장 빨리 찾은 시간, 동생을 찾는 방법 수 
vector<int> checked(100001, -1); // 위치 체크 
int dx[3] = { -1,1,2 };
priority_queue<step> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	bfs(n, 0);

	cout << fastest_time << "\n" << find_cnt;

	return 0;
}

void bfs(int location, int time) {

	// 수빈 출발 위치
	pq.push(step{ location, time });

	while (!pq.empty()) {

		int loc = pq.top().cur_loc;
		int time = pq.top().cur_time;
		pq.pop();

		if (fastest_time != -1 && time > fastest_time) break; // 이미 가장 빠른 시간을 찾았고 그 시간을 넘어간 경우 종료

		if (loc == m) { // 가장 빠른 속도로 동생을 찾았으면
			if (fastest_time == -1) {  // 처음 찾았으면
				fastest_time = time;
			}
			find_cnt++;
		}

		for (int nxt_loc : {loc - 1, loc + 1, loc * 2}) {
			if (-1 < nxt_loc && nxt_loc < 100001) {
				if (checked[nxt_loc] == -1 || checked[nxt_loc] == time+1) { // 첫 방문이거나 동일 시간에 방문이면(가장 빠른 시간을 찾은 경우)
					checked[nxt_loc] = time+1;
					pq.push(step{ nxt_loc, time + 1 });
				}
			}
		}

	}

}