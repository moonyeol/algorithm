/*
1
1 1
1 2
1 1 2 1
1 2 2 1 1 1
1 1 2 2 1 3
1 2 2 2 1 1 3 1
1 1 2 3 1 2 3 1 1 1 ...
������ ��Ģ�� �����ϴ� �ڵ带 �ϼ��ϵ�
ũ�Ⱑ 30�� �迭�� �����ϰ�, �Է��� ������ ���� 0���� �Ѵ�.
���� ���
�Է��� 1 1 2 1 0 �̸�
����� 1 2 2 1 1 1�� �Ǿ�� �Ѵ�.*/
#include <stdio.h>



void main() {

	int array[30];

	int narray[30];

	int i = 0, m = 0;

	int ncount = 1, tmp = 1;

	while (1) {

		scanf("%d", &array[i]);

		if (array[i] == 0) break;

		i++;

	}



	for (int k = 0; k < i;k++) {

		if (array[k] == array[k + 1]) {



			ncount++;

		}

		else {

			narray[m] = array[k];

			narray[m + 1] = ncount;

			m += 2;



			ncount = 1;

		}



	}

	for (int k = 0; k < m; k++) {

		printf("%d ", narray[k]);

	}

}