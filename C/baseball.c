//야구게임
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setRand(int *secret)
{

	secret[0] = rand() % 9 + 1;
	while (1)
	{
		secret[1] = rand() % 10;
		if (secret[0] != secret[1])
			break;

	}
	while (1)
	{
		secret[2] = rand() % 10;
		if (secret[0] != secret[2] && secret[1] != secret[2])
			break;
	}
}


void save(int* y) {                 // 숫자 입력 함수
	int a;
	char c[256];
	while (1) {
		printf("수를 입력하세요(3자리수, 동일 숫자 중복 안됨) : ");
		scanf_s("%d", &a);               // 세자리수를 받고 각자리의 숫자를
		*y = a / 100;                // 따로 저장한다.
		*(y + 1) = a / 10 - 10 * (*y);
		*(y + 2) = a - 100 * (*y) - 10 * (*(y + 1));

		if (*y < 1 || *y > 9 || *(y + 1) < 0 || *(y + 2) < 0) {
			printf("0을 제외한 세자리수를 입력하세요!\n");
			continue;
		}
		else if ((*y == *(y + 1) || *(y + 1) == *(y + 2) || *(y + 2) == *y)) {
			printf("숫자를 중복하여 입력하였습니다.\n");
			continue;
		}
		else
			break;
	}
}

void StrikeBall(int* secret, int* save_num, int* strike, int* ball) {    // 스트라이크, 볼 계산 함수
	*strike = 0;
	*ball = 0;
	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
			if (secret[a] == save_num[b])
				if (a == b)
					(*strike)++;
				else
					(*ball)++;

}
void printsb(int strike, int ball) {            // 스트라이크, 볼 출력 함수
	if (strike == 0 && ball == 0)
		printf("out!\n");
	else printf("%d strike %d ball\n", strike, ball);
}

void main() {
	int i = 0, j = 0;
	int secret[3];     // 정답
	int save_num[3];    // 사용자 입력 기록 저장
	int strike = 0, ball = 0;     // 스트라이크 볼 개수
	int count;         // 시도 횟수
	char yn;
	srand((unsigned int)time(NULL));


	printf("====================야구 게임====================\n\n");
	while (1) {
		count = 1;           // 첫 시도 1시작
		setRand(secret);         // 난수 생성 함수
								 //  printf("%d %d %d", secret[0], secret[1], secret[2]);
		while (1) {

			save(save_num);         // 숫자 입력 함수
			StrikeBall(secret, save_num, &strike, &ball); // 스트라이크, 볼 계산 함수
			if (strike == 3) break;       // strikeBall 함수가 1을 반환하면 루프 나감
			printsb(strike, ball);       // 스트라이크, 볼 출력 함수
			count++;          // 반복문이 끝나면 시도 횟수 1증가
		}
		printf("%d번만에 성공 \n한번더? (y/n)", count);
		scanf_s(" %c", &yn);
		if (yn == 'n') break;
	}
	printf("\n\n====================게임 종료====================\n");
}
