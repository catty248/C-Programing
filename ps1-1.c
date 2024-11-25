#include <stdio.h>

int* MAX(int ar[]); //�Լ� ���� ����
int* MIN(int ar[]);

int main() { 
	int N; //���� ����
	int ar[100];
	int* M, * m;

	scanf("%d", &N); //�ݺ�Ƚ�� �Է�
	for (int i = 0; i < N; i++) { //Ƚ����ŭ �ݺ�
		for (int* p = ar; p < ar + 100; p++) { //�迭�� �ּҰ��� ���� �����ڱ�
			scanf("%d", p);
			if (*p == 0) { //�ݺ� ��������
				break;
			}
		}
		M = MAX(ar); //�Լ� ȣ��
		m = MIN(ar);
		printf("%d %d\n", *M, *m); //���Ŀ� �°� ���
	}

	return 0;
}

int* MAX(int ar[]) { //�ִ밪 �Լ�
	int* maxp; //������ ������ ���� ����
	int max = 0; //���� ����
	for (int* p = ar; p < ar + 100; p++) { //�ݺ����� �迭 �ȱ�
		if (*p == 0) { break; } //��������
		if (*p > max) { //�ִ밪 ��������
			maxp = p;
			max = *p;
		}
	}

	return maxp; //�ּ� ����
}

int* MIN(int ar[]) { //�ּҰ� �Լ�
	int* minp = ar; //������ ���� ����
	int min = *ar; //���� ����
	for (int* p = ar; p < ar + 100; p++) { //�ݺ����� �迭 �ȱ�
		if (*p == 0) { break; } //��������
		if (*p < min) { //�ּҰ� ���� ����
			minp = p;
			min = *p;
		}
	}

	return minp; //�ּ� ����
}