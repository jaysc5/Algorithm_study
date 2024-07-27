def solution(s):
    answer = ''
    count = dict.fromkeys(sorted(s), 0)
    
    for x in s:
        count[x] += 1
    count = {key: value for key, value in count.items() if value == 1 } 

    for key in count:
        answer += key
        
    return answer