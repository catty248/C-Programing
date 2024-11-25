#include <stdio.h>

void addArray(int* a, int* b, int* c, int N); //�Լ� ���� ����

int main() {
	int N; //���� ����
	int a[20], b[20], c[20]; //�迭 ���� ����

	scanf("%d", &N); //�Է¹��� ������ ���� �ʱ�ȭ
	for (int* p = a; p < a + N; p++) { //1��° �迭 �ʱ�ȭ
		scanf("%d", p);
	}
	for (int* p = b; p < b + N; p++) { //2��@�� �迭 �ʱ�ȭ
		scanf("%d", p);
	}

	addArray(&a, &b, &c, N); //�Լ� ȣ��

	for (int i = 0; i < N; i++) { //�ݺ� ���
		printf(" %d", *(c + i));
	}

	return 0;
}

void addArray(int* a, int* b, int* c, int N) { //�ݺ����� �̿��Ͽ� ������ ���ϱ� ����
	for (int i = 0; i < N; i++) {
		*(c + i) = *(a+i) + *(b + N - i - 1);
	}
}