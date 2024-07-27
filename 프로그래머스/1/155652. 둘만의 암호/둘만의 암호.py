def solution(s, skip, index):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    answer = ''
    
    for sk in skip:
        alphabet = alphabet.replace(sk,'')
        
    for x in s:
        idx = (alphabet.index(x) + index) % len(alphabet)
        answer += alphabet[idx]
        
    return answer