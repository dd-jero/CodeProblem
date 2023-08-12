import sys

def solution():
    stack = []

    for c in sentance:
        if c == '(' or c == '[':
            stack.append(c)

        elif c == ')':
            if len(stack) != 0 and stack[-1] == '(':
                stack.pop()
            else:
                stack.append(c)
                break
        elif c == ']':
            if len(stack) != 0 and stack[-1] == '[':
                stack.pop()
            else:
                stack.append(c)
                break

    if not stack:
        return 'yes'
    else:
        return 'no'

while 1:
    sentance = list(sys.stdin.readline().rstrip())
    if sentance == ['.']:
        exit()

    print(solution())