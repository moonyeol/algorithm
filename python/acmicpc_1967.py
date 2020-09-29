import collections
import sys
import heapq

def dijkstra(N, V, distance):
    ans = [0, 0]
    # N은 출발점
    global tree
    heap = []
    visited = 1 << (V + 1)
    distance[N] = 0
    heapq.heappush(heap,[0,N])
    while heap:
        weight, Node = heapq.heappop(heap)
        visited = visited | 1 << Node
        for k, w in tree[Node].items():
            if visited & 1 << k:
                continue
            via = weight + w
            if distance[k] < via:
                distance[k] = via
                heapq.heappush(heap,[via,k])
            if ans[1] < distance[k]:
                ans[1] = distance[k]
                ans[0] = k
    return ans

input = sys.stdin.readline
n = int(input())
if n == 1:
    print(0)
else:
    tree = dict()
    distance = []
    for i in range(n - 1):
        temp = list(map(int, input().split()))
        if not temp[0] in tree:
            tree[temp[0]] = dict()
        if not temp[1] in tree:
            tree[temp[1]] = dict()
        tree[temp[0]][temp[1]] = temp[2]
        tree[temp[1]][temp[0]] = temp[2]
    ans = 0
    distance = [-1 for i in range(n + 1)]
    temp = dijkstra(1, n, distance)
    distance = [-1 for i in range(n + 1)]
    ans = dijkstra(temp[0], n, distance)
    print(ans[1])