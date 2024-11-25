#include <stdio.h>
#include <stdlib.h>

struct taxi_info { //����ü ����
	char start[11]; //�����
	char target[11]; //������
	double distance; //�Ÿ�
	int t_time; //��ü�ð�
	char late_night; //�ɾ߿���
	int tot; //�����ݾ�
};

typedef struct taxi_info TAXI; //����� ���������� ����

int main() {
	int N; //����� 
	TAXI *info; //����ü ������ ����

	scanf("%d", &N); //����� �Է�
	info = (TAXI*)malloc(N * sizeof(TAXI)); //�������ŭ�� �����Ҵ�

	for (TAXI* p = info; p < info + N; p++) { //�������ŭ �Է¹ޱ�
		scanf("%s %s %lf %d %c", p->start, p->target, &p->distance, &p->t_time, &p->late_night);
		if (p->late_night == 'N') { //�ְ� �����϶�
			if (p->distance >= 2.0) { //�߰������� �߻��� ���
				p->tot = (int)(((p->distance) - 2) * 1000/100)*100 + (int)(p->t_time / 30) * 100 + 3800;
			}
			else { //�߰������� �߻����� ���� ���
				p->tot = (int)(p->t_time / 30) * 100 + 3800;
			}
		}
		else { //�ɾ� �����϶�
			if (p->distance >= 2.0) { //�߰������� �߻��� ���
				p->tot = (int)(((p->distance) - 2) * 1000/100)*120 + (int)(p->t_time / 30) * 120 + 4800;
			}
			else { //�߰������� �߻����� ���� ���
				p->tot = (int)(p->t_time / 30) * 120 + 4800;
			}
		}
	}

	for (TAXI* p = info; p < info + N; p++) { //��� ������ ���� ���
		printf("%s %s %d\n", p->start, p->target, p->tot);
	}
	free(info); //�޸� ����

	return 0;
}