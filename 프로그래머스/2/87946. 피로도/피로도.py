def solution(k, dungeons):
    answer = -1
    visited = [0] * len(dungeons)
    
    def dfs(k, clear): #피로도, 클리어
        print(visited)
        for idx, dungeon in enumerate(dungeons):
            print(idx, dungeon)
            if not visited[idx]:
                visited[idx] = 1
                dfs(k-dungeon[1], clear+1)
                visited[idx] = 0
    dfs(k, 0)
    return answer