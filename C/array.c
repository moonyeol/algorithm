/*����� ������ ��� ���� ��
n���� �Է¹ް�(�׸������� 7), n x n ����� �ϼ��Ͻÿ�.
(�� ��, ����� �� ������ �ش� ������ ��� ���� ��)*/

#include <stdio.h>



int main(void) {

	int i;

	scanf("%d", &i);

	for (int j = 1;j <= i;j++)

		for (int k = 1; k <= i;k++) {

			printf("%d ", k + j);

			if (k == i)

				printf("\n");

		}

}

