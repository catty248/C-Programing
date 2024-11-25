#include <stdio.h>

int input(int* p);					// �Լ� ���� ����
int* sel_next(int* p);
int number(int* p, int* q);


int main() { //���� �Լ� 
	int x[100]; //���� ����
	int M, N;
	int* p = x;
	int max;

	max = input(x); //�Է� �Լ� ȣ�� , �ִ�迭�� ����


	for (int i = 0; ; i++) { //�ݺ����� ��� �迭�� ���� ������ ����
		int* q = p;
		p = sel_next(q); //���� ������ ���� �Լ� ȣ��
		if (*p == -1) { //������ �迭 Ư���� �� ��������
			if (*q == *(p - 1)) { //Ư���� ����ó��
				break;
			}
			printf("%d\n", number(q, p-1)); //���� ��� �Լ��� ȣ���� ��� ������ ����
			break;
		}
		printf("%d\n", number(q, p)); //���� ��� �Լ��� ȣ���� ���
	}

	return 0;
}

int input(int* p) {
	int max = 0; //�迭�� �Էµ� ���� ������ �ľ��ϱ� ���� �Է�
	for (int i = 0; i < 100; i++) { //�ݺ��� ����
		scanf("%d", p + i);
		if (*(p + i) == -1) { //��������
			max = i;
			break;
		}
	}

	return max; //�ִ� �迭�� ����
}

int* sel_next(int* p) {
	int* end = p;	//Ž�� ���� ���� ����
	int up = 0, down = 0;
	for (int* k = p; ; k++) { //�迭 �m��� ���� Ž��
		if (up == 1 && down == 1) { //�����ĺ��ڰ� ���� ������ ��� Ž�� ����
			break;
		}
		if (*k > *(k + 1)) { //�����Ұ��
			down = 1; //���� �ĺ��ڸ� Ȱ��ȭ
			end++;
		}
		else if (*k < *(k + 1)) { //�����Ұ��
			up = 1; //���� �ĺ��ڸ� Ȱ��ȭ
			end++;
		}
	}
	return end - 1; //������������ ��ĭ ���� �ּҸ� ����
}


int number(int* p, int* q) { //���� ����� �Լ�
	int num = 0;
	for (int* k = p; k < q + 1; k++) { //�迭�� �ҷ��� �ڸ��� ����
		num *= 10;
		num += *k;
	}

	return num; //����� ����
}