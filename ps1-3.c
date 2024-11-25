#include <stdio.h>

int main() {
	char ch[100]; //변수 선언
	int length = 0, max_length = 0;
	int max_arg = 0;

	for (char* p = ch; p < ch + 100; p++) { //입력을 위한 루프
		scanf("%c", p);
		if (*p == '#') {break;} //종료조건
		max_arg++;
	}

	for (char* p = ch; p < ch + max_arg; p++) { //입력받은 만큼만 반복
		if (*p >= 'a' && *p <= 'z') { //소문자 일 경우에만 출력
			length++;
			if (length > max_length) { //길이 값이 최대보다 클경우 갱신
				max_length = length;
			}
			printf("%c", *p); //각 문자를 출력
		}
		else {
			if (length > 0) { //소문자이후 다른 문자가 나올경우만 줄바꿈
				printf("\n");
			}
			length = 0; //길이값 초기화
		}
	}
	if (length > 0) { //마지막이 소문자로 끝났을 경우의 예외처리
		printf("\n");
	}
	printf("%d", max_length); //최대 길이 출력


	return 0;
}