answer = 0
def solution(k, dungeons):
    visited = []
    
    def dfs(k, clear): #피로도, 클리어
        global answer
        answer = max(answer, clear)
        
        for idx, dungeon in enumerate(dungeons):
            if idx in visited:
                continue
            if k < dungeon[0]:
                continue
                
            visited.append(idx)
            dfs(k-dungeon[1], clear+1)
            visited.pop()
    dfs(k, 0)
    return answer