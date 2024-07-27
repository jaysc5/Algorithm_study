def solution(people, limit):
    answer = 0
    people = sorted(people)
    left, right = 0, len(people)-1
    
    while left < right:
        if limit >= people[left] + people[right]:
            answer += 1
            left += 1
        right -= 1

    return len(people) - answer