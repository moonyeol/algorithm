//���̾Ƹ��*�����
//�߰� �κ��� *�� ����(Ȧ��)�� �Է¹ް� ���̾Ƹ�� ����Ͻÿ�.

#include <stdio.h>

int main(void) {
	int n;
	while (1) {
		printf("�߰� �κ� �� ����(Ȧ����) : ");
		scanf("%d", &n);
		if (n %2 == 0)
			printf("Ȧ���� �Է����ּ���\n");
		else
			break;
	}
		for (int i = 0; i < (int)(n/2)+1 ; i++) {
			for (int j = 0; j < (int)(n/2) - i ; j++)
				printf(" ");
			for (int j = 0; j < 2*i+1  ; j++)
				printf("*");
			printf("\n");
		}
		for (int i = (int)(n/2)  ; i >= 0; i--)
		{
			for (int j = 0; j < (int)(n/2) - i +1; j++)
				printf(" ");
			for (int j = 0; j < (2 * i - 1); j++)
				printf("*");
			printf("\n");
		}
	return 0; 
}


