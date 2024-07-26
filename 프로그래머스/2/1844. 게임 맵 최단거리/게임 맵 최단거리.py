from collections import deque

def solution(maps):
    answer = -1
    n, m = len(maps), len(maps[0])
    start_x, start_y = 0, 0
    end_x, end_y = n-1, m-1
    
    queue = deque()
    queue.append((start_x, start_y, 1))

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    
    visited = set()
    visited.add((start_x, start_y))
    
    while queue:
        x, y, distance = queue.popleft()
        if (x, y) == (end_x, end_y):
            answer = distance
        
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            
            if 0<=nx<n and 0<=ny<m and maps[nx][ny]==1 and (nx, ny) not in visited:
                queue.append((nx, ny, distance+1))
                visited.add((nx, ny))
    return answer