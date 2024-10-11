def solution(dartResult):
    stack = []
    
    for idx, i in enumerate(dartResult):
        if i == 'S':
            pass
        elif i == 'D':
            stack[-1] **= 2
        elif i == 'T':
            stack[-1] **= 3
        elif i == '*':
            if (len(stack) >= 2):
                stack[-2] *= 2
            stack[-1] *= 2
        elif i == '#':
            stack[-1] *= -1
        else:
            if dartResult[idx:idx+2] == '10':
                stack.append(10)
            elif dartResult[idx-1:idx+1] != '10':
                stack.append(int(i))
    return sum(stack)