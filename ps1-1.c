#include <stdio.h>

int* MAX(int ar[]); //함수 원형 선언
int* MIN(int ar[]);

int main() { 
	int N; //변수 선언
	int ar[100];
	int* M, * m;

	scanf("%d", &N); //반복횟수 입력
	for (int i = 0; i < N; i++) { //횟수만큼 반복
		for (int* p = ar; p < ar + 100; p++) { //배열에 주소값에 직접 때려박기
			scanf("%d", p);
			if (*p == 0) { //반복 종료조건
				break;
			}
		}
		M = MAX(ar); //함수 호출
		m = MIN(ar);
		printf("%d %d\n", *M, *m); //형식에 맞게 출력
	}

	return 0;
}

int* MAX(int ar[]) { //최대값 함수
	int* maxp; //리턴할 포인터 변수 선언
	int max = 0; //변수 선언
	for (int* p = ar; p < ar + 100; p++) { //반복으로 배열 훑기
		if (*p == 0) { break; } //종료조건
		if (*p > max) { //최대값 갱신조건
			maxp = p;
			max = *p;
		}
	}

	return maxp; //주소 리턴
}

int* MIN(int ar[]) { //최소값 함수
	int* minp = ar; //포인터 변수 선언
	int min = *ar; //변수 선언
	for (int* p = ar; p < ar + 100; p++) { //반복으로 배열 훑기
		if (*p == 0) { break; } //종료조건
		if (*p < min) { //최소값 갱신 조건
			minp = p;
			min = *p;
		}
	}

	return minp; //주소 리턴
}