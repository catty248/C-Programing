#include <stdio.h>
#include <string.h>

int check(char* st1, char* st3); //함수 원형선언

int main() {
	char str1[81], str2[82]; //변수 선언

	scanf("%s", str1); //문자열 초기화
	scanf("%s", str2);

	printf("%d %d", strlen(str1), check(str1, str2)); //길이와 포함여부 출력 

	return 0;
}

int check(char* st1, char* st3) { //문자열 포함 확인 함수
	for (int i = 0; i < strlen(st1); i++) { //모든 문자에 대한 탐색 시작
		int testor = 0; //포함 확인자 초기화
		for (int k = 0; k < strlen(st3); k++) { //포함될 문자열의 길이만큼 반복
			if (st1[i + k] == st3[k]) { //문자가 포함될때마다 확인자 1증가
				testor++;
			}	
		}
		if (testor == strlen(st3)) { //확인자가 포함될 문자열의 길이와 같아질경우 포함한다 간주하고 1리턴
			return 1;
		}
	}
	
	return 0; //아무것도 감지되지 않았다면 포함안될걸로 간주
}