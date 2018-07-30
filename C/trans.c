#include <stdio.h>



int main(void) {
	float n;									//실수 값을 받기위한 변수
	char c = 'c';
	void translat2(float num);					//정수를 2진수로 변환 시키는 함수 선언
	void translate1(int num);					//소수를 2진수로 변환 시키는 함수 선언
	while (1) {									
		printf(">>");							
		scanf("%f", &n);						//n값을 입력받음
		if (n - (int)n == 0) {					//n이 정수라면 translate1을, 아니라면 translate2를 실행
			translate1((int)n);
		}
		else {
			translat2(c);
		}
	}
	return 0;
}




void translate1(int num, int m) {							//10진수 정수를 2진법으로 표시하는 함수
	int tmp = num;									// num값을 tmp에 저장
	int b[32];										//2진수를 저장할 배열
	int i;
	printf("십진수 %d 를 이진수로 변환\n", num);	
	printf("\t");

	for (i = 0; tmp != 1; i++) {				//반복문을 통해 tmp에 든값을 2진수로 b에 저장
		printf("%d\t.....",tmp);
		b[i] = tmp % 2;							//tmp값을 2로 나눈 나머지 값을 배열에 저장
		tmp = tmp / 2;							//tmp에 tmp를 2로 나눈 값을 저장
		printf("%d\n", b[i]);
		printf("/2\t");
	}
	b[i] = tmp;									//반복문을 바져나온 tmp에 저장되있는 1을 b에 저장
	printf("%d\t.....%d\n", b[i], b[i]);
	for (int j = i; j >= 0; j--) {				// 반복문을 통해 b에 저장 시킨 값을 역순으로 표시함
		printf("%d ", b[j]);
		if (j != 0 && j % 4 == 0) {				//j가 0이 아닐때와 4의 배수일때 '/'를 표시함
			printf("/ ");
		}

	}

	printf("\n십진수 %d 를 16진수로 변환 : %x\n", num, num);	//num값을 16진수로 표시함

}


void translat2(float num, int m) {							//소수점 값을 2진수로 표시하는 함수
	int b[32];
	int i;
	
	num = num - (int)num;

	printf("1미만의 소수점수%.6f를 이진수로 변환\n", num);
	printf("\t%.2f\t.... %d\n", num, (int)num);

	for (i = 0; i != 12; i++) {						//반복문을 통해 소수점수를 2진법으로 표시
		printf("x2 = ");
		num = num * 2;								//num에 2를 곱함
		b[i] = num;									//2를 곱한 num의 1의 자리를 b에 저장
		printf("\t%.2f\t.... %d\n", num, b[i]);
		if ((int)num == 1) {						//num의 1의 자리가 1이 라면 1을 빼준다
			num = num - 1;
			printf("-1 = \t%.2f\n", num);
		}
	}
	printf("0. ");

	for (int j = 0; j < i; j++) {					//반복문을 통해 b에 저장한 num의 2진수를 표시한다
		printf("%d ", b[j]);
		if ((j + 1) % 4 == 0) {						//j가 0부터 이므로 j+1이 4의 배수라면 '/'를 표시한다.
			printf("/ ");
		}
	}
	printf("\n");

}

