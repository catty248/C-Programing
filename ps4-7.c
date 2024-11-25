#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct subject {
	char* name; //과목이름
	double score;
};

typedef struct { //사용자 변수형으로 구조체 정의
	char* studentName;
	char id[5];
	int numSubject;
	struct subject* psub;
	double avg;
} student;

int main() {
	int N; //학생수
	int rank; //검색할 순위
	char name[101], sub_name[101], tmp[101]; //임시 이름변수 , 임시 과목이름 변수
	student* st; //구조체 포인터

	scanf("%d", &N); //학생수 입력
	getchar();
	st = (student*)malloc(N * sizeof(student)); //학생수만큼 메모리 할당
	if (st == NULL) {
		printf("error");
		return 0;
	}

	//학생정보 입력
	for (student* p = st; p < st + N; p++) { 
		int index = 0, count = 0, dex = 0; //문자열 순서확인 변수, 과목/점수 확인변수, 단위 단어변수
		char ntmp[101]; //임시 저장 변수
		
		gets(tmp); //정보 문자열 입력
		//학생 이름 저장
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
		//학생 id저장
		for (int i = index + 1; i < index + 5; i++) {
			p->id[count++] = tmp[i];
		}
		index += 5; //순서변수 조정으로 다음 단계 진행

		count = 0; //확인 변수 초기화
		p->psub = (struct subject*)malloc(1*sizeof(struct subject)); //과목변수 할당
		for (int i = index; i < strlen(tmp)+1; i++) { //과목 정보 읽기
			if ((tmp[i] == ' ' || tmp[i] == '\0') && dex > 0) {
				if (count % 2 == 0) { //과목이 추가될경우
					ntmp[dex] = '\0';
					p->psub = (struct subject*)realloc(p->psub, (count / 2 + 1) * sizeof(struct subject)); //메모리 추가할당
					if (p->psub == NULL) { printf("error");  return 0; }
					p->psub[(count / 2)].name = (char*)calloc(strlen(ntmp) + 1, sizeof(char)); //과목 이름메모리 할당
					if (p->psub[count / 2].name == NULL) {
						printf("Error");
						return 0;
					}
					strcpy(p->psub[(count / 2)].name, ntmp); //과목 이름을 저장
				}
				else { //점수일경우
					ntmp[dex] = '\0';
					p->psub[count / 2].score = atof(ntmp); //과목 점수문자를 실수로 바꿔저장
				}
				count++; //확인변수 증가
				dex = 0;
			}
			else {
				ntmp[dex++] = tmp[i]; //단위 단어로 만들기
			}
		}
		//과목의 개수 판별후 평균내기
		p->numSubject = count / 2; //확인변수로 과목카운팅
		double total = 0;
		for (struct subject* q = p->psub; q < p->psub + p->numSubject; q++) {
			total += q->score;
		}
		p->avg = total / p->numSubject;

		//저장된 과목들의 내림차순 정렬
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
	


	//점수별로 내림차순 정렬
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

	scanf("%d", &rank); //검색할 순위 입력


	printf("%s %s %.2lf %s %.2lf", st[rank - 1].studentName, st[rank - 1].id, st[rank - 1].avg, st[rank - 1].psub[0].name, st[rank-1].psub[0].score);


	for (student* p = st; p < st + N; p++) { //메모리 해제
		free(p->studentName);
		for (struct subject* q = p->psub; q < p->psub + p->numSubject; q++) {
			free(q->name);
		}
		free(p->psub);
	}
	free(st);

	return 0;
}