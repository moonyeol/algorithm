'''
문제 설명

위와 같은 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 합니다. 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능합니다. 예를 들어 3에서는 그 아래칸의 8 또는 1로만 이동이 가능합니다.

삼각형의 정보가 담긴 배열 triangle이 매개변수로 주어질 때, 거쳐간 숫자의 최댓값을 return 하도록 solution 함수를 완성하세요.

제한사항
삼각형의 높이는 1 이상 500 이하입니다.
삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수입니다.
입출력 예
triangle	result
[[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]	30
'''


def solution(triangle):
    answer = 0
    level = 1

    now = triangle[0]
    while level < len(triangle):
        temp = [0 for i in range(len(triangle[level]))]
        for i, v in enumerate(now):
            if i == 0:
                temp[i] = v + triangle[level][i]
            else:
                temp[i] = max(v + triangle[level][i], now[i - 1] + triangle[level][i])
            if i == len(now) - 1:
                temp[i + 1] = v + triangle[level][i + 1]

        level += 1
        now = temp
    answer = max(now)
    print(now)
    return answer