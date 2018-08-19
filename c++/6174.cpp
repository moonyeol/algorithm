/*
1949 �� �ε� ������ Kaprekar �� Kaprekar ������ ����س´�. Kaprekar ������ �� �ڸ� �� �� ��� �ڸ����� ���� ���� ��(1111, 2222 ���� ������)�� �� �ڸ��� ���ڸ� ��迭�ؼ� ���� �� �ִ� ���� ū ���� ���� ���� ���� ���� �� ���̸� ����ϴµ�, �� ����� ���� ���ο� ���ڸ� ���� ���� ������ �ݺ��ϴ� ���̴�.

������ ���������� Kaprekar �� �� ������ ���� ����� �����شٴ� ���� �߰��ߴ�. ���� ������ 2008 �� �� ����� �˾ƺ���. 2008 �� ���� �� �ִ� ���� ū ���� 8200 �̰� ���� ���� ���� 0028 �̴�.

8200 - 0028 = 8172
8721 - 1278 = 7443
7443 - 3447 = 3996
9963 - 3699 = 6264
6642 - 2466 = 4176
7641 - 1467 = 6174
7641 - 1467 = 6174
6174 �� ������ �������� �Ź� 6174 �� ����� ����. 2008 ���� ���� 6174 �� �����ϴ� ���� �ƴ϶� �� ���ڷ� �̷������ ���� ��� �� �ڸ� ���� Kaprekar ������ ���� 6174 �� ���� �ȴ�. 2008 �� ��� 6 �ܰ踦 ���� 6174 �� ���� �Ǿ��µ�, �ٸ� ���ڰ� �Է����� �־����� �� �� �ܰ� ���� 6174 �� ������ �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
�Է�
�� �ٿ� �� �ڸ� ��(1000~9999)�� �ϳ��� �־�����. ��, �� ���ڴ� 1111, 2222 ó�� �ϳ��� ���ڷ� �̷���� ���� �����Ѵ�.
���
Kaprekar ������ ���� �� �ܰ� ���� 6174�� �Ǵ��� ����Ͻÿ�.
����� ��
�Է�

6174

���

0

�Է�

1789

���

3

�Է�

2005

���

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

/*�������� c++����� �����Ҵ�κп��� ��û ��̴�.
���� �˰����� Ʋ���پ˰� ��� ���ƴ��� �𸣰ڴ�.
������ �� ��ư� Ǭ�Ű��⵵ �ϰ�...*/