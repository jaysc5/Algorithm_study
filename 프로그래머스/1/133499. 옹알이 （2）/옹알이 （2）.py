def solution(babbling):
    answer = 0
    basic_babbling = ["aya", "ye", "woo", "ma"]
    for babble in babbling:
        for basic in basic_babbling:
            if basic*2 not in babble:
                if babble.__contains__(basic):
                    babble = babble.replace(basic, ' ')

        babble = babble.strip()
        if babble == '':
            answer += 1

    return answer