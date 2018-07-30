//�߱�����
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


void save(int* y) {                 // ���� �Է� �Լ�
	int a;
	char c[256];
	while (1) {
		printf("���� �Է��ϼ���(3�ڸ���, ���� ���� �ߺ� �ȵ�) : ");
		scanf_s("%d", &a);               // ���ڸ����� �ް� ���ڸ��� ���ڸ�
		*y = a / 100;                // ���� �����Ѵ�.
		*(y + 1) = a / 10 - 10 * (*y);
		*(y + 2) = a - 100 * (*y) - 10 * (*(y + 1));

		if (*y < 1 || *y > 9 || *(y + 1) < 0 || *(y + 2) < 0) {
			printf("0�� ������ ���ڸ����� �Է��ϼ���!\n");
			continue;
		}
		else if ((*y == *(y + 1) || *(y + 1) == *(y + 2) || *(y + 2) == *y)) {
			printf("���ڸ� �ߺ��Ͽ� �Է��Ͽ����ϴ�.\n");
			continue;
		}
		else
			break;
	}
}

void StrikeBall(int* secret, int* save_num, int* strike, int* ball) {    // ��Ʈ����ũ, �� ��� �Լ�
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
void printsb(int strike, int ball) {            // ��Ʈ����ũ, �� ��� �Լ�
	if (strike == 0 && ball == 0)
		printf("out!\n");
	else printf("%d strike %d ball\n", strike, ball);
}

void main() {
	int i = 0, j = 0;
	int secret[3];     // ����
	int save_num[3];    // ����� �Է� ��� ����
	int strike = 0, ball = 0;     // ��Ʈ����ũ �� ����
	int count;         // �õ� Ƚ��
	char yn;
	srand((unsigned int)time(NULL));


	printf("====================�߱� ����====================\n\n");
	while (1) {
		count = 1;           // ù �õ� 1����
		setRand(secret);         // ���� ���� �Լ�
								 //  printf("%d %d %d", secret[0], secret[1], secret[2]);
		while (1) {

			save(save_num);         // ���� �Է� �Լ�
			StrikeBall(secret, save_num, &strike, &ball); // ��Ʈ����ũ, �� ��� �Լ�
			if (strike == 3) break;       // strikeBall �Լ��� 1�� ��ȯ�ϸ� ���� ����
			printsb(strike, ball);       // ��Ʈ����ũ, �� ��� �Լ�
			count++;          // �ݺ����� ������ �õ� Ƚ�� 1����
		}
		printf("%d������ ���� \n�ѹ���? (y/n)", count);
		scanf_s(" %c", &yn);
		if (yn == 'n') break;
	}
	printf("\n\n====================���� ����====================\n");
}
