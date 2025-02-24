#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct log_info {
	int score;
	int cnt;
	int time;
};

struct res_team {
	int team_id;
	int sum_score;
	int sum_cnt;
	int last_time;

	bool operator<(const res_team& other) const {

		// 총점 내림차순
		if (this->sum_score != other.sum_score) {
			return this->sum_score < other.sum_score;
		}

		// 제출 횟수 오름차순 
		if (this->sum_cnt != other.sum_cnt) {
			return this->sum_cnt > other.sum_cnt;
		}

		// 마지막 제출 시간 내림차순
		if (this->last_time != other.last_time) {
			return this->last_time > other.last_time;
		}
	}

	/*void print() const {
		cout << "팀 " << team_id << ": [총점]" << sum_score << " [제출 횟수]" << sum_cnt << " [마지막 제출시간]" << last_time << " " << "\n";
	}*/
};

int T, n, k, t, m;
int i, j, s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	for (int tc = 0;tc < T;tc++) {
		cin >> n >> k >> t >> m; // 팀의 개수, 문제의 개수, 내팀의 id, 로그 엔트리 수
		vector<vector<log_info>> team(n + 1, vector<log_info>(k + 1));
		vector<vector<bool>> checked(n + 1, vector<bool>(k + 1));

		for (int time = 1;time <= m;time++) {
			cin >> i >> j >> s; // 팀 id, 문제 번호, 획득 점수

			if (checked[i][j]) { // 해당 문제를 이미 제출 했으면
				if (team[i][j].score < s) {
					team[i][j] = log_info{ s, ++team[i][j].cnt, time }; // {더 높은 점수, 제출 횟수 1 증가, 현재 제출 시간}으로 갱신 
				}
				else {
					// 더 높은 점수가 아니더라도 최종 제출 시간 및 제출 횟수 갱신 
					team[i][j] = log_info{ team[i][j].score, ++team[i][j].cnt, time}; // {더 높은 점수, 제출 횟수 1 증가, 현재 제출 시간}으로 갱신 

				}
			}
			else { // 아직 제출 안했으면
				checked[i][j] = true;
				team[i][j] = log_info{ s,1,time };
			}
		}

		priority_queue<res_team> pq;
		// 각 팀 별 {총점, 제출 횟수, 마지막 제출 시간} 구하기 
		for (int i = 1;i <= n;i++) { 
			int s_score = 0, s_cnt = 0, last_t = 0;

			for (int p = 1;p <= k;p++) { // 각 문제별로 확인
				s_score += team[i][p].score;
				s_cnt += team[i][p].cnt;
				last_t = last_t < team[i][p].time ? team[i][p].time : last_t;
			}

			res_team cur_team = res_team{ i, s_score, s_cnt, last_t };
			//cur_team.print();
			pq.push(cur_team);
		}

		int rank = 1;
		while (!pq.empty()) {
			res_team cur = pq.top();
			if (cur.team_id == t) break;
			else {
				pq.pop();
				rank++;
			}
		}

		cout << rank << "\n";

	}
	return 0;
}