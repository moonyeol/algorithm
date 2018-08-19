/*
1949 년 인도 수학자 Kaprekar 는 Kaprekar 연산을 고안해냈다. Kaprekar 연산은 네 자리 수 중 모든 자리수가 같지 않은 수(1111, 2222 등을 제외한)의 각 자리의 숫자를 재배열해서 만들 수 있는 가장 큰 수와 가장 작은 수를 만들어서 그 차이를 계산하는데, 그 결과로 나온 새로운 숫자를 갖고 같은 과정을 반복하는 것이다.

간단한 연산이지만 Kaprekar 는 이 연산이 놀라운 결과를 보여준다는 것을 발견했다. 올해 연도인 2008 로 그 결과를 알아보자. 2008 로 만들 수 있는 가장 큰 수는 8200 이고 가장 작은 수는 0028 이다.

8200 - 0028 = 8172
8721 - 1278 = 7443
7443 - 3447 = 3996
9963 - 3699 = 6264
6642 - 2466 = 4176
7641 - 1467 = 6174
7641 - 1467 = 6174
6174 에 도달한 다음에는 매번 6174 를 만들어 낸다. 2008 만이 유독 6174 에 도달하는 것이 아니라 한 숫자로 이루어지지 않은 모든 네 자리 수는 Kaprekar 연산을 통해 6174 로 가게 된다. 2008 의 경우 6 단계를 거쳐 6174 로 가게 되었는데, 다른 숫자가 입력으로 주어졌을 때 몇 단계 만에 6174 로 가는지 알아내는 프로그램을 작성하시오.
입력
한 줄에 네 자리 수(1000~9999)가 하나씩 주어진다. 단, 이 숫자는 1111, 2222 처럼 하나의 숫자로 이루어진 수는 제외한다.
출력
Kaprekar 연산을 통해 몇 단계 만에 6174가 되는지 출력하시오.
입출력 예
입력

6174

출력

0

입력

1789

출력

3

입력

2005

출력

7
*/


#include <iostream>

using namespace std;
int* Max(int arr[]);
void split(int num, int arr[]);
int* Min(int arr[]);
int makenum(int arr[]);
int fun(int nums[], int& count);

void split(int num,int arr[]) {
	arr[0] = num / 1000;
	arr[1] = num / 100- arr[0]*10;
	arr[2] = num / 10 - arr[1] * 10 - arr[0] * 100;
	arr[3] = num - arr[2] * 10 - arr[1] * 100 - arr[0] * 1000;
}

int *Max(int arr[]) {
	int* max = new int[4];
	int temp;
	for (int i = 0; i < 4; i++) {
		max[i] = arr[i];
	}
	for (int i = 0;i< 3;i++)
	{
		for (int j = i+1;j< 4;j++)
		{
			if (max[i] < max[j])
			{
				temp = max[j];
				max[j] = max[i];
				max[i] = temp;
			}
		}
	}

	return max;
}
int *Min(int arr[]) {
	int* min = new int[4];
	int temp;

	for (int i = 0; i < 4; i++) {
		min[i] = arr[i];
	}
	for (int i = 0;i< 3;i++)
	{
		for (int j = i + 1;j< 4;j++)
		{
			if (min[i] > min[j])
			{
				temp = min[j];
				min[j] = min[i];
				min[i] = temp;
			}
		}
	}
	
	return min;
}
int makenum(int arr[]) {
	return arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
}

int fun(int nums[],int& count) {
	if (makenum(nums) == 6174)
		return count;
	int* arr = new int[4];
	int num = makenum(Max(nums)) - makenum(Min(nums));
	count++;
	if (num == 6174)
		return count;
	split(num, arr);
	return fun(arr,count);
}


int main() {
	int num;
	int count = 0;
	int nums[4];
	int* min;
	int* max;
	cin >> num;
	split(num,nums);


	fun(nums, count);
	cout << count;
	return 0;
}

/*오랜만에 c++써봐서 동적할당부분에서 엄청 헤맸다.
정렬 알고리즘이 틀린줄알고 몇번 고쳤는지 모르겠다.
문제를 더 어렵게 푼거같기도 하고...*/