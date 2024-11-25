#include <stdio.h>
#include <string.h>

int check(char* ch); //함수 원형 선언

int main() {
	char in_char[31]; //변수 선언

	scanf("%s", in_char); //확인할 문자 입력받아 초기화
	printf("%d %d", strlen(in_char), check(in_char)); //표준 문자열 처리 함수를 사용해 길이 출력 및 함수 호출

	return 0;
}

int check(char* ch) { 
	char rch[31]; //역으로 정렬할 변수 선언
	for (int i = 0; i < strlen(ch); i++) { //문자열의 길이를 이용해 역순 정렬
		rch[strlen(ch) - i-1] = ch[i];
	}
	rch[strlen(ch)] = '\0'; //비교를 위해 마지말 널문자 추가

	if (strcmp(ch, rch) == 0) { //비교함수 사용하여 결과값 출력
		return 1;
	}
	else {
		return 0;
	}
}