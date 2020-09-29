import collections
import heapq
INF = float('inf')

def dijkstra(N, V, distance):
    ans = [0,0]
    #N은 출발점
    global tree
    queue = collections.deque()
    visited = [False] * (V+1)
    distance[N] = 0
    queue.append(N)
    while queue:
        Node = queue.popleft()
        visited[Node] = True
        for k, w in tree[Node]. items():
            if visited[k]: continue
            queue.append(k)
            via = distance[Node] + w
            if distance[k] < via:
                distance[k] = via
            if ans[1] < distance[k]:
                ans[1] = distance[k]
                ans[0] = k
    return ans


V = int(input())
tree = dict()
distance = []
for i in range(V):
    temp = list(map(int, input().split()))
    edges = dict()
    n = temp[0]
    for j in range(1,len(temp)-1,2):
        edges[temp[j]] = temp[j+1]
    tree[n] =edges
ans = 0
distance = [-1 for i in range(V + 1)]
temp = dijkstra(1,V,distance)
distance = [-1 for i in range(V + 1)]
ans = dijkstra(temp[0],V,distance)
print(ans[1])

