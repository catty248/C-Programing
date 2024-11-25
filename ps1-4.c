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

	printf("%d %d\n", len_n, len_m); //������� �� ���� ���
	bubble_sort(n, len_n), bubble_sort(m, len_m); //�ִ� ������ �ּ� ������ ���ϱ� ���� 
												  //���� �Լ� ȣ��

	if (*(n + len_n - 1) > *(m + len_m - 1)) { //���ĵ� �Ŀ� �� �� �Ͽ� �ִ� ���� ���
		printf("%d", *(n + len_n - 1));
	}
	else {printf("%d", *(m + len_m - 1));}

	if (*(n) > *(m)) { printf("%d ", *m); } //���ĵ� �Ŀ� �� ���Ͽ� �ּ� ���� ���
	else { printf("%d", *n); }

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