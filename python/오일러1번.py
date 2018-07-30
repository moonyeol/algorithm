# 10보다 작은 자연수 중에서 3 또는 5의 배수는 3, 5, 6, 9 이고, 이것을 모두 더하면 23입니다.
# 1000보다 작은 자연수 중에서 3 또는 5의 배수를 모두 더하면 얼마일까요?
a = 1000
sum = 0
while a :
    a = a - 1
    if not(a%3 and a%5): sum=sum+a
    elif not(a%5) :sum = sum+ a
    elif not(a %3) : sum = sum + a
print(sum)