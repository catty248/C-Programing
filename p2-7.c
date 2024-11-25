#include <stdio.h>

int main() {
	int N; //변수 선언
	int in_N[4] = {0,};
	char st[4][4] = { "\0", "TEN", "HUN", "THO"}; //이중 배열로 문자열 저장
	char cNum[9][6] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	scanf("%d", &N); //수 입력받아 초기화
	for (int* p = in_N; p < in_N + 4; p++) { //수를 단위별로 나눠 저장
		*p = N % 10;
		N /= 10;
	}

	for (int i = 3; i >= 0; i--) { //역순으로 불러오며 작업처리
		if (in_N[i] != 0) { //0일경우 캔슬
			printf("%s %s ", cNum[in_N[i]-1], st[i]); //문제조건에 맞게 출력
		}
	}

	return 0;
}

