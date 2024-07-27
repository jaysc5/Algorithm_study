def solution(record):
    answer = []
    leave = []
    name = {}
    
    for re in record:
        re = re.split(" ")
        
        if re[0] == "Enter":
            name[re[1]] = re[2]
            leave += [re[1]+ "님이 들어왔습니다."]
        elif re[0] == "Leave":
            leave += [re[1]+ "님이 나갔습니다."]
        else:
            name[re[1]] = re[2]
    
    for l in leave:
        l = l.replace(l[0:l.index("님")], name[l[0:l.index("님")]])
        answer.append(l)
        
    return answer