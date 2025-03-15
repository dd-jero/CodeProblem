#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Lecture {
	int start;
	int end;

	bool operator<(const Lecture& other) const { // pq 정렬
		if (this->end != other.end) { // 종료 시간에 따른 오름차순
			return (this->end > other.end);
		}

		return false;
	}
};

bool comp(Lecture l1, Lecture l2)  { // 벡터 정렬

	if (l1.start == l2.start) { 
		return l1.end < l2.end;  // 종료 시간에 따른 오름차순
	}

	return l1.start < l2.start;  // 시작 시간에 따른 오름차순
}

int N; 
vector<Lecture> lec;
priority_queue<Lecture> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int s, e;
	for (int i = 0;i < N;i++) {
		cin >> s >> e;
		lec.push_back(Lecture{ s,e });
	}

	sort(lec.begin(), lec.end(), comp);


	for (int i = 0;i < lec.size();i++) { // 강의 개수 만큼 

		if (pq.size() == 0) { // 처음에는 그냥 삽입
			pq.push(lec[i]);
			continue;
		}

		auto cur = pq.top();

		if (cur.end <= lec[i].start) { // 해당 강의실을 그대로 이용
			pq.pop();
			pq.push(lec[i]);
		}
		else { // 새로운 강의실을 추가 활용 
			pq.push(lec[i]);
		}
	}

	cout << pq.size() << "\n";

	return 0;
}