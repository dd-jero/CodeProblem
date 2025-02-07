#include <iostream>
#include <string>
using namespace std;

string s, t;
int res = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> s >> t;

	int s_size = s.size();
	int t_size = t.size();

	int max_length = s_size > t_size ? s_size : t_size;

	for (int i = 0;i < max_length * 2;i++) {
		if (s[i % s_size] != t[i % t_size]) {
			res = 0; // 다르면
			break;
		}
	}

	cout << res << "\n";

	return 0;
}