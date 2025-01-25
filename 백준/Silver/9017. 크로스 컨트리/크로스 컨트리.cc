#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n;

struct team {
	int id;
	int sum;
	int five_score;

	bool operator<(const team& other) const {
		if (this->sum != other.sum) {
			return this->sum < other.sum; // 현재 팀의 합이 더 작으면 true
		}
		else { // 점수가 같을 때
			return this->five_score < other.five_score; // 현재 팀의 다섯번째 점수가 더 작으면 true
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int tc = 0;tc < t;tc++) {

		cin >> n;

		vector<vector<int>> score_list(n+1);
		vector<team> ranking_list;
		vector<int> cnt_num(n + 1, 0); // 각 팀 6명 확인
		vector<int> all_team(n+1); // 모든 인원의 순위 확인
		int team_id;

		for (int i = 1;i < n+1;i++) { 
			cin >> team_id;
			cnt_num[team_id]++; // 각 팀의 인원 수 확인 위함.
			all_team[i] = team_id; // 해당 등수에 팀 id 저장 
;		}	

		int cur_rank = 1;
		for (int i = 1;i < n + 1;i++) {
			if (cnt_num[all_team[i]] == 6) { // 현재 등수의 팀이 점수 부여 가능한지 
				score_list[all_team[i]].push_back(cur_rank++);
			}
		}

		for (int i = 1;i < n+1;i++) {
			if (score_list[i].size() != 0) { // 점수를 부여 받은 팀이면 

				int cur_score = 0;
				// 1. 각 팀의 상위 네명의 점수 합산
				for (int j = 0;j < 4;j++) {
					cur_score += score_list[i][j];
				}
				ranking_list.push_back(team{ i, cur_score, score_list[i][4] });
			}
		}

		sort(ranking_list.begin(), ranking_list.end());

		cout << ranking_list[0].id << "\n";
		
	}

	return 0;
}