#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { //����� ������ ����ü ����
	char* name;
	int firstStage;
	int interview;
	double sum;
}student;

int main() {
	int N, M; //�л����� �հ��ڼ�
	char name[11];
	student* st;

	scanf("%d %d", &N, &M); //�л����� �հ��ڼ� �Է¹ޱ�
	getchar();
	st = (student*)malloc(N * sizeof(student)); //�޸𸮤� �Ҵ�
	if (st == NULL) {
		printf("Error");
		return 0;
	}

	for (student* p = st; p < st + N; p++) { //�л�����ŭ �ݺ�
		scanf("%s %d %d", name, &p->firstStage, &p->interview); //���� �Է¹ޱ�
		getchar();
		p->name = (char*)calloc(strlen(name) + 1, sizeof(char)); //�л� �̸�ũ�⸸ŭ �Ҵ�
		if (p->name == NULL) {
			printf("error");
			return 0;
		}
		strcpy(p->name, name); //�̸� ����
		p->sum = (double)(p->firstStage * 7 + p->interview * 3) / 10; //���� ����� ����
	}
	
	//�������� ��������
	for (int i = 0; i < N; i++) {
		for (student* p = st; p < st + N - i - 1; p++) {
			if (p->sum < (p + 1)->sum) {
				student tmp = *p;
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
			else if (p->sum == (p + 1)->sum && p->firstStage < (p + 1)->firstStage) {
				student tmp = *p;
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
			else if (p->sum == (p + 1)->sum && p->firstStage == (p + 1)->firstStage && strcmp(p->name, (p + 1)->name) > 0) {
				student tmp = *p;
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
		}
	}



	//�հ��ڼ���ŭ ���
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (st[i].sum >= st[M-1].sum || (st[i].sum >= st[M - 1].sum && st[i].firstStage == st[M-1].firstStage)) {
			printf("%s %d %d %.1lf\n", st[i].name, st[i].firstStage, st[i].interview, st[i].sum);
			count++;
		}
	}
	printf("%d", count);



	for (student* p = st; p < st + N; p++) {
		free(p->name);
	}
	free(st);

	return 0;
}