//페이지교체알고리즘

#include <stdio.h>
#define Max_Arr	7
#define Max_Frame 3

int check(int(*arr)[2], int num);							//참조 페이지의 값이 프레임페이지에 존재하는 검사
void init(int* page,int num);								//페이지 프레임 한 행의 0번방을 num값으로 초기화, 1번방을 0초로 초기화
void set_zero(int* arr);									//페이지 프레임 한행의 1번방(시간) 을 0으로 초기화
int get_max(int(*arr)[2]);									//페이지 프레임 행들중 가장 오랜된(시간이 가장 높은) 행을 리턴
void add_sec(int(*arr)[2]);									//페이지 프레임 행들의 1번방(시간)을 1초식 증가 

void main() {
	int page[Max_Frame][2];									//페이지 프레임, 0번방은 값, 1번방 시간
	int num[Max_Arr];										//참조페이지
	int sec = 0;											//시간
	int count = 0;											//페이지 프레임의 인덱스 변수
	int index = 0;											//참조페이지의 인덱스 변수
	int hit = 0;											//hit된 횟수

	for (int i = 0; i < Max_Arr; i++) {						//참조페이지의 값들을 받음
		scanf(" %d", &num[i]);
	}
	while (1) {												//루프 한번이 1초라 가정
		if (sec == Max_Arr) break;							//시간이 참조프레임의 크기와 같아진다면 루프 탈출

		if (check(page, num[index]) == -1) {				//참조프레임의 값이 페이지 프레임에 겹치는 값이 없다면
			if (count < Max_Frame) {						//페이지 프레임의 배열들이 덜 채워졌다면 빈행들을 채움
				init(page[count++], num[index++]);
			}
			else {											//빈행이 없다면
				init(page[get_max(page)], num[index++]);	//가장 시간이 오래된 행에 참조프레임의 값을 넣음(시간도 0으로 초기화)
			}
		}
		else {												//참조프레임의 값이 페이지 프레임에 겹치는 값이 있다면
					set_zero(page[check(page, num[index++])]);//겹치는 값을 가진 행의 시간만 0으로 초기화
					hit++;									//hit횟수 증가
		}
		add_sec(page);										//페이지 프레임 시간 증가
		sec++;												//시간 증가
	}
	printf("페이지 부재 수 : %d", sec- hit );
	
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
	return -1;							//i가 0~Max_Frame까지를 반환할수 있으므로 0이되면 문제가 됨
}
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define Max_Arr 20

#define Max_Frame 3




int check(int(*arr)[2], int num); //참조 페이지의 값이 프레임페이지에 존재하는 검사

void init(int* page, int num); //페이지 프레임 한 행의 0번방을 num값으로 초기화, 1번방을 0초로 초기화

void set_zero(int* arr); //페이지 프레임 한행의 1번방(시간) 을 0으로 초기화

int get_max(int(*arr)[2]); //페이지 프레임 행들중 가장 오랜된(시간이 가장 높은) 행을 리턴

void add_sec(int(*arr)[2]); //페이지 프레임 행들의 1번방(시간)을 1초식 증가 




void main() {

	int page[Max_Frame][2] = { { 0, }, }; //페이지 프레임, 0번방은 값, 1번방 시간

	int num[Max_Arr]; //참조페이지

	int sec = 0; //시간

	int count = 0; //페이지 프레임의 인덱스 변수

	int index = 0; //참조페이지의 인덱스 변수

	int hit = 0; //hit된 횟수




	for (int i = 0; i < Max_Arr; i++) { //참조페이지의 값들을 받음

		scanf(" %d", &num[i]);

	}

	while (1) { //루프 한번이 1초라 가정

		if (sec == Max_Arr) break; //시간이 참조프레임의 크기와 같아진다면 루프 탈출

		if (count < Max_Frame) { //페이지 프레임의 배열들이 덜 채워졌다면 빈행들을 채움
								 //문제 1. 예외 처리 추가
			if (check(page, num[index]) != -1) {
				//문제 1. + 예외 처리 추가
				if (num[index] == 0) {
					init(page[count++], num[index++]);

					add_sec(page);

					sec++;

					continue;
				}

				set_zero(page[check(page, num[index++])]); //겹치는 값을 가진 행의 시간만 0으로 초기화

				hit++; //hit횟수 증가

				add_sec(page); //페이지 프레임 시간 증가

				sec++; //시간 증가

				continue;
			}

			init(page[count++], num[index++]);
		}

		else { //빈행이 없다면

			if (check(page, num[index]) == -1) { //참조프레임의 값이 페이지 프레임에 겹치는 값이 없다면

				init(page[get_max(page)], num[index++]); //가장 시간이 오래된 행에 참조프레임의 값을 넣음(시간도 0으로 초기화)

			}

			else {//참조프레임의 값이 페이지 프레임에 겹치는 값이 있다면

				set_zero(page[check(page, num[index++])]); //겹치는 값을 가진 행의 시간만 0으로 초기화

				hit++; //hit횟수 증가

			}

		}

		add_sec(page); //페이지 프레임 시간 증가

		sec++; //시간 증가

	}

	printf("페이지 부재 수 : %d", sec - hit);



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

	arr[1] = 0; //1 에서 0 으로 수정 -> 올바르게 시간값이 초기화 되도록

}




int check(int(*arr)[2], int num) {

	for (int i = 0; i < Max_Frame; i++)

		if (arr[i][0] == num)

			return i;

	return -1; //i가 0~Max_Frame-1까지를 반환할수 있으므로 0이되면 문제가 됨

	*/