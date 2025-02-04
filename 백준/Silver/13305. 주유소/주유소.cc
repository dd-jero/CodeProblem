#define INF 2e9
#include <iostream>
using namespace std;

int n, cur_min_cost = INF, total_cost = 0;
int len_road[100001]; // 도로의 길이
int liter_cost[100001]; // 각 주유소의 리터당 가격

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0;i < n - 1;i++) {
		cin >> len_road[i];
	}

	for (int i = 0;i < n;i++) {
		cin >> liter_cost[i];
	}

	for (int i = 0;i < n - 1;i++) {
		
		// 현재 주유소 가격이 더 싸면 갱신 
		cur_min_cost = cur_min_cost > liter_cost[i] ? liter_cost[i] : cur_min_cost;

		total_cost += (cur_min_cost * len_road[i]);
	}

	cout << total_cost << "\n";

	return 0;
}