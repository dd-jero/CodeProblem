#include <iostream>
using namespace std;

int N; // 노드의 개수
char tree[27][2];

void preorder(char n);
void inorder(char n);
void postorder(char n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	char parent, left, right;
	for (int i = 0;i < N;i++) {
		cin >> parent >> left >> right;
		tree[parent - 'A'][0] = left;
		tree[parent - 'A'][1] = right;
	}

	// 항상 A가 루트 노드
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";

	return 0;
}

void preorder(char n) { // 루트 -> 왼쪽 -> 오른쪽

	char left = tree[n - 'A'][0], right = tree[n - 'A'][1];

	// 1. 현재 노드 출력
	cout << n;

	// 2. 현재 노드의 왼쪽 자식
	if (left != '.') preorder(left);

	// 3. 현재 노드의 오른쪽 자식
	if (right != '.') preorder(right);
}

void inorder(char n) { // 왼쪽 -> 루트 -> 오른쪽

	char left = tree[n - 'A'][0], right = tree[n - 'A'][1];

	// 1. 현재 노드의 왼쪽 자식
	if (left != '.') inorder(left);

	// 2. 현재 노드 출력
	cout << n;

	// 3. 현재 노드의 오른쪽 자식
	if (right != '.') inorder(right);

}

void postorder(char n) { // 왼쪽 -> 오른쪽 -> 루트 
	char left = tree[n - 'A'][0], right = tree[n - 'A'][1];

	// 1. 현재 노드의 왼쪽 자식
	if (left != '.') postorder(left);

	// 2. 현재 노드의 오른쪽 자식
	if (right != '.') postorder(right);

	// 3. 현재 노드 출력
	cout << n;
}