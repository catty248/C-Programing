#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct taxi_info { //����ü ����
	char start[11]; //�����
	char target[11]; //������
	double distance; //�Ÿ�
	int t_time; //��ü�ð�
	char late_night; //�ɾ߿���
	int tot; //�����ݾ�
};

typedef struct taxi_info TAXI; //����� ���������� ����

TAXI* sel_max(TAXI* p, int N, char* s, char* d);

int main() {
	int N; //����� 
	TAXI* info; //����ü ������ ����
	char start[11], destination[11];

	scanf("%d", &N); //����� �Է�
	info = (TAXI*)malloc(N * sizeof(TAXI)); //�������ŭ�� �����Ҵ�

	for (TAXI* p = info; p < info + N; p++) { //�������ŭ �Է¹ޱ�
		scanf("%s %s %lf %d %c", p->start, p->target, &p->distance, &p->t_time, &p->late_night);
		if (p->late_night == 'N') { //�ְ� �����϶�
			if (p->distance >= 2.0) { //�߰������� �߻��� ���
				p->tot = (int)(((p->distance) - 2) * 1000 / 100) * 100 + (int)(p->t_time / 30) * 100 + 3800;
			}
			else { //�߰������� �߻����� ���� ���
				p->tot = (int)(p->t_time / 30) * 100 + 3800;
			}
		}
		else { //�ɾ� �����϶�
			if (p->distance >= 2.0) { //�߰������� �߻��� ���
				p->tot = (int)(((p->distance) - 2) * 1000 / 100) * 120 + (int)(p->t_time / 30) * 120 + 4800;
			}
			else { //�߰������� �߻����� ���� ���
				p->tot = (int)(p->t_time / 30) * 120 + 4800;
			}
		}
	}

	scanf("%s %s", start, destination); //�˻��� ���/������ ����
	TAXI* result = sel_max(info, N, start, destination); //�ִ���ã�� �Լ� ȣ���� ����� ����

	printf("%0.2f %d %c %d", result->distance, result->t_time, result->late_night, result->tot);

	free(info); //�޸� ����

	return 0;
}

//�ִ���ã�� �Լ�
TAXI* sel_max(TAXI* p, int N, char* s, char* d) {
	TAXI* max = NULL; //�ִ밪 ����

	for (TAXI* k = p;k < p +N ; k++) {
		if (strcmp(k->start, s) == 0 && strcmp(k->target, d) == 0) { //�˻����� Ȯ��
			if (max == NULL || max->tot < k->tot) { //�ִ밪���� Ȯ��
				max = k; //�ִ밪 ����
			}
		}
	}

	return max; //�ִ밪 ����ü ����
}