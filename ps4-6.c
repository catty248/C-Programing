#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { //사용자 변수형으로 구조체 정의
	char* studentName;
	char id[5];
	char* subjectName;
	double subjectScore;
} student;

int main() {
	int N; //학생수
	int rank; //검색할 순위
	char name[101], sub_name[101]; //임시 이름변수 , 임시 과목이름 변수
	student* st; //구조체 포인터

	scanf("%d", &N); //학생수 입력
	st = (student*)malloc(N * sizeof(student)); //학생수만큼 메모리 할당
	if (st == NULL) {
		printf("error");
		return 0;
	}

	for (student* p = st; p < st + N; p++) {
		scanf("%s %s %s %lf", name, p->id, sub_name, &p->subjectScore); //임시변수에 입력값 받기
		p->studentName = (char*)calloc(strlen(name) + 1, sizeof(char)); //임시변수 크기에 따라 구조체 메모리 할당
		if (p->studentName == NULL) {
			printf("error");
			return 0;
		}
		p->subjectName = (char*)calloc(strlen(sub_name) + 1, sizeof(char));
		if (p->subjectName == NULL) {
			printf("error");
			return 0;
		}
		strcpy(p->studentName, name); //임시변수값 구조체에 저장
		strcpy(p->subjectName, sub_name);
	}

	//점수별로 버블정렬
	for (int i = 0; i < N - 1; i++) {
		for (student* p = st; p < st + N - i - 1; p++) {
			if (p->subjectScore < (p + 1)->subjectScore) {
				student tmp = *p;
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
		}
	}

	scanf("%d", &rank); //검색한 순위 입력


	printf("%s %s %s %.2lf", st[rank-1].studentName, st[rank-1].id, st[rank-1].subjectName, st[rank-1].subjectScore);


	for (student* p = st; p < st + N; p++) { //메모리 해제
		free(p->studentName);
		free(p->subjectName);
	}
	free(st);

	return 0;
}