def solution(s):
    answer = s
    digit = [0,1,2,3,4,5,6,7,8,9]
    word = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    word_to_digit = dict(zip(word, digit))

    
    for key in word_to_digit:
        answer = answer.replace(key, str(word_to_digit[key]))   

    return int(answer)