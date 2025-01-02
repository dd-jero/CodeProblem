#include <iostream>
#include <string>
#include <vector>
using namespace std;

int learned = 0; // 배운 글자 여부 비트마스킹 
int word[50];
int res = 0;
int N = 0, K = 0; // 단어의 개수, 가르칠 수 있는 글자 수

void recur(int idx, int cnt); // 조합을 위한 재귀함수 
int check_word();

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> K;

	string str;
	for (int i = 0;i < N;i++) { // 단어의 개수 만큼 입력 
		cin >> str;

		int num = 0;
		// 시작과 끝 검증
		if (str.substr(0, 4) == "anta" && str.substr(str.length() - 4) == "tica") {
			for (int j = 0;j < (str.length() - 4); j++) {
				num |= (1 << (str[j] - 'a'));
			}

			word[i] = num; // 단어도 비트 마스킹 활용 해서 저장 
		}
	}

	if (K < 5) { // anta, tica 조차 다 못 배움 
		cout << 0;
		return 0;
	}

	// 기본 문자 처리
	learned |= (1 << ('a' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a')) | (1 << ('i' - 'a')) | (1 << ('c' - 'a'));
	K -= 5;

	recur(0, K);

	cout << res;

	return 0;
}

void recur(int idx, int cnt) {

	// K개의 모두 배웠으면 
	if (cnt == 0) {
		int tmp_res = check_word(); // 읽을 수 있는 단어 수 확인 

		if (tmp_res == N) { // 종료
			cout << tmp_res;
			exit(0);
		}

		// 업데이트
		res = res < tmp_res ? tmp_res : res;
		return;
	}

	for (int i = idx;i < 26;i++) {

		if (i == 'a' - 'a' || i == 'n' - 'a' || i == 't' - 'a' || i == 'i' - 'a' || i == 'c' - 'a') {
			continue;
		}


		if (!(learned & (1 << i))) {
			learned |= (1 << i);
			recur(i + 1, cnt - 1);
			learned &= ~(1 << i);
		}
	}

}

int check_word() {

	int tmp_res = 0;

	for (int i = 0;i < N;i++) {
		if ((word[i] & learned) == word[i]) { // 해당 단어를 읽을 수 있으면 
			tmp_res++;
		}
	}

	if (tmp_res == N) { // 모든 단어를 읽을 수 있으면
		return N;
	}
	else { // 아니면 
		return tmp_res;
	}
}