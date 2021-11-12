def solution(n, jump):
    answer = []
    array = [[0 for _ in range(n)] for _ in range(n)]

    array[0][0] = 1

    num = 1
    count = 0
    while num < n*n:
        x, y = 0, 0
        num, x, y, count = snail(x, y, num, array, jump, count, n, n, 1)
    answer = [y+1,x+1]
    return answer


def snail(x, y, num, array, jump, count, originN, n, direct):
    if n <= 0:
        return num, x, y, count
    for i in range((2 * n) -1):
        if i < n and 0 <= x + direct < originN:
            x += direct
        elif 0 <= y + direct < originN:
            y += direct
        else:
            break
        if array[x][y] == 0:
            count += 1
            if count == jump:
                num += 1
                array[x][y] = num
                count = 0
        if num == originN*originN:
            return num, x, y, count
    return snail(x, y, num, array, jump, count, originN, n - 1, -1*direct)
solution(5,3)