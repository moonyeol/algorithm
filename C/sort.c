//ũ�Ⱑ 10�� ������ �迭�� �����ϰ�, 10���� ������ �Է¹޾� ���� ������ ���ʴ�� ����� �� ��. 
//��������

#include <stdio.h>


void main() {
	int n[10];
	void sort(int* arr);
	void swap(int* n1, int* n2);

	printf("�� 10���� �Է��Ͻÿ�\n");

	for (int i = 0; i < 10; i++)
		scanf("%d", &n[i]);

	sort(n);

	for (int i = 0; i < 10; i++)
		printf("%d ", n[i]);
}

void sort(int* arr) {

	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (arr[i] > arr[j]) {    //tmp�� ����� ���� n[j]���� ũ�ٸ� 
				swap(&arr[i], &arr[j]);     //k��°�� i��° ���� �ٲ���
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