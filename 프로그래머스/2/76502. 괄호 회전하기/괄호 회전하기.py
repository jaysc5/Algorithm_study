from collections import deque

def is_collect(s):
    dict = {']':'[', ')':'(', '}':'{' }
    queue = deque()
    for c in s:
        if c in ['[', '(', '{']:
            queue.append(c)
        else:
            if not queue:
                return False
            
            if queue[-1] == dict[c]:
                queue.pop()
            else:
                return False

    if queue:
        return False
    return True

def solution(s):
    answer = 0
    for i in range(len(s)):
        check = s[i:] + s[:i]
        answer += is_collect(check)
    return answer