def solution(s):
    stack = []
    
    for st in s:
        if stack == []:
            stack.append(st)
        else:
            if st == stack[-1]:
                stack.pop()
            else:
                stack.append(st)

    return 1 if stack == [] else 0