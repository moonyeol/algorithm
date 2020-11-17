import heapq
INF = float('inf')

def dijkstra(start, N, distance,tree):
    ans = [0, 0]
    # N은 출발점
    heap = []
    visited = 1 << (N + 1)
    distance[start] = 0
    heapq.heappush(heap, [0, start])
    while heap:
        weight, Node = heapq.heappop(heap)
        visited = visited | 1 << Node
        for k, w in tree[Node].items():
            if visited & 1 << k:
                continue
            via = weight + w
            if distance[k] >= via:
                distance[k] = via
                heapq.heappush(heap, [via, k])



result = []
tree = dict()
reverse_tree = dict()
N, M, X = map(int, input().split())
for i in range(M):
    start, end, T = map(int, input().split())
    if not start in tree:
        tree[start] = dict()
    if not end in reverse_tree:
        reverse_tree[end] = dict()
    tree[start][end] = T
    reverse_tree[end][start] = T

distance1 = [INF for _ in range(N + 1)]
dijkstra(X, N, distance1, tree)
distance2 = [INF for _ in range(N + 1)]
dijkstra(X, N, distance2, reverse_tree)

for i in range(1,N+1):
    result.append(distance1[i]+distance2[i])
print(max(result))
