//�����̹迭
#include <stdio.h>

void snail(int** arr, int* num, int n, int* x, int* y, int direct);

void main(){		
	int** arr;	//�迭
	int num = 0, x = -1, y = 0;	//num : �迭�� �� ���ڰ�, x: �迭�� ��(����Լ� �� �˰���� +1�� ���� ���������̹Ƿ� -1�� �ʱ�ȭ), y: �迭�� ��
	int n;
	printf("���ڸ� �Է��Ͻÿ� : ");
	scanf("%d", &n);
	
	arr = (int**)malloc(sizeof(int*)*n);	//2���� �迭 �����Ҵ�
	for (int i = 0; i<n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
	}

	snail(arr, &num, n, &x, &y, 1);

	for (int i = 0; i <n; i++) {	//�迭 ���
		for (int j = 0;j <n;j++) {
			printf("\t%d", arr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i<n; i++) {	//���� �Ҵ� ����
		free(arr[i]);
	}
	free(arr);
}

void snail(int** arr, int* num, int n, int* x, int* y, int direct) {	//������ �迭 ������ ���� ����Լ�
	if (n == 0) return;		//n�� 0�� �����ϸ� ����Լ��� ��������

	for (int i = 0; i<2 * n - 1; i++)	//����, �ѿ��� ���� �־��شٰ� �����ϸ� ��, (��, �� ������� �����ϸ� ��)
	{
		if (i < n) *x += direct;	//1�� �����ϰų� ���� 0~n-1(n��)
		else *y += direct;	//x�� n-1�̳� 0�� �����ϸ� y�� 1�� �����ϰų� ���� n~2n-1(n��)
		*(*(arr + *y) + *x) = ++(*num);	//�迭�� ��ĭ�� 1�� ������ ���� ����
	}
	snail(arr, num, n - 1, x, y, direct * (-1));	//�̸� ��������� �ݺ�, direct�� ��ȣ�� �ݴ�� �־���� �ݺ������� ����,���� �� ����
													//����->����->����->���� �̸� �ݺ��ϴ� ��
}