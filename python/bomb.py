'''
지뢰찾기 게임은 M x N 매트릭스에 위치해 있는 지뢰를 찾는 게임이다.

M x N 매트릭스 상의 격자(square)는 지뢰이거나 지뢰가 아니다.

지뢰 격자는 *로 표시한다. 지뢰가 아닌 격자(square)는 숫자로 표시하며 그 숫자는 인접해 있는 지뢰의 수를 의미한다. (격자(sqaure)는 최대 8개의 인접한 지뢰를 가질 수 있다.)
'''
x = int(input("열 크기 :"))
y = int(input("행 크기 :"))

i_arr =[[0 for i in range(x+2)] for j in range(y+2)]
b_arr =[[0 for i in range(x)] for j in range(y)]

i_arr[0] = ['.' for i in range(x+2)]


for i in range(0,x) :
    i_arr[i+1] = list('.' +input() +'.')


i_arr[-1] = ['.' for i in range(x+2)]


for i in range(1,x+1) :
    for j in range(1,x+1) :
        if i_arr[i][j]!='*' :
            b_arr[i-1][j-1] = [i_arr[i-1][j-1], i_arr[i-1][j],  i_arr[i-1][j+1],i_arr[i][j-1],i_arr[i][j+1],i_arr[i+1][j-1], i_arr[i+1][j], i_arr[i+1][j+1]].count('*')
        else :
            b_arr[i-1][j-1] = '*'

for i in range(0,y) :
    print(b_arr[i])
