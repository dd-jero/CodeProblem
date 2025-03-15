#define MAX_N 100001
#include <iostream>
#include <queue>
using namespace std;

int N, res = 0; // 카드 묶음 개수 
int arr[MAX_N];
priority_queue<int, vector<int>, greater<>> pq; // 오름차순 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}

	while (1) {

		if (pq.size() == 1) {
			break;
		}

		int n1 = pq.top();
		pq.pop();
		int n2 = pq.top();
		pq.pop();

		int s = n1 + n2;
		res += s;
		pq.push(s);
	}

	cout << res << "\n";

	return 0;
}