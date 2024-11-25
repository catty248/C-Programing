#include <stdio.h>

int input(int* p);					// 함수 원형 선언
int* sel_next(int* p);
int number(int* p, int* q);


int main() { //메인 함수 
	int x[100]; //변수 선언
	int M, N;
	int* p = x;
	int max;

	max = input(x); //입력 함수 호출 , 최대배열값 저장


	for (int i = 0; ; i++) { //반복으로 모든 배열에 대한 연산을 진행
		int* q = p;
		p = sel_next(q); //증감 구간을 위한 함수 호출
		if (*p == -1) { //마지막 배열 특수값 및 종료조건
			if (*q == *(p - 1)) { //특수값 예외처리
				break;
			}
			printf("%d\n", number(q, p-1)); //숫자 출력 함수를 호출해 출력 끝항은 제외
			break;
		}
		printf("%d\n", number(q, p)); //숫자 출력 함수를 호출해 출력
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
	int* end = p;	//탐색 시작 조건 설정
	int up = 0, down = 0;
	for (int* k = p; ; k++) { //배열 훝어보며 조건 탐색
		if (up == 1 && down == 1) { //증감식별자가 동시 감지된 경우 탐색 종료
			break;
		}
		if (*k > *(k + 1)) { //감소할경우
			down = 1; //감소 식별자를 활성화
			end++;
		}
		else if (*k < *(k + 1)) { //증가할경우
			up = 1; //증가 식별자를 활성화
			end++;
		}
	}
	return end - 1; //증감지점에서 한칸 앞의 주소를 리턴
}


int number(int* p, int* q) { //숫자 만들기 함수
	int num = 0;
	for (int* k = p; k < q + 1; k++) { //배열값 불러와 자리값 연산
		num *= 10;
		num += *k;
	}

	return num; //결과값 리턴
}