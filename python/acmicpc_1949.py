import sys
sys.setrecursionlimit(20000)
def dfs(now):
    global visited, populations, tree
    visited[now] = True
    dp[now][0] = populations[now]

    for i in tree[now]:
        if not visited[i]:
            dfs(i)
            dp[now][0] += dp[i][1]
            dp[now][1] += max(dp[i][0],dp[i][1])

input = sys.stdin.readline
N = int(input())
if N == 1:
    print(input())
else:
    dp = [[0,0] for _ in range(N+1)]
    visited = [False for _ in range(N+1)]
    populations = [0]
    tree = dict()
    populations += list(map(int,input().split()))
    for i in range(N-1):
        temp = list(map(int, input().split()))
        if not temp[0] in tree:
            tree[temp[0]] = set()
        if not temp[1] in tree:
            tree[temp[1]] = set()
        tree[temp[0]].add(temp[1])
        tree[temp[1]].add(temp[0])
    dfs(1)
    ans = max(dp[1][0], dp[1][1])

    print(ans)

