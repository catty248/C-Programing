#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct subject {
	char* name; //�����̸�
	double score;
};

typedef struct { //����� ���������� ����ü ����
	char* studentName;
	char id[5];
	int numSubject;
	struct subject* psub;
	double avg;
} student;

int main() {
	int N; //�л���
	int rank; //�˻��� ����
	char name[101], sub_name[101], tmp[101]; //�ӽ� �̸����� , �ӽ� �����̸� ����
	student* st; //����ü ������

	scanf("%d", &N); //�л��� �Է�
	getchar();
	st = (student*)malloc(N * sizeof(student)); //�л�����ŭ �޸� �Ҵ�
	if (st == NULL) {
		printf("error");
		return 0;
	}

	//�л����� �Է�
	for (student* p = st; p < st + N; p++) { 
		int index = 0, count = 0, dex = 0; //���ڿ� ����Ȯ�� ����, ����/���� Ȯ�κ���, ���� �ܾ��
		char ntmp[101]; //�ӽ� ���� ����
		
		gets(tmp); //���� ���ڿ� �Է�
		//�л� �̸� ����
		for (int i = 0; ; i++) {
			if (tmp[i] == ' ') {
				ntmp[i] = '\0';
				p->studentName = (char*)calloc(strlen(ntmp) + 1, sizeof(char));
				if (p->studentName == NULL) {
					printf("error");
					return 0;
				}
				strcpy(p->studentName, ntmp);
				index = i;
				break;
			}
			else {
				ntmp[i] = tmp[i];
			}
		}
		//�л� id����
		for (int i = index + 1; i < index + 5; i++) {
			p->id[count++] = tmp[i];
		}
		index += 5; //�������� �������� ���� �ܰ� ����

		count = 0; //Ȯ�� ���� �ʱ�ȭ
		p->psub = (struct subject*)malloc(1*sizeof(struct subject)); //���񺯼� �Ҵ�
		for (int i = index; i < strlen(tmp)+1; i++) { //���� ���� �б�
			if ((tmp[i] == ' ' || tmp[i] == '\0') && dex > 0) {
				if (count % 2 == 0) { //������ �߰��ɰ��
					ntmp[dex] = '\0';
					p->psub = (struct subject*)realloc(p->psub, (count / 2 + 1) * sizeof(struct subject)); //�޸� �߰��Ҵ�
					if (p->psub == NULL) { printf("error");  return 0; }
					p->psub[(count / 2)].name = (char*)calloc(strlen(ntmp) + 1, sizeof(char)); //���� �̸��޸� �Ҵ�
					if (p->psub[count / 2].name == NULL) {
						printf("Error");
						return 0;
					}
					strcpy(p->psub[(count / 2)].name, ntmp); //���� �̸��� ����
				}
				else { //�����ϰ��
					ntmp[dex] = '\0';
					p->psub[count / 2].score = atof(ntmp); //���� �������ڸ� �Ǽ��� �ٲ�����
				}
				count++; //Ȯ�κ��� ����
				dex = 0;
			}
			else {
				ntmp[dex++] = tmp[i]; //���� �ܾ�� �����
			}
		}
		//������ ���� �Ǻ��� ��ճ���
		p->numSubject = count / 2; //Ȯ�κ����� ����ī����
		double total = 0;
		for (struct subject* q = p->psub; q < p->psub + p->numSubject; q++) {
			total += q->score;
		}
		p->avg = total / p->numSubject;

		//����� ������� �������� ����
		for (int i = 0; i < p->numSubject - 1; i++) {
			for (struct subject* q = p->psub; q < p->psub + p->numSubject - i - 1; q++) {
				if (q->score < (q + 1)->score) {
					struct subject stmp = *q;
					*q = *(q + 1);
					*(q + 1) = stmp;
				}
			}
		}
	}
	


	//�������� �������� ����
	for (int i = 0; i < N - 1; i++) {
		for (student* p = st; p < st + N - i - 1; p++) {
			if (p->avg < (p + 1)->avg) {
				student tmp = *p;
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
			if (p->avg == (p + 1)->avg && strcmp(p->id, (p+1)->id)>0) {
				student tmp = *p;
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
		}
	}

	scanf("%d", &rank); //�˻��� ���� �Է�


	printf("%s %s %.2lf %s %.2lf", st[rank - 1].studentName, st[rank - 1].id, st[rank - 1].avg, st[rank - 1].psub[0].name, st[rank-1].psub[0].score);


	for (student* p = st; p < st + N; p++) { //�޸� ����
		free(p->studentName);
		for (struct subject* q = p->psub; q < p->psub + p->numSubject; q++) {
			free(q->name);
		}
		free(p->psub);
	}
	free(st);

	return 0;
}