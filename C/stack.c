/*스택 프로그램
스택이란 컴퓨터의 기본 자료 구조 중 하나로 LIFO(Last In, First Out). 즉, 데이터를 후입선출 구조로 유지하는 자료 구조이다. 스택은 두 가지의 기본 연산으로 구성되어있는데, 첫 번째, 삽입(push)와 두 번째, 삭제(pop)가 있다. 먼저 삽입 연산은 입력한 데이터를 스택의 제일 높은 위치에 저장하고, 기존에 있는 데이터들은 그 아래에 두도록 하는 연산이다. 마찬가지로 삭제 연산은 스택의 제일 높은 위치에 있는 데이터를 제거하고 기존에 있는 데이터들은 스택에 남기는 연산이다.
크기가 10인 배열을 설정하고, Push, Pop, Show(스택에 있는 데이터들을 출력)연산을 수행하는 프로그램을 만드시오.*/

#include <stdio.h>

void main() {
	int n;
	int array[10];
	int i = 0;

	printf("========== 메뉴 ==========\n");
	printf(" push : 1 \n pop : 2 \n show : 3\n");
	printf("종료 하려면 1,2,3 이외의 수 입력\n\n");

	while (1) {

		if (i == 10) {
			printf("10개 다 찼습니다");
			return;
		}

		printf("메뉴를 입력하세요 : ");
		scanf("%d", &n);

		switch (n) {
		case 1:
			printf("수입력 : ");
			scanf("%d", &array[i++]);
			break;
		case 2:
			array[i--] = 0;
			break;
		case 3:
			for (int k = 0; k < i; k++) {
				printf("%d ", array[k]);
			}
			printf("\n");
			break;
		default: return;
		}
	}
}