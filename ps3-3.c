#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { //����ü ����� ������ ����
	char name[20]; //�̸�
	int kor, eng, math; //����
}student;

typedef struct { //����ü ����ں����� ����
	double kor, eng, math; //��� ����
}average;

average calculate_avg(student* st, int N); //��� �����Լ�

int main() {
	int N; //�л���
	int F_kor = 0, F_eng = 0, F_math = 0; //�̴� �л���
	student* st; //�л�����ü

	scanf("%d", &N); //�л���
	st = (student*)malloc(N * sizeof(student)); //���� �Ҵ����� �޸� ����

	for (student* p = st; p < st + N; p++) { //�Է°� �ޱ�
		scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);
	}

	average av = calculate_avg(st, N); //��� ����ü�� �����Ѱ� ����
	printf("%0.1f %0.1f %0.1f\n", av.kor, av.eng, av.math); //������� ���

	for (student* p = st; p < st + N; p++) { //�̴� �л��� ���ϱ�
		if ((double)p->kor < av.kor) { F_kor++; }
		if ((double)p->eng < av.eng) { F_eng++; }
		if ((double)p->math < av.math) { F_math++; }
	}

	printf("%d %d %d", F_kor, F_eng, F_math); //�̴� �л��� ���
	free(st); //�޸� ����

	return 0;
}

//��� �����Լ�
average calculate_avg(student* st, int N) {
	average av; //������ ����ü ����

	for (student* p = st; p < st + N; p++) { //��� �л� ������ �������� ���� �տ���
		av.kor += (double)p->kor;
		av.eng += (double)p->eng;
		av.math += (double)p->math;
	}

//�л� �ο��� ������
	av.kor /= N;
	av.eng /= N;
	av.math /= N;

	return av; //������ �� ����
}