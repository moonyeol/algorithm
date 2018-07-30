//다이아몬드*만들기
//중간 부분의 *의 개수(홀수)를 입력받고 다이아몬드 출력하시오.

#include <stdio.h>

int main(void) {
	int n;
	while (1) {
		printf("중간 부분 별 개수(홀수만) : ");
		scanf("%d", &n);
		if (n %2 == 0)
			printf("홀수만 입력해주세요\n");
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


