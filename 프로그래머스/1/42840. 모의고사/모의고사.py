def solution(answers):
    score = [0,0,0]
    result = []
    p1 = [1, 2, 3, 4, 5]
    p2 = [2, 1, 2, 3, 2, 4, 2, 5]
    p3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    
    for i in range(len(answers)):
        if p1[i%len(p1)] == answers[i]:
            score[0] += 1
        if p2[i%len(p2)] == answers[i]:
            score[1] += 1
        if p3[i%len(p3)] == answers[i]:
            score[2] += 1

    for idx, s in enumerate(score):
    	if s == max(score):
        	result.append(idx+1)

    return result