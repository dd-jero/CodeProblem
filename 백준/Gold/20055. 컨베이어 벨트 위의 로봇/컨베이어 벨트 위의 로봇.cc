#include <iostream>
#include <queue>
using namespace std;

int N, K, cnt = 0, res = 0;
int belt[202];
bool visited[202];
int s_loc = 1, e_loc;
queue<int> robot_loc;

void Move_belt();
void Move_robot();
void Put_robot();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 1;i <= 2*N;i++) {
		cin >> belt[i];
	}
	e_loc = N; // 내리는 위치 갱신 

	// 내구도가 0인 칸의 개수가 K되면 종료
	while (cnt < K) {
		res++;

		Move_belt();
		Move_robot();
		Put_robot();
	}

	cout << res << "\n";

	return 0;
}

// 1. 벨트가 회전한다. => 올리는 위치와 내리는 위치의 변경을 확인하면 된다.
void Move_belt() {
	s_loc--;
	e_loc--;

	// 올리는 위치는 1번칸, 내리는 위치는 N번칸이다
	if (s_loc < 1) s_loc = 2 * N;
	if (e_loc < 1) e_loc = 2 * N;
}

// 2. 로봇을 움직인다. 
void Move_robot() {

	int robot_size = robot_loc.size();

	for (int i = 0;i < robot_size;i++) {
		int cur_loc = robot_loc.front();
		visited[cur_loc] = false;
		robot_loc.pop();

		// 벨트가 움직였을 때, 내리는 위치에 도달하면 그 즉시 내린다.
		if (cur_loc == e_loc) continue;

		int nxt_loc = cur_loc + 1;

		if (nxt_loc > 2 * N) nxt_loc = 1; // 2N 다음 이동 칸은 1번
		if (belt[nxt_loc] >= 1 && !visited[nxt_loc]) { // 이동하려는 위치의 내구도가 1이상이고 로봇이 존재하지 않으면 이동

			belt[nxt_loc]--; // 내구도 1 감소

			if (belt[nxt_loc] == 0) cnt++; // 내구도가 0이 되면
			if (nxt_loc == e_loc) continue; // 다음 칸으로 움직였을 때 내리는 위치면 내린다.

			// 해당 위치로 이동
			visited[nxt_loc] = true; 
			robot_loc.push(nxt_loc); 
		}
		else { // 이동할 수 없으면 가만히 있는다.
			robot_loc.push(cur_loc);
			visited[cur_loc] = true;
		}
	}
}

// 3. 올리는 칸에 로봇 올릴 수 있으면 올린다.
void Put_robot() {
	if (!visited[s_loc] && belt[s_loc] >= 1) {
		visited[s_loc] = true;
		robot_loc.push(s_loc);
		belt[s_loc]--;

		if (belt[s_loc] == 0) cnt++;
	}
}