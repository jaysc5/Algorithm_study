from collections import Counter

def solution(N, stages):
    fail = {}
    people = len(stages)
    
    for n in range(1, N+1):
        if people == 0:
            fail[n] = 0
        else:
            fail[n] = stages.count(n)/people
            people -= stages.count(n)

    return sorted(fail, key=lambda i: fail[i], reverse=True)