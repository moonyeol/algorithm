/*
1
1 1
1 2
1 1 2 1
1 2 2 1 1 1
1 1 2 2 1 3
1 2 2 2 1 1 3 1
1 1 2 3 1 2 3 1 1 1 ...
다음의 규칙을 만족하는 코드를 완성하되
크기가 30인 배열을 선언하고, 입력의 마지막 수는 0으로 한다.
예를 들어
입력이 1 1 2 1 0 이면
출력은 1 2 2 1 1 1이 되어야 한다.*/
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