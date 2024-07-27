def solution(survey, choices):
    answer = ''
    index = {"R" : 0,"T" : 0,"C" : 0,"F" : 0,"J" : 0,"M" : 0,"A" : 0,"N" : 0 }
    
    for s, c in zip (survey, choices):
        if c>4:
            index[s[1]] += c-4
        elif c<4:
            index[s[0]] += 4-c
            
    idx = list(index.items())
    for i in range(0,8,2):
        if idx[i][1] < idx[i+1][1]:
            answer += idx[i+1][0]
        else:
            answer += idx[i][0]
        
    return answer