#include <iostream>
using namespace std;

double N, avr, score[1001], max_score = 0.0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cout << fixed;
	cout.precision(15);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> score[i];

		if (max_score < score[i]) max_score = score[i];
	}

	for (int i = 0;i < N;i++) {
		score[i] = score[i] / max_score * 100.0;
		avr += score[i];
	}

	cout << avr/N << "\n";
	
	return 0;
}
