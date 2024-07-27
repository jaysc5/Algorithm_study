from collections import Counter

def solution(X, Y):
    num = Counter(X) & Counter(Y)
    num_count = sorted(list(num), reverse = True)
    
    if not num: return '-1'
    if list(num) == ['0']: return '0'    
    return ''.join(n*num[n] for n in num_count)