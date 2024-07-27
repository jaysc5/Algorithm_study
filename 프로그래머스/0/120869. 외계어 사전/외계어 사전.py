def solution(spell, dic):
    spell = set(spell)
    for d in dic:
        if sorted(d) == sorted(spell):
            return 1
    return 2