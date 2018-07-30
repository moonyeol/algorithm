//크기가 10인 정수형 배열을 선언하고, 10개의 정수를 입력받아 작은 수부터 차례대로 출력을 할 것. 
//오름차순

#include <stdio.h>


void main() {
	int n[10];
	void sort(int* arr);
	void swap(int* n1, int* n2);

	printf("수 10개를 입력하시오\n");

	for (int i = 0; i < 10; i++)
		scanf("%d", &n[i]);

	sort(n);

	for (int i = 0; i < 10; i++)
		printf("%d ", n[i]);
}

void sort(int* arr) {

	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (arr[i] > arr[j]) {    //tmp에 저장된 값이 n[j]보다 크다면 
				swap(&arr[i], &arr[j]);     //k번째와 i번째 값을 바꿔줌
			}
		}

	}
}


void swap(int* n1, int* n2) {
	int tmp;
	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}