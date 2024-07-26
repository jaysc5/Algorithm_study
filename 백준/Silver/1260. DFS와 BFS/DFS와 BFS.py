from collections import defaultdict, deque

n, m, v = map(int, input().split())
dic = defaultdict(list)

for _ in range(m):
    s, e = map(int, input().split())
    dic[s].append(e)
    dic[e].append(s)

for key, value in dic.items():
    dic[key] = sorted(value)

## dfs stack, 재귀
visited = set()
visited.add(v)

def dfs(node):
    print(node, end=" ")
    for next_node in dic[node]:
        if next_node not in visited:
            visited.add(next_node)
            dfs(next_node)
        
dfs(v)
print()

## bfs

queue = deque()
queue.append(v)

visited = set()
visited.add(v)

while queue:
    node = queue.popleft()
    print(node, end=" ")
    for next_node in dic[node]:
        if next_node in visited:
            continue
        queue.append(next_node)
        visited.add(next_node)
print()
