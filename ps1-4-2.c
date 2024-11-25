#include <stdio.h>

void bubble_sort(int* p, int len); //�Լ� ���� ����

int main() {
	int n[11], m[11]; //���� ����
	int len_n = 0, len_m = 0; //���� ����

	for (int* p = n; p < n + 11; p++) { //101ȣ ������ ������ ����� �Է�
		scanf("%d", p);
		if (*p == -1) { break; }
		len_n++;
	}

	for (int* p = m; p < m + 11; p++) { //102ȣ ������ ������ ����� �Է�
		scanf("%d", p);
		if (*p == -1) { break; }
		len_m++;
	}

	bubble_sort(n, len_n), bubble_sort(m, len_m); //�ִ� ������ �ּ� ������ ���ϱ� ���� 
	//���� �Լ� ȣ��

	int cn = 0, cm = 0; //������ �ʱ�ȭ
	for (int i = 0; i < len_n; i++) { //�л�����ŭ �ݺ�
		if (*(n + len_n-1  - cn) > *(m + len_m-1 - cm)) { //ū������ ��
			printf("%d ", *(n + len_n-1  - cn)); //��µȰ��� ������ ��ȭ
			cn++;
		}
		else {
			printf("%d ", *(m + len_m-1  - cm)); //��µ� ���� ������ ��ȭ
			cm++;
		}
	}
	printf("\n"); //1ȸ�� ���� ������ �ٹٲ�

	cn = 0, cm = 0; //������ �ʱ�ȭ
	for (int i = 0; i < len_m; i++) { //�л�����ŭ �ݺ�
		if (*(n + cn) < *(m+ cm)) { //���������� ��
			printf("%d ", *(n  + cn)); //��µȰ��� ������ ��ȭ
			cn++;
		}
		else {
			printf("%d ", *(m  + cm)); //��µ� ���� ������ ��ȭ
			cm++;
		}
	}

	return 0;

}

void bubble_sort(int* p, int len) { //�������� �Լ�
	for (int i = 0; i < len - 1; i++) {
		for (int* k = p; k < p + len - i - 1; k++) {
			if (*k > *(k + 1)) {
				int tmp = *k;
				*k = *(k + 1);
				*(k + 1) = tmp;
			}
		}
	}
}