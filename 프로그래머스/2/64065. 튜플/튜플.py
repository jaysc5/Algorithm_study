def solution(s):
    answer = []
        
    s = s.lstrip('{').rstrip('}').split('},{')
    s.sort(key = len)
    
    for st in s:
        num = st.split(",")
        for n in num:
            if int(n) not in answer:
                answer.append(int(n))
        
    return answer