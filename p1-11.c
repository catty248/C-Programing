#include <stdio.h>

void addArray(int* a, int* b, int* c, int N); //함수 원형 선언

int main() {
	int N; //변수 선언
	int a[20], b[20], c[20]; //배열 변수 선언

	scanf("%d", &N); //입력받을 숫자의 개수 초기화
	for (int* p = a; p < a + N; p++) { //1번째 배열 초기화
		scanf("%d", p);
	}
	for (int* p = b; p < b + N; p++) { //2번@쨰 배열 초기화
		scanf("%d", p);
	}

	addArray(&a, &b, &c, N); //함수 호출

	for (int i = 0; i < N; i++) { //반복 출력
		printf(" %d", *(c + i));
	}

	return 0;
}

void addArray(int* a, int* b, int* c, int N) { //반복문을 이용하여 역방향 더하기 실행
	for (int i = 0; i < N; i++) {
		*(c + i) = *(a+i) + *(b + N - i - 1);
	}
}