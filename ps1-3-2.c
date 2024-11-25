#include <stdio.h>

void PRT(int n, char* p); //함수 원형 선언

int main() {
	char ch[100]; //변수 선언
	char long_word[100], tmp_word[100];
	int length = 0, max_length = 0;
	int max_arg = 0;

	for (char* p = ch; p < ch + 100; p++) { //입력을 위한 루프
		scanf("%c", p);
		if (*p == '#') { break; } //종료조건
		max_arg++;
	}

	for (char* p = ch; p < ch + max_arg; p++) { //입력받은 만큼만 반복
		if (*p >= 'a' && *p <= 'z') { //소문자 일 경우에만 출력
			*(tmp_word + length) = *p; //임시단어에 알파벳 저장
			length++;
			printf("%c", *p); //각 문자를 출력
		}
		else {
			if (length > 0) { //소문자이후 다른 문자가 나올경우만 줄바꿈
				printf("\n");
			}
			if (length > max_length) { //길이 값이 최대보다 클경우 갱신
				max_length = length;
				for (int i = 0; i < max_length; i++) { //최대길이 갱신시 단어 복사
					*(long_word + i) = *(tmp_word + i);
				}
			}
			length = 0; //길이값 초기화
		}
	}
	if (length > 0) { //마지막이 소문자로 끝났을 경우의 예외처리
		printf("\n");
	}
	printf("%d %c\n", max_length, *long_word); //최대 길이 출력/긴단어의 앞글자 출력
	PRT(max_length, long_word);

	return 0;
}

void PRT(int n, char* p) {
	for (char* c = p; c < p + n; c++) { //긴단어 출력
		printf("%c", *c);
	}
}