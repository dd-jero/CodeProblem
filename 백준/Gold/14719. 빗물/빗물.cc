#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int H, W, res = 0; // 세로, 가로, 빗물 총량 
	cin >> H >> W;

	vector<vector<int>> vec(H,vector<int>(W,0)); // 2차원 세계
	for (int i = 0;i < W;i++) { // 열의 개수만큼 입력
		int num;
		cin >> num;

		for (int j = H-1;j >= H-num;j--) { // 아래서부터 num 만큼 블록 채우기
			vec[j][i] = 1;
		}
	}

	//for (int i = 0;i < vec.size();i++) {
	//	for (int j = 0;j < vec[i].size();j++) {
	//		cout << vec[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	// 아래 행부터 1을 요소로 가지는 연속된 idx 차가 2 이상일 경우에 (해당 차 -1) 만큼 res 더함
	int start_idx = -1, end_idx = -1;

	for (int i = H - 1;i >= 0;i--) {
		for (int j = 0; j < W;j++) {
			if (vec[i][j] == 1) { // 해당 좌표의 요소가 블록이면 
				
				// 갱신
				start_idx = end_idx;
				end_idx = j;
				if (start_idx != -1 && end_idx != -1) { // 두 인덱스가 초기값이 아닐 때 
					if (end_idx - start_idx > 1) { // 사이에 공간이 존재하면 
						res += (end_idx - start_idx - 1); // 사이의 빈칸만큼 더하기 
					}
				}
			}
		}
	}

	cout << res;

	return 0;
}