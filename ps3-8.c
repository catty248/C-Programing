#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { //����� ������ ����ü ����
	int car_num; //������ȣ
	int ph_num; //��ȭ��ȣ
	char type; //��ǰ ����
	char member; //����� ���� ����
	int m_type; //����� ����
	int min; //�����ð�
	double tot; //�������
} info;

void input(info* p, int N); //�Լ� ���� ����
void compute(info* p);
void display(info* p, int N);

int main() {
	info* parking; //����ü ������ ����
	int N;

	scanf("%d", &N); //������ �Է�
	parking = (info*)malloc(N * sizeof(info)); //���� �޸� �Ҵ�

	input(parking, N); //�Է��Լ� ȣ��
	for (info* p = parking; p < parking + N; p++) { //��� ������ ���� ��� ���
		compute(p);
	}
	parking_info_sort(parking, N); //�����Լ� ȣ��
	display(parking, N); //���� ���� ���

	free(parking);

	return 0;
}

//�Է��Լ�
void input(info* p, int N) {
	for (info* k = p; k < p + N; k++) {
		scanf("%d %d %c", &k->car_num, &k->ph_num, &k->type); //�⺻���� �Է�
		getchar();
		if (k->type == 'S') { //����� ���������� Ȯ��
			scanf("%c %d %d", &k->member, &k->m_type, &k->min); //�������ΰ�� �߰����� �Է�
		}
		else {
			scanf("%d", &k->min);
		}
	}
}

//��ݰ�� �Լ�
void compute(info* p) {
	if (p->type == 'S') { //��ǰ Ȯ��
		if (p->member == 'N') { //����� ���� Ȯ��
			if (p->m_type == 7) {
				p->tot = 30000.0;
			}
			else if (p->m_type == 30) {
				p->tot = 100000.0;
			}
			else {
				p->tot = 500000.0;
			}
		}
		else { //����� ����ڿ� ���� �⺻��� ������
			p->tot = 0.0;
		}
	}
	else { //���ϱ� ��� �ΰ�
		p->tot = 5000.0;
	}

	if (p->min > 240) { //�ʰ��� �ð��� ���� �߰���ݰ��
		p->tot += ((p->min - 240) / 10) * 200;
	}

}
//�����Լ�
void parking_info_sort(info* p, int N) {
	for (int i = 0; i < N - 1; i++) {
		for (info* k = p; k < p + N - 1 - i; k++) {
			if (k->type == 'S' && (k+1)->type == 'D') { //���� �������� �ٸ��� ����
				info tmp = *k;
				*k = *(k + 1);
				*(k + 1) = tmp;
			}
			if (k->type == (k+1)->type && k->car_num >(k + 1)->car_num) { //���������� ������� ������ȣ������ ����
				info tmp = *k;
				*k = *(k + 1);
				*(k + 1) = tmp;
			}
		}
	}
}

//����Լ�
void display(info* p, int N) {
	double D = 0.0, S = 0.0;
	for (info* k = p; k < p + N; k++) { //��� ������ ���� ���
		printf("%d %d %c %.0f\n", k->car_num, k->ph_num, k->type, k->tot);
		if (k->type == 'D') { //���������� ��� �ջ�
			D += k->tot;
		}
		else {
			S += k->tot;
		}
	}
	printf("%.0f %.0f %.0f", D, S, D + S); //���������� ��� ����� ���տ�� ���
}