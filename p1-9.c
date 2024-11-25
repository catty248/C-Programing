#include <stdio.h>

void gcdlcm(int x, int y, int* a, int* b); //�Լ� ���� ����


int main() {
	int x, y; //���� ����
	int a, b;

	scanf("%d %d", &x, &y); //�Է¹޾� �ʱ�ȭ
	gcdlcm(x, y, &a, &b); //�Լ� ȣ��

	printf("%d %d", a, b); //�����͸� �̿��� ���

	return 0;
}


void gcdlcm(int x, int y, int* a, int* b) {
	int N = 0; //���� ���� ����
	if (x <= y) { //���� ���� ���ڷ� ����
		N = x;
	}
	else {
		N = y;
	}
	
	for (int i = N; i > 1; i--) { //�ִ� ����� ���ϱ�
		if (x % i == 0 && y % i == 0) {
			*a = i;
			N = i;
			break;
		}
	}

	*b = (x / N) * (y / N) * (N); //�ִ� ����� ���� ���
	//������ �����Ϳ� ������ �̵�
}