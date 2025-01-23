#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k; // 국가 수, 등수를 알고 싶은 국가

struct country {
	int num;
	int g;
	int s;
	int b;

	bool operator<(const country& other) const {
		if(this->g != other.g) {
			return this->g > other.g;  
		}
		else if (this->s != other.s) { 
			return this->s > other.s; 
		}
		else {
			return this->b > other.b;
		}
	}

	void print() {
		cout << num << g << s << b << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	vector<country> vec(n);

	for (int i = 0;i < n;i++) {
		cin >> vec[i].num >> vec[i].g >> vec[i].s >> vec[i].b;
	}

	sort(vec.begin(), vec.end());

	int rank = 1, same = 0;
	
	for (int i = 0;i < n;i++) {
		if (i > 0 && (vec[i].g != vec[i - 1].g || vec[i].s != vec[i - 1].s || vec[i].b != vec[i - 1].b)) { // 하나의 메달 수라도 다르면 
			rank += same;
			same = 0;
		}

		if (vec[i].num == k) { // 찾는 나라이면
			cout << rank;
			return 0;
		}
		
		same++;
	}

	return 0;
}