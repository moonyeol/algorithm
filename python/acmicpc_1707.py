import collections
import sys
input=sys.stdin.readline
def bfs(edges, vertex, visited,color):
    YES_FLAG = True
    color[vertex] = 1
    queue = collections.deque([vertex])
    while queue:
        node = queue.popleft()
        if visited[node]:
            continue
        c = color[node]
        visited[node] = True
        if node in edges:
            for link in edges[node]:
                if visited[link] and color[node] == color[link]:
                    YES_FLAG = False
                    return YES_FLAG
                elif not visited[link]:
                    color[link] = -c
                    queue.append(link)
    return YES_FLAG



K = int(input())
testCases = []
Vs = []
for i in range(K):
    edges = dict()
    V, E = map(int,input().split())
    for j in range(E):
        N, M = map(int, input().split())
        if not N in edges:
            edges[N] = set()
        if not M in edges:
            edges[M] = set()
        edges[N].add(M)
        edges[M].add(N)
    Vs.append(V)
    testCases.append(edges)

for idx, edges in enumerate(testCases):
    V = Vs[idx]
    visited = [False for _ in range(V+1)]
    color = [0 for _ in range(V+1)]
    for i in range(1,V+1):
        if not bfs(edges, i, visited, color):
            print("NO")
            break
    else:
        print("YES")


