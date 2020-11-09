
N = int(input())
nums = list(map(int,input().split()))

ans = [0 for _ in range(N)]
for i in range(N):
    count = 0
    for j in range(N):
        if count >= nums[i] and ans[j] ==0:
            ans[j] = i+1
            break
        elif ans[j] == 0:
            count += 1

print(' '.join(map(str,ans)))