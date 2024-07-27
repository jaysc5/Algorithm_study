def solution(today, terms, privacies):
    answer = []
    terms_dict  = {terms[i].split()[0] : terms[i].split()[1] for i in range(0, len(terms))}

    y,m,d = today.split('.')
    today = int(y)*12*28 + int(m)*28 + int(d)
    
    for i, value in enumerate(privacies):
        date, key = value.split()
        if key in list(terms_dict.keys()):
            val = terms_dict[key]
            print(val)
            
            yy, mm, dd = date.split('.')
            date = int(yy)*12*28 + int(mm)*28 + int(dd) + int(val)*28 - 1
            if date < today:
                answer.append(i+1)

                
                
    return answer