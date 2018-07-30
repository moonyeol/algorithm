//달팽이배열
#include <stdio.h>

void snail(int** arr, int* num, int n, int* x, int* y, int direct);

void main(){		
	int** arr;	//배열
	int num = 0, x = -1, y = 0;	//num : 배열에 들어갈 숫자값, x: 배열의 열(재귀함수 내 알고리즘상 +1이 먼저 더해질것이므로 -1로 초기화), y: 배열의 행
	int n;
	printf("숫자를 입력하시오 : ");
	scanf("%d", &n);
	
	arr = (int**)malloc(sizeof(int*)*n);	//2차원 배열 동적할당
	for (int i = 0; i<n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
	}

	snail(arr, &num, n, &x, &y, 1);

	for (int i = 0; i <n; i++) {	//배열 출력
		for (int j = 0;j <n;j++) {
			printf("\t%d", arr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i<n; i++) {	//동적 할당 해지
		free(arr[i]);
	}
	free(arr);
}

void snail(int** arr, int* num, int n, int* x, int* y, int direct) {	//달팽이 배열 구현을 귀한 재귀함수
	if (n == 0) return;		//n이 0에 도달하면 재귀함수를 빠져나감

	for (int i = 0; i<2 * n - 1; i++)	//한행, 한열의 값을 넣어준다고 생각하면 됨, (ㄱ, ㄴ 모양으로 생각하면 됨)
	{
		if (i < n) *x += direct;	//1씩 증가하거나 감소 0~n-1(n개)
		else *y += direct;	//x가 n-1이나 0에 도달하면 y가 1씩 증가하거나 감수 n~2n-1(n개)
		*(*(arr + *y) + *x) = ++(*num);	//배열의 한칸에 1씩 증가된 값을 대입
	}
	snail(arr, num, n - 1, x, y, direct * (-1));	//이를 재귀적으로 반복, direct의 부호를 반대로 넣어줘야 반복문에서 증가,감소 가 가능
													//증가->감소->증가->감소 이를 반복하는 것
}