def solution(s):
    stack = []
    for st in s.split():
        if st == 'Z':
            stack.pop()
        else:
            stack.append(int(st))
    return sum(stack)