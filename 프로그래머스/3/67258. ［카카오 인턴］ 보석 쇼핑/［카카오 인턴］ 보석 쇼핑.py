def solution(gems):
    answer = []
    start, end = 0, 0
    contained = {}
    check_len = len(set(gems))
    shortest = len(gems) + 1
    while end < len(gems):
        contained[gems[end]] = contained.get(gems[end], 0) + 1
        end += 1 # 끝 점 증가
        
        if len(contained) == check_len:
            while start < end:
                if contained[gems[start]] > 1:
                    contained[gems[start]] -= 1 
                    start += 1
                elif shortest > end - start:
                    shortest = end - start
                    answer = [start+1, end]
                    break
                else:
                    break

    return answer