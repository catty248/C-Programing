#include <stdio.h>
#include <string.h> //새로운 라이브러리 도입

int main() {
	char A[101], B[101]; //변수 선언 (합칠경우를 생각하여 공간 여유롭게)

	scanf("%s", A); //입력으로 초기화
	scanf("%s", B);

	int result = strcmp(A, B); //문자열의 사전순 비교
	if (result < 0) { //순서대로라면
		printf("%s", strcat(B, A)); //뒤집어서 합친후 출력
	}
	else { //역순이라면
		printf("%s", strcat(A, B)); //그대로 합친후 출력
	}
	return 0;
}