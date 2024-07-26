from collections import deque

n = int(input())
lst = [list(map(int, input())) for _ in range(n)]

def bfs (i, j):
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    q = deque()
    q.append((i, j))
    lst[i][j] = 0
    cnt = 1

    while q:
        x, y = q.popleft()

        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            if 0<=nx<n and 0<=ny<n and lst[nx][ny] == 1:
                lst[nx][ny] = 0
                q.append((nx, ny))
                cnt += 1
    return cnt


answer = []
for i in range(n):
    for j in range(n):
        if lst[i][j] == 1:
            answer.append(bfs(i, j))

print(len(answer))
for c in sorted(answer):
    print(c)