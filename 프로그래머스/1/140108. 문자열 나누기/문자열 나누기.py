def solution(s):
    answer = 0
    r = 0
    l = 0
    for st in s:
        if r == l:
            answer += 1
            tmp = st
            
        if st == tmp:
            r +=1
        else:
            l += 1

    return answer