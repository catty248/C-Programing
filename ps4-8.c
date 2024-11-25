#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { //사용자 정의형 구조체 정의
	char* name;
	int firstStage;
	int interview;
	double sum;
}student;

int main() {
	int N, M; //학생수와 합격자수
	char name[11];
	student* st;

	scanf("%d %d", &N, &M); //학생수와 합격자수 입력받기
	getchar();
	st = (student*)malloc(N * sizeof(student)); //메모리ㅏ 할당
	if (st == NULL) {
		printf("Error");
		return 0;
	}

	for (student* p = st; p < st + N; p++) { //학생수만큼 반복
		scanf("%s %d %d", name, &p->firstStage, &p->interview); //성적 입력받기
		getchar();
		p->name = (char*)calloc(strlen(name) + 1, sizeof(char)); //학생 이름크기만큼 할당
		if (p->name == NULL) {
			printf("error");
			return 0;
		}
		strcpy(p->name, name); //이름 저장
		p->sum = (double)(p->firstStage * 7 + p->interview * 3) / 10; //점수 계산후 저장
	}
	
	//점수기준 내림차순
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



	//합격자수만큼 출력
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