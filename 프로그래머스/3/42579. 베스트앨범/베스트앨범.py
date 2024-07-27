def solution(genres, plays):
    answer = []
    music = list(zip(plays, genres, range(len(genres))))
    genres_count = dict.fromkeys(set(genres),0)
    play_count = {}
    
    for p, g, i in music:
        genres_count[g] += p
        
        if g not in play_count:
            play_count[g] = [(i, p)]
        else:
            play_count[g].append((i,p))
    
    for (g, c) in sorted(genres_count.items(), key=lambda x:x[1], reverse=True):
        for (i, p) in sorted(play_count[g], key=lambda x:x[1], reverse=True)[:2]:
            answer.append(i)

    return answer