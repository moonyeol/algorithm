def solution(money):
    answer = 0
    dp = [0 for _ in range(len(money))]
    dp[0] = money[0]
    dp[1] = max(money[1], money[0])
    for i in range(2, len(money) - 1):
        dp[i] = max(money[i] + dp[i - 2], dp[i - 1])
    dp2 = [0 for _ in range(len(money))]
    dp2[0] = 0
    dp2[1] = money[1]
    for i in range(2, len(money)):
        dp2[i] = max(money[i] + dp2[i - 2], dp2[i - 1])

    answer = max(dp[len(money) - 2], dp2[len(money) - 1])
    return answer