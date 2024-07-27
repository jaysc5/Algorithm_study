def solution(babbling):
    answer = 0
    basic_babbling = ["aya", "ye", "woo", "ma"]
    
    for babble in babbling:
        for basic in basic_babbling:
            if babble.__contains__(basic):
                babble = babble.replace(basic, ' ')
								#포함된 부분 공백으로 바꾸기

        babble = babble.strip()
				#모두 공백일 경우만 발음 가능한 경우임
        if babble == '':
            answer += 1

    return answer
