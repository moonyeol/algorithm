def solution(n, computers):
    answer = 0
    visited = [False for i in range(n)]
    for i in range(n):
        if visited[i] == False:
            DFS(n, computers, i, visited)
            answer += 1
    return answer

def DFS(n, computers, idx, visited):
    visited[idx] = True
    for connect in range(n):
        if connect != idx and computers[idx][connect] == 1:
            if visited[connect] == False:
                DFS(n, computers, connect, visited)