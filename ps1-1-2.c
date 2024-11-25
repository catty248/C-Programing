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
		if (M == m || M + 1 == m || m + 1 == M) {
			printf("none\n");
			continue;
		}
		if (M < m) { //�ִ��ּ��� �迭�� ���İ��� �ľ�
			for (int* p = M + 1; p < m; p++) { //ȣ�� ����� ���� �ּҸ� �������� �ݺ�
				printf("%d ", *p); //�����Ѵٸ� �������Ĵ�� ���
			}
			printf("\n"); //���ĸ��߱�� �ٹٲ�
		}
		else {
			for (int* p = m + 1; p < M; p++) { //ȣ�� ����� ���� �ּҸ� �������� �ݺ�
				printf("%d ", *p); //�����Ѵٸ� �������Ĵ�� ���
			}
			printf("\n"); //���ĸ��߱�� �ٹٲ�
		}
	}
}


int* MAX(int ar[]) { //�ִ밪 �Լ�
	int* maxp = ar; //������ ������ ���� ����
	int max = *ar; //���� ����
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