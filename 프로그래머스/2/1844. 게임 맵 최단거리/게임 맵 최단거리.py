from collections import deque

def solution(maps):
    n = len(maps)
    m = len(maps[0])

    start_x, start_y = 0, 0
    end_x, end_y = n-1, m-1

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    q = deque()
    q.append((start_x, start_y))

    maps[start_x][start_y] = 100 + 1
    answer = -1
    
    while q:
        x, y = q.popleft()
        if (x, y) == (end_x, end_y):
            answer = maps[x][y]
            break

        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            if 0<=nx<n and 0<=ny<m and maps[nx][ny] == 1:
                q.append((nx, ny))
                maps[nx][ny] = maps[x][y] + 1
    return answer - 100