import sys
input=sys.stdin.readline

minNum, maxNum = map(int,input().split())
visited = [True for _ in range(maxNum - minNum + 1)]
N = 1
count = 0
while N*N <= maxNum:
    N += 1
    square = N * N
    i = minNum // square
    while square *i <= maxNum:
        idx = square * i - minNum
        if idx >= 0 and visited[idx]:
            count +=1
            visited[idx] = False
        i += 1
ans = len(visited) - count
print(ans)
