#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { //����ü ����� ������ ����
	char name[20]; //�̸�
	int kor, eng, math; //����
	double avg;
}student;

void read_data(student* st, int N); //�л����� �Է��Լ�
void sort_score(student* st, int N); //�л����� �����Լ�
student* select_out(student* st1, student* st2, int N); //�߰���� ���Լ�

int main() {
	int N; //�л���
	student* st1, *st2; //�л�����ü

	scanf("%d", &N); //�л���
	st1 = (student*)malloc(N * sizeof(student)); //���� �Ҵ����� �޸� ����
	st2 = (student*)malloc(N * sizeof(student));

	//�Է��Լ� ȣ��
	read_data(st1, N);
	read_data(st2, N);
	
	//�����Լ� ȣ��
	sort_score(st1, N);
	sort_score(st2, N);

	//�߰���� ���Լ� ȣ���� ���ο� ����ü�� ����
	student *st = select_out(st1, st2, N);

	for (student* p = st; p < st + N; p++) { //������ ������ ���
		printf("%s %d %d %d %0.1f\n", p->name, p->kor, p->eng, p->math, p->avg);
	}

	free(st1); //�޸� ����
	free(st2);

	return 0;
}

//�л����� �Է� �Լ�
void read_data(student* st, int N) {
	for (student* p = st; p < st + N; p++) { //�л�����ŭ �Է�
		scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);
		p->avg = (double)(p->kor + p->eng + p->math) / 3.0; //�Էµ� ������ ������� ����Ͽ� ����
	}

	return 0;
}

//�л����� �����Լ�
void sort_score(student* st, int N) {
	for (int i = 0; i < N - 1; i++) { //�л��� -1��ŭ �ݺ�
		for (student* p = st; p < st + N - i - 1; p++) { //���� ����ü �ݺ�
			if (p->avg < (p + 1)->avg) { //������� �������� ��
				student tmp = *p; //����ü ��°�� ����
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
			if (p->avg == (p + 1)->avg && p->kor < (p+1)->kor) { //��������� ���ٸ� ����� ��
				student tmp = *p; //����ü ��°�� ����
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
			if (p->avg == (p + 1)->avg && p->kor == (p + 1)->kor && p->eng < (p + 1)->eng) { //��������� ������� ���ٸ� ����� ��
				student tmp = *p; //����ü ��°�� ����
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
			if (p->avg == (p + 1)->avg && p->kor == (p + 1)->kor && p->eng == (p + 1)->eng && p->math < (p + 1)->math) { //���,����,���� ������ ���ٸ� ���м��� ��
				student tmp = *p; //����ü ��°�� ��
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
		}
	}

	return 0;
}

//�߰���� ���Լ�
student* select_out(student* st1, student* st2, int N) {
	int mid = N / 2; //�߰����Ȯ��

	if ((st1 + mid)->avg == (st2 + mid)->avg) { //�߰������ ����� ���ٸ�
		if ((st1 + mid)->kor == (st2 + mid)->kor) { //������� ���ٸ�
			if ((st1 + mid)->eng == (st2 + mid)->eng) { //������� ���ٸ�
				if ((st1 + mid)->math < (st2 + mid)->math) { //���м��� ���Ͽ� ���
					return st2;
				}
				return st1;
			}
			else if ((st1 + mid)->eng < (st2 + mid)->eng) { //����� �� ���
				return st2;
			} 
			return st1;
		}
		else if ((st1 + mid)->kor < (st2 + mid)->kor) { //����� �����
			return st2;
		}
		return st1;
	}
	else if ((st1 + mid)->avg < (st2 + mid)->avg) { //��ռ��� �����
		return st2;
	}
	return st1;
}