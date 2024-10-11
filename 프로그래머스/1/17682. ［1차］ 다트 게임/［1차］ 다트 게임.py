import re

def solution(dartResult):
    answer = []
    pattern = re.compile(r'([0-9]|10)([SDT])([\*\#]?)')
    cal = {
        'S':lambda n:n,
        'D':lambda n:n**2,
        'T':lambda n:n**3,        
    }
    
    for n, b, o in pattern.findall(dartResult):
        answer.append((cal[b](int(n))))
        
        if (o == '*'):
            answer[-1] *= 2
            if len(answer) >= 2:
                answer[-2] *= 2
        elif (o == '#'):
            answer[-1] *= -1
    
    return sum(answer)