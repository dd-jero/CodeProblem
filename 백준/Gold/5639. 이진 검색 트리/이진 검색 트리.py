from collections import deque
class node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self,data):
        if self.root is None: # root 노드가 비어있으면
            self.root = node(data) # 새로운 노드를 생성하고 root로 지정 
        else:
            self.base = self.root # 현재 노드를 root 노드로 가리킴 

            while 1:
                if data == self.base.data: # 이미 해당 데이터가 노드에 존재한다면 
                    break
                elif data > self.base.data: # 현재 노드 보다 새로운 값이 더 크면
                    if self.base.right is None: # 현재 노드의 오른 자식 노드가 비어 있으면
                        self.base.right = node(data)
                        break
                    else:   # 비어 있지 않으면
                        self.base = self.base.right # 현재 노드의 오른 자식 노드를 현재 노드로 설정 
                
                else: # 현재 노드보다 새로운 값이 더 작으면 
                    if self.base.left is None: # 현재 노드의 왼쪽 자식 노드가 비어 있으면
                        self.base.left = node(data) 
                        break
                    else:   # 비어 있지 않으면           
                        self.base = self.base.left # 현재 노드의 왼쪽 자식 노드를 현재 노드로 설정

    def postorder(self, root): # 후위 순회: 왼-> 오-> 루트
        if not root:
            return

        stack = deque()
        visited = set()
        current = root

        while stack or current:
            if current:
                stack.append(current)
                current = current.left
            else:
                top = stack[-1]
                if top.right and top.right not in visited:
                    current = top.right
                else:
                    visited.add(top)
                    print(top.data)
                    stack.pop()

values = []

while True:
    try:
        val = input()
        values.append(int(val))
    except:
        break

tree = BST()

for v in values:
    tree.insert(v)

tree.postorder(tree.root)