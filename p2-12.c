#include <stdio.h>
#include <string.h>

int CheckCount(char* st1, char* st3); //함수 원형선언

int main() {
	char str1[101], str3[101]; //변수 선언

	scanf("%[^\n]%*c", str1); //문자열 초기화 
	scanf("%s", str3); //%[^\n]%*c를 이용해 공백 제거

	printf("%d", CheckCount(str1, str3)); //함수 호출하여 요구한 문제 해결

	return 0;
}


int CheckCount(char* st1, char* st3) { //문자열 포함 확인 함수
	int indicator = 0;
	int len1 = strlen(st1);
	int len3 = strlen(st3);

	for (int i = 0; i <= len1; i++) { //모든 문자에 대한 탐색 시작
		int testor = 1; //포함 확인자 초기화
		for (int k = 0; k < len3; k++) { //포함될 문자열의 길이만큼 반복
			if (st1[i + k] != st3[k]) { //문자가 일치 하지 않으면 확인자 변경
				testor = 0;
			}
		}
		if (testor == 1) { //확인자가 포함될 문자열의 길이와 같아질경우 포함한다 간주하고 횟수 1증가
			indicator++;
			i += len3 - 1; //중복 방지를 위해 건너뛰기
		}
	}

	return indicator; //최종 카운팅값 확인
}