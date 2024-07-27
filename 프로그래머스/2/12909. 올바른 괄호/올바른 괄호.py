def solution(s):
    stack = []
    
    for st in s:
        stack.append(st)
        if stack[-2:] == ['(', ')']:
            stack.pop()
            stack.pop()
            
    return stack == []