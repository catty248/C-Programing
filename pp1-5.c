#include <stdio.h>

int input(int* p);					// 함수 원형 선언
int* sel_next(int* p);
int number(int* p, int* q);


int main() { //메인 함수 
	int x[100]; //변수 선언
	int M, N;
	int* p = x;
	int* j;

	j = input(x); //입력 함수 호출 , 최대배열값 저장


	for (int i = 0; ; i++) { //반복으로 모든 배열에 대한 연산을 진행
		int* q = p;
		p = sel_next(q); //합을 세기위한 함수 호출
		printf("%d", number(q, p)); //숫자 출력 함수를 호출해 출력
		printf("*\n"); //개행문자 사용으로 문제 형식에 맞게 출력
		if (*(p + 1) == -1) { //반복문의 종료조건, 마지막 배열값이 -1인것을 이용
			break;
		}
		p += 1;
	}

	return 0;
}

int input(int* p) {
	int max = 0; //배열에 입력된 수의 개수를 파악하기 위해 입력
	for (int i = 0; i < 100; i++) { //반복문 실행
		scanf("%d", p + i);
		if (*(p + i) == -1) { //종료조건
			max = i;
			break;
		}
	}

	return max; //최대 배열값 리턴
}

int* sel_next(int* p) {
	int* end = p, sum = 0;	//탐색 시작 조건 설정
	for (int* k = p; ; k++) { //배열 훝어보며 합연산
		if (*k == -1) { //배열끝 종료조건
			end = k - 1; //리턴값을 -1이전으로 설정
			return end;
		}
		sum += *k; //검산용 합에 메모리의 값을 더함
		if (sum > 10) { //합이 10이 초과된다면
			end = k - 1; //그 이전 값의 메모리를 출력
			return end;
		}
	}
	return p;

}


int number(int* p, int* q) { //숫자 만들기 함수
	int num = 0;
	for (int* k = p; k < q+1; k++) { //배열값 불러와 자리값 연산
		num *= 10;
		num += *k;
	}

	return num; //결과값 리턴
}