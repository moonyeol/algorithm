#include <stdio.h>



int main(void) {
	float n;									//�Ǽ� ���� �ޱ����� ����
	char c = 'c';
	void translat2(float num);					//������ 2������ ��ȯ ��Ű�� �Լ� ����
	void translate1(int num);					//�Ҽ��� 2������ ��ȯ ��Ű�� �Լ� ����
	while (1) {									
		printf(">>");							
		scanf("%f", &n);						//n���� �Է¹���
		if (n - (int)n == 0) {					//n�� ������� translate1��, �ƴ϶�� translate2�� ����
			translate1((int)n);
		}
		else {
			translat2(c);
		}
	}
	return 0;
}




void translate1(int num, int m) {							//10���� ������ 2�������� ǥ���ϴ� �Լ�
	int tmp = num;									// num���� tmp�� ����
	int b[32];										//2������ ������ �迭
	int i;
	printf("������ %d �� �������� ��ȯ\n", num);	
	printf("\t");

	for (i = 0; tmp != 1; i++) {				//�ݺ����� ���� tmp�� �簪�� 2������ b�� ����
		printf("%d\t.....",tmp);
		b[i] = tmp % 2;							//tmp���� 2�� ���� ������ ���� �迭�� ����
		tmp = tmp / 2;							//tmp�� tmp�� 2�� ���� ���� ����
		printf("%d\n", b[i]);
		printf("/2\t");
	}
	b[i] = tmp;									//�ݺ����� �������� tmp�� ������ִ� 1�� b�� ����
	printf("%d\t.....%d\n", b[i], b[i]);
	for (int j = i; j >= 0; j--) {				// �ݺ����� ���� b�� ���� ��Ų ���� �������� ǥ����
		printf("%d ", b[j]);
		if (j != 0 && j % 4 == 0) {				//j�� 0�� �ƴҶ��� 4�� ����϶� '/'�� ǥ����
			printf("/ ");
		}

	}

	printf("\n������ %d �� 16������ ��ȯ : %x\n", num, num);	//num���� 16������ ǥ����

}


void translat2(float num, int m) {							//�Ҽ��� ���� 2������ ǥ���ϴ� �Լ�
	int b[32];
	int i;
	
	num = num - (int)num;

	printf("1�̸��� �Ҽ�����%.6f�� �������� ��ȯ\n", num);
	printf("\t%.2f\t.... %d\n", num, (int)num);

	for (i = 0; i != 12; i++) {						//�ݺ����� ���� �Ҽ������� 2�������� ǥ��
		printf("x2 = ");
		num = num * 2;								//num�� 2�� ����
		b[i] = num;									//2�� ���� num�� 1�� �ڸ��� b�� ����
		printf("\t%.2f\t.... %d\n", num, b[i]);
		if ((int)num == 1) {						//num�� 1�� �ڸ��� 1�� ��� 1�� ���ش�
			num = num - 1;
			printf("-1 = \t%.2f\n", num);
		}
	}
	printf("0. ");

	for (int j = 0; j < i; j++) {					//�ݺ����� ���� b�� ������ num�� 2������ ǥ���Ѵ�
		printf("%d ", b[j]);
		if ((j + 1) % 4 == 0) {						//j�� 0���� �̹Ƿ� j+1�� 4�� ������ '/'�� ǥ���Ѵ�.
			printf("/ ");
		}
	}
	printf("\n");

}

