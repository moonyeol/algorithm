//�Ǻ���ġ ����
#include <stdio.h>



void main() {

	int fib(int* n);

	int n, k;

	int* m;

	printf("���ڸ� �Է��Ͻÿ�");

	scanf("%d", &n);

	m = &n;

	k = fib(m);

	printf("%d��° ���� %d\n", n, k);

}





int fib(int* n) {         //�Ǻ���ġ �Լ�

	if (*n < 2) return 1;       //n���� 2���� ������ 1���� ��ȯ

	else {

		int i, tmp, last = 1, current = 1;   //last�� 0��°��, current�� 1��° ���̶� ����

		for (i = 2;i < *n;i++) {     //i�� 2���� n���� �ɶ����� �ݺ�

			tmp = current;       //tmp�� current �� ����

			current += last;      //current�� last�� ���ؼ� ����

			last = tmp;        //tmp�� �����ߴ� current���� last�� ��

		}

		return current;        //current ��ȯ

	}

}