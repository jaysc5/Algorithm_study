def solution(id_pw, db):
    answer = ''
    db = dict(db)
    
    if id_pw[0] in db.keys():
        if id_pw[1] == db[id_pw[0]]:
            answer = "login"
        else:
            answer = "wrong pw"
    else:
        answer = "fail"
        
    return answer