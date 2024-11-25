#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { //구조체 사용자 변수형 선언
	char name[20]; //이름
	int kor, eng, math; //성적
}student;

typedef struct { //구조체 사용자변수형 선언
	double kor, eng, math; //평균 성적
}average;

average calculate_avg(student* st, int N); //평균 연산함수

int main() {
	int N; //학생수
	int F_kor = 0, F_eng = 0, F_math = 0; //미달 학생수
	student* st; //학생구조체

	scanf("%d", &N); //학생수
	st = (student*)malloc(N * sizeof(student)); //동적 할당으로 메모리 설정

	for (student* p = st; p < st + N; p++) { //입력값 받기
		scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);
	}

	average av = calculate_avg(st, N); //평균 구조체에 연산한값 저장
	printf("%0.1f %0.1f %0.1f\n", av.kor, av.eng, av.math); //평균점수 출력

	for (student* p = st; p < st + N; p++) { //미달 학생수 구하기
		if ((double)p->kor < av.kor) { F_kor++; }
		if ((double)p->eng < av.eng) { F_eng++; }
		if ((double)p->math < av.math) { F_math++; }
	}

	printf("%d %d %d", F_kor, F_eng, F_math); //미달 학생수 출력
	free(st); //메모리 해제

	return 0;
}

//평균 연산함수
average calculate_avg(student* st, int N) {
	average av; //저장할 구조체 생성

	for (student* p = st; p < st + N; p++) { //모든 학생 정보를 바탕으로 점수 합연산
		av.kor += (double)p->kor;
		av.eng += (double)p->eng;
		av.math += (double)p->math;
	}

//학생 인원수 나누기
	av.kor /= N;
	av.eng /= N;
	av.math /= N;

	return av; //저장한 값 리턴
}