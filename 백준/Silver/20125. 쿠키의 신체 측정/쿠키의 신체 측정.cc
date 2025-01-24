#include <iostream>
#include <string>
using namespace std;

int n, heart_x, heart_y, cnt_leftarm = 0, cnt_rightarm = 0, cnt_center = 0, cnt_leftleg = 0, cnt_rightleg = 0;
char arr[1001][1001];

void Count(int x, int y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1;i < n+1;i++) {
		string str;
		cin >> str;
		for (int j = 1; j < n + 1;j++) {
			arr[i][j] = str[j-1];
		}
	}

	for (int i = 2;i < n;i++) {
		for (int j = 2;j < n;j++) {
			if (arr[i - 1][j] == '*' &&  arr[i + 1][j] == '*' && arr[i][j - 1] == '*' && arr[i][j + 1] == '*') {
				heart_x = i;
				heart_y = j;
			}
		}
	}

	Count(heart_x, heart_y);
	cout << heart_x << " " << heart_y << "\n";
	cout << cnt_leftarm << " " << cnt_rightarm << " "<< cnt_center << " " << cnt_leftleg << " " << cnt_rightleg << "\n";
	return 0;
}

void Count(int x, int y) {

	// 왼팔
	for (int i = y-1; i > 0; i--) {
		if (arr[x][i] == '*') cnt_leftarm++;
	}

	// 오른팔
	for (int i = y+1;i < n + 1;i++) {
		if (arr[x][i] == '*') cnt_rightarm++;
	}

	// 왼다리, 몸통, 오른다리
	for (int i = x + 1; i < n + 1;i++) {
		if (arr[i][y - 1] == '*') cnt_leftleg++;
		if (arr[i][y] == '*') cnt_center++;
		if (arr[i][y + 1] == '*') cnt_rightleg++;
	}
}