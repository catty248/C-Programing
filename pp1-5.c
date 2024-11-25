#include <stdio.h>

int input(int* p);					// �Լ� ���� ����
int* sel_next(int* p);
int number(int* p, int* q);


int main() { //���� �Լ� 
	int x[100]; //���� ����
	int M, N;
	int* p = x;
	int* j;

	j = input(x); //�Է� �Լ� ȣ�� , �ִ�迭�� ����


	for (int i = 0; ; i++) { //�ݺ����� ��� �迭�� ���� ������ ����
		int* q = p;
		p = sel_next(q); //���� �������� �Լ� ȣ��
		printf("%d", number(q, p)); //���� ��� �Լ��� ȣ���� ���
		printf("*\n"); //���๮�� ������� ���� ���Ŀ� �°� ���
		if (*(p + 1) == -1) { //�ݺ����� ��������, ������ �迭���� -1�ΰ��� �̿�
			break;
		}
		p += 1;
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
	int* end = p, sum = 0;	//Ž�� ���� ���� ����
	for (int* k = p; ; k++) { //�迭 �m��� �տ���
		if (*k == -1) { //�迭�� ��������
			end = k - 1; //���ϰ��� -1�������� ����
			return end;
		}
		sum += *k; //�˻�� �տ� �޸��� ���� ����
		if (sum > 10) { //���� 10�� �ʰ��ȴٸ�
			end = k - 1; //�� ���� ���� �޸𸮸� ���
			return end;
		}
	}
	return p;

}


int number(int* p, int* q) { //���� ����� �Լ�
	int num = 0;
	for (int* k = p; k < q+1; k++) { //�迭�� �ҷ��� �ڸ��� ����
		num *= 10;
		num += *k;
	}

	return num; //����� ����
}