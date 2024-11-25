#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { //구조체 사용자 변수형 선언
	char name[20]; //이름
	int kor, eng, math; //성적
	double avg;
}student;

void read_data(student* st, int N); //학생정보 입력함수
void sort_score(student* st, int N); //학생정보 정렬함수
student* select_out(student* st1, student* st2, int N); //중간등수 비교함수

int main() {
	int N; //학생수
	student* st1, *st2; //학생구조체

	scanf("%d", &N); //학생수
	st1 = (student*)malloc(N * sizeof(student)); //동적 할당으로 메모리 설정
	st2 = (student*)malloc(N * sizeof(student));

	//입력함수 호출
	read_data(st1, N);
	read_data(st2, N);
	
	//정렬함수 호출
	sort_score(st1, N);
	sort_score(st2, N);

	//중간등수 비교함수 호출후 새로운 구조체에 저장
	student *st = select_out(st1, st2, N);

	for (student* p = st; p < st + N; p++) { //결정된 정보를 출력
		printf("%s %d %d %d %0.1f\n", p->name, p->kor, p->eng, p->math, p->avg);
	}

	free(st1); //메모리 해제
	free(st2);

	return 0;
}

//학생정보 입력 함수
void read_data(student* st, int N) {
	for (student* p = st; p < st + N; p++) { //학생수만큼 입력
		scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);
		p->avg = (double)(p->kor + p->eng + p->math) / 3.0; //입력된 정보로 평균점수 계산하여 저장
	}

	return 0;
}

//학생정보 정렬함수
void sort_score(student* st, int N) {
	for (int i = 0; i < N - 1; i++) { //학생수 -1만큼 반복
		for (student* p = st; p < st + N - i - 1; p++) { //내부 구조체 반복
			if (p->avg < (p + 1)->avg) { //평균점수 기준으로 비교
				student tmp = *p; //구조체 통째로 변경
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
			if (p->avg == (p + 1)->avg && p->kor < (p+1)->kor) { //평균점수가 같다면 국어성적 비교
				student tmp = *p; //구조체 통째로 변경
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
			if (p->avg == (p + 1)->avg && p->kor == (p + 1)->kor && p->eng < (p + 1)->eng) { //평균점수와 국어성적이 같다면 영어성적 비교
				student tmp = *p; //구조체 통째로 변경
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
			if (p->avg == (p + 1)->avg && p->kor == (p + 1)->kor && p->eng == (p + 1)->eng && p->math < (p + 1)->math) { //평균,국어,영어 성적이 같다면 수학성적 비교
				student tmp = *p; //구조체 통째로 비교
				*p = *(p + 1);
				*(p + 1) = tmp;
			}
		}
	}

	return 0;
}

//중간등수 비교함수
student* select_out(student* st1, student* st2, int N) {
	int mid = N / 2; //중간등수확인

	if ((st1 + mid)->avg == (st2 + mid)->avg) { //중간등수의 평균이 같다면
		if ((st1 + mid)->kor == (st2 + mid)->kor) { //국어성적이 같다면
			if ((st1 + mid)->eng == (st2 + mid)->eng) { //영어성적이 같다면
				if ((st1 + mid)->math < (st2 + mid)->math) { //수학성정 비교하여 출력
					return st2;
				}
				return st1;
			}
			else if ((st1 + mid)->eng < (st2 + mid)->eng) { //영어성적 비교 출력
				return st2;
			} 
			return st1;
		}
		else if ((st1 + mid)->kor < (st2 + mid)->kor) { //국어성적 비교출력
			return st2;
		}
		return st1;
	}
	else if ((st1 + mid)->avg < (st2 + mid)->avg) { //평균성적 비교출력
		return st2;
	}
	return st1;
}