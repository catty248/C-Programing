#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { //����� ���������� ����ü ����
	char* studentName;
	char id[5];
	char* subjectName;
	double subjectScore;
} student;

int main() {
	int N; //�л���
	int rank; //�˻��� ����
	char name[101], sub_name[101]; //�ӽ� �̸����� , �ӽ� �����̸� ����
	student* st; //����ü ������

	scanf("%d", &N); //�л��� �Է�
	st = (student*)malloc(N * sizeof(student)); //�л�����ŭ �޸� �Ҵ�
	if (st == NULL) {
		printf("error");
		return 0;
	}

	for (student* p = st; p < st + N; p++) {
		scanf("%s %s %s %lf", name, p->id, sub_name, &p->subjectScore); //�ӽú����� �Է°� �ޱ�
		p->studentName = (char*)calloc(strlen(name) + 1, sizeof(char)); //�ӽú��� ũ�⿡ ���� ����ü �޸� �Ҵ�
		if (p->studentName == NULL) {
			printf("error");
			return 0;
		}
		p->subjectName = (char*)calloc(strlen(sub_name) + 1, sizeof(char));
		if (p->subjectName == NULL) {
			printf("error");
			return 0;
		}
		strcpy(p->studentName, name); //�ӽú����� ����ü�� ����
		strcpy(p->subjectName, sub_name);
	}

	//�������� ��������
	for (int i = 0; i < N - 1; i++) {
		for (student* p = st; p < st + N - i - 1; p++) {
			if (p->subjectScore < (p + 1)->subjectScore) {
				student tmp = *p;
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
		}
	}

	scanf("%d", &rank); //�˻��� ���� �Է�


	printf("%s %s %s %.2lf", st[rank-1].studentName, st[rank-1].id, st[rank-1].subjectName, st[rank-1].subjectScore);


	for (student* p = st; p < st + N; p++) { //�޸� ����
		free(p->studentName);
		free(p->subjectName);
	}
	free(st);

	return 0;
}