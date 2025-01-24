#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, taesu_score, p, taesu_rank = -1; // 주어지는 랭킹 수, 태수 점수, 랭킹 리스트에 올라갈 수 있는 점수
int score_list[51];
int ranking_list[51];

int main() {

	memset(score_list, -1, sizeof(score_list));
	cin >> n >> taesu_score >> p;

	for (int i = 0;i < n;i++) { // 비오름차순 = 내림차순
		cin >> score_list[i];
	}
	score_list[n] = taesu_score;

	sort(score_list, score_list + n + 1, greater<>());

	int rank = 1;
	int same = 0;

	for (int i = 0;i < p;i++) {

		if (i > 0 && (score_list[i] != score_list[i-1])) { // 현재 랭킹 점수가 이전 랭킹 점수와 다르면
			rank+= same;
			same = 0;
		}
		
		if (taesu_score == score_list[i]) taesu_rank = rank; // 점수 같으면 랭크 지정 (단, 같은 점수가 마지막 랭킹의 점수면 안됨)
		ranking_list[i] = rank;
		
		// 같은 점수가 나오지 않으면 rank에는 1만 더해짐 
		same++;
	}

	if (score_list[p] == taesu_score) taesu_rank = -1;

	cout << taesu_rank << "\n";

	return 0;
}