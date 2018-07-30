/*행렬의 성분은 행과 열의 합
n값을 입력받고(그림에서는 7), n x n 행렬을 완성하시오.
(이 때, 행렬의 각 성분은 해당 성분의 행과 열의 합)*/

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

