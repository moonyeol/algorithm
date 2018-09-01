'''
프로그램 명: inversion
제한시간: 1 초
1 부터 n 까지의 수를 한 번씩만 사용하여 이루어진 수열이 있을 때, 1 부터 n 까지 각각의 수 앞에 있는 자신보다 큰 수들의 개수를 수열로 표현한 것을 inversion sequence 라 한다.

예를 들어 다음과 같은 수열의 경우

4 8 6 2 5 1 3 7
1 앞에 놓인 1 보다 큰 수는 4 , 8 , 6 , 2 , 5 로 5 개이고 ,
2 앞에 놓은 2 보다 큰 수는 4 , 8 , 6 으로 3 개
3 앞에 놓인 3 보다 큰 수는 4 , 8 , 6 , 5 로 4 개
따라서 4 8 6 2 5 1 3 7 의 inversion sequence 는 5 3 4 0 2 1 1 0 이 된다.
n 과 1 부터 n 까지의 수를 사용하여 이루어진 수열의 inversion sequence 가 주어졌을때 원래의 수열을 출력하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 1000 이하의 자연수 n 이 주어진다.
두 번째 줄에는 inversion sequence 가 숫자 사이에 한 칸의 공백을 두고 주어진다.
출력
원래의 수열을 출력한다.
입출력 예
입력

8
5 3 4 0 2 1 1 0

출력

4 8 6 2 5 1 3 7
'''



nums = list(map(int, input().split()))
newnums = []
count = 0
for i in range(1, len(nums)+1):
    newnums.append(0)
    k = nums.index(i)
    for j in range(k):
        if nums[k] < nums[j]:
            newnums[count] += 1
    count += 1
for i in newnums:
    print(str(i), end=" ")