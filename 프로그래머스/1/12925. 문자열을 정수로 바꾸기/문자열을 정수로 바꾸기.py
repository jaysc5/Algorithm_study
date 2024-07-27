def solution(s):
    answer = 0
    flag = 0

    for c in s:
        if c == '+':
            flag = 1
            continue
        elif c == '-':
            flag = 2
            continue
        answer = answer * 10 + ord(c) - ord('0')

    if flag == 1:
        return +answer
    elif flag == 2:
        return -answer
    
    return answer