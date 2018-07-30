//��������ü�˰���

#include <stdio.h>
#define Max_Arr	7
#define Max_Frame 3

int check(int(*arr)[2], int num);							//���� �������� ���� �������������� �����ϴ� �˻�
void init(int* page,int num);								//������ ������ �� ���� 0������ num������ �ʱ�ȭ, 1������ 0�ʷ� �ʱ�ȭ
void set_zero(int* arr);									//������ ������ ������ 1����(�ð�) �� 0���� �ʱ�ȭ
int get_max(int(*arr)[2]);									//������ ������ ����� ���� ������(�ð��� ���� ����) ���� ����
void add_sec(int(*arr)[2]);									//������ ������ ����� 1����(�ð�)�� 1�ʽ� ���� 

void main() {
	int page[Max_Frame][2];									//������ ������, 0������ ��, 1���� �ð�
	int num[Max_Arr];										//����������
	int sec = 0;											//�ð�
	int count = 0;											//������ �������� �ε��� ����
	int index = 0;											//������������ �ε��� ����
	int hit = 0;											//hit�� Ƚ��

	for (int i = 0; i < Max_Arr; i++) {						//������������ ������ ����
		scanf(" %d", &num[i]);
	}
	while (1) {												//���� �ѹ��� 1�ʶ� ����
		if (sec == Max_Arr) break;							//�ð��� ������������ ũ��� �������ٸ� ���� Ż��

		if (check(page, num[index]) == -1) {				//������������ ���� ������ �����ӿ� ��ġ�� ���� ���ٸ�
			if (count < Max_Frame) {						//������ �������� �迭���� �� ä�����ٸ� ������� ä��
				init(page[count++], num[index++]);
			}
			else {											//������ ���ٸ�
				init(page[get_max(page)], num[index++]);	//���� �ð��� ������ �࿡ ������������ ���� ����(�ð��� 0���� �ʱ�ȭ)
			}
		}
		else {												//������������ ���� ������ �����ӿ� ��ġ�� ���� �ִٸ�
					set_zero(page[check(page, num[index++])]);//��ġ�� ���� ���� ���� �ð��� 0���� �ʱ�ȭ
					hit++;									//hitȽ�� ����
		}
		add_sec(page);										//������ ������ �ð� ����
		sec++;												//�ð� ����
	}
	printf("������ ���� �� : %d", sec- hit );
	
}

void add_sec(int (*arr)[2]) {
	for (int i = 0; i < Max_Frame;i++) {
		arr[i][1]++;
	}
}

int get_max(int(*arr)[2]) {
	int max = 0;
	int a;
	for (int i=0; i < Max_Frame;i++) {
		if (arr[i][1] > max) {
			max = arr[i][1];
			a = i;
		}
	}
	return a;
}

void init(int* page, int num) {
	page[0] = num;
	page[1] = 0;
}

void set_zero(int* arr) {
	arr[1] = 0;
}

int check(int(*arr)[2], int num) {
	for (int i = 0; i < Max_Frame; i++) 
		if (arr[i][0] == num)
			return i;
	return -1;							//i�� 0~Max_Frame������ ��ȯ�Ҽ� �����Ƿ� 0�̵Ǹ� ������ ��
}
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define Max_Arr 20

#define Max_Frame 3




int check(int(*arr)[2], int num); //���� �������� ���� �������������� �����ϴ� �˻�

void init(int* page, int num); //������ ������ �� ���� 0������ num������ �ʱ�ȭ, 1������ 0�ʷ� �ʱ�ȭ

void set_zero(int* arr); //������ ������ ������ 1����(�ð�) �� 0���� �ʱ�ȭ

int get_max(int(*arr)[2]); //������ ������ ����� ���� ������(�ð��� ���� ����) ���� ����

void add_sec(int(*arr)[2]); //������ ������ ����� 1����(�ð�)�� 1�ʽ� ���� 




void main() {

	int page[Max_Frame][2] = { { 0, }, }; //������ ������, 0������ ��, 1���� �ð�

	int num[Max_Arr]; //����������

	int sec = 0; //�ð�

	int count = 0; //������ �������� �ε��� ����

	int index = 0; //������������ �ε��� ����

	int hit = 0; //hit�� Ƚ��




	for (int i = 0; i < Max_Arr; i++) { //������������ ������ ����

		scanf(" %d", &num[i]);

	}

	while (1) { //���� �ѹ��� 1�ʶ� ����

		if (sec == Max_Arr) break; //�ð��� ������������ ũ��� �������ٸ� ���� Ż��

		if (count < Max_Frame) { //������ �������� �迭���� �� ä�����ٸ� ������� ä��
								 //���� 1. ���� ó�� �߰�
			if (check(page, num[index]) != -1) {
				//���� 1. + ���� ó�� �߰�
				if (num[index] == 0) {
					init(page[count++], num[index++]);

					add_sec(page);

					sec++;

					continue;
				}

				set_zero(page[check(page, num[index++])]); //��ġ�� ���� ���� ���� �ð��� 0���� �ʱ�ȭ

				hit++; //hitȽ�� ����

				add_sec(page); //������ ������ �ð� ����

				sec++; //�ð� ����

				continue;
			}

			init(page[count++], num[index++]);
		}

		else { //������ ���ٸ�

			if (check(page, num[index]) == -1) { //������������ ���� ������ �����ӿ� ��ġ�� ���� ���ٸ�

				init(page[get_max(page)], num[index++]); //���� �ð��� ������ �࿡ ������������ ���� ����(�ð��� 0���� �ʱ�ȭ)

			}

			else {//������������ ���� ������ �����ӿ� ��ġ�� ���� �ִٸ�

				set_zero(page[check(page, num[index++])]); //��ġ�� ���� ���� ���� �ð��� 0���� �ʱ�ȭ

				hit++; //hitȽ�� ����

			}

		}

		add_sec(page); //������ ������ �ð� ����

		sec++; //�ð� ����

	}

	printf("������ ���� �� : %d", sec - hit);



}




void add_sec(int(*arr)[2]) {

	for (int i = 0; i < Max_Frame; i++) {

		arr[i][1]++;

	}

}




int get_max(int(*arr)[2]) {

	int max = 0;

	int a;

	for (int i = 0; i < Max_Frame; i++) {

		if (arr[i][1] > max) {

			max = arr[i][1];

			a = i;

		}

	}

	return a;

}




void init(int* page, int num) {

	page[0] = num;

	page[1] = 0;

}




void set_zero(int* arr) {

	arr[1] = 0; //1 ���� 0 ���� ���� -> �ùٸ��� �ð����� �ʱ�ȭ �ǵ���

}




int check(int(*arr)[2], int num) {

	for (int i = 0; i < Max_Frame; i++)

		if (arr[i][0] == num)

			return i;

	return -1; //i�� 0~Max_Frame-1������ ��ȯ�Ҽ� �����Ƿ� 0�̵Ǹ� ������ ��

	*/