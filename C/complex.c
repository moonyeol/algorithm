//���Ҽ����
#include <stdio.h>

typedef struct num{
	float Re;
	float Im;
}Num;

Num PlusCnumber(Num *num);
Num ProductCnumber(Num *num);
void ShowCnumber(Num num);

void main() {
	Num Cnumber[2];

	printf("���Ҽ� �Է�1[�Ǽ� ���] :");
	scanf("%f %f", &Cnumber[0].Re, &Cnumber[0].Im);
	printf("���Ҽ� �Է�2[�Ǽ� ���] :");
	scanf("%f %f", &Cnumber[1].Re, &Cnumber[1].Im);

	printf("\n\n");
	ShowCnumber(PlusCnumber(Cnumber));
	ShowCnumber(ProductCnumber(Cnumber));

}

Num PlusCnumber(Num *num) {
	Num tmp;
	tmp.Re = num[0].Re + num[1].Re;
	tmp.Im = num[0].Im + num[1].Im;
	return tmp;
}
Num ProductCnumber(Num *num) {
	Num tmp;
	tmp.Im= num[0].Re * num[1].Re - num[0].Im * num[1].Im;
	tmp.Re = num[0].Re * num[1].Im + num[1].Re * num[0].Im;
	return tmp;
}
void ShowCnumber(Num num) {
	printf("%f + %fi\n", num.Im, num.Re);
}