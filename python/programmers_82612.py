def solution(price, money, count):
    answer = -1
    result = 0
    for i in range(1,count+1):
        result += price * i
    answer = result - money
    if answer < 0:
        answer = 0
    return answer