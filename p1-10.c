#include <stdio.h>

void strcopy(char a[], char b[]); //함수 원형 선언

int main() {
	char ch[6]; //문자열 선언
	char co[6];

	for (char* p = ch; p < ch + 6; p++) { //포인터 반복으로 입력받기
		scanf("%c", p);
	}
	strcopy(ch, co); //함수 호출

	for (char* p = co; p < co + 6; p++) { //포인터 반복으로 출력하기
		printf("%c", *p);
	}

	return 0;

}


void strcopy(char a[], char b[]) { //복사함수
	for (int i = 0; i < 6; i++) { //반복문으로 포인터 값을 불러와 복사
		*(b + i) = *(a + i);
	}
}