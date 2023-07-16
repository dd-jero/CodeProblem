import sys

def preorder(root): # 전위 순회: 현재노드 -> 왼쪽노드 -> 오른노드 순으로 방문
    if root != '.':
        print(root,end="") 
        preorder(tree[root][0]) 
        preorder(tree[root][1]) 

def inorder(root): # 중위 순회: 왼쪽노드 -> 현재노드 -> 오른노드 순으로 방문
    if root != '.':
        inorder(tree[root][0])
        print(root,end="")     
        inorder(tree[root][1]) 

def postorder(root): # 후위 쉰회: 왼쪽노드 -> 오른노드 -> 현재노드 순으로 방문
    if root != '.':
        postorder(tree[root][0])
        postorder(tree[root][1])
        print(root,end="")

tree = {}
n = int(sys.stdin.readline())

for _ in range(n):
    cur, left, right = sys.stdin.readline().split()
    tree[cur] = [left, right] # 인덱스를 현재 노드, 0번째 요소를 왼쪽 자식, 1번째 요소를 오른 자식으로 하여 트리 형성

preorder('A')
print()
inorder('A')
print()
postorder('A')