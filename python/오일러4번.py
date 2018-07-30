# 앞에서부터 읽을 때나 뒤에서부터 읽을 때나 모양이 같은 수를 대칭수(palindrome)라고 부릅니다.
# 두 자리 수를 곱해 만들 수 있는 대칭수 중 가장 큰 수는 9009 (= 91 × 99) 입니다.
# 세 자리 수를 곱해 만들 수 있는 가장 큰 대칭수는 얼마입니까?
c_num = []
for i in range(100,1000) :
    for j in range(100, 1000) :
        num = str(i*j)
        for k in range(len(num)) :
            if num[k] != num[-(k+1)] :
                break
        else :
            c_num.append(i*j)
print(max(c_num))