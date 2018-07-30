//피보나치 수열
#include <stdio.h>



void main() {

	int fib(int* n);

	int n, k;

	int* m;

	printf("숫자를 입력하시오");

	scanf("%d", &n);

	m = &n;

	k = fib(m);

	printf("%d번째 항은 %d\n", n, k);

}





int fib(int* n) {         //피보나치 함수

	if (*n < 2) return 1;       //n값이 2보다 작으면 1값을 반환

	else {

		int i, tmp, last = 1, current = 1;   //last가 0번째항, current가 1번째 항이라 가정

		for (i = 2;i < *n;i++) {     //i가 2부터 n값이 될때까지 반복

			tmp = current;       //tmp에 current 값 저장

			current += last;      //current에 last값 더해서 저장

			last = tmp;        //tmp에 저장했던 current값이 last가 됨

		}

		return current;        //current 반환

	}

}