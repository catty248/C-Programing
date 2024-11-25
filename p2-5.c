#include <stdio.h>

int main() {
	char st[41], ch[21]; //변수 선언
	int slen = 0,len = 0, index;

	scanf("%s", st); //첫번째 문자열 초기화
	for (int i = 0; i < 21; i++) { //첫번쨰 문자열 인덱스값 확인
		if (st[i] == '\0') {
			break;
		}
		slen++;
	}
	scanf("%s", ch); //두번쨰 문자열 초기화
	for (int i = 0; i < 21; i++) { //추번쨰 문자열 인덱스값 확인
		if (ch[i] == '\0') {
			break;
		}
		len++;
	}
	scanf("%d", &index); //집어넣을 인덱스값 입력
	for (int i = slen; i >= index; i--){ //넣을 구간부터 두번쨰 문자열만ㅌ큼 뒤로 밀기
		st[i + len] = st[i];
	}
	for (int i = 0; i < len; i++) { //두번쨰 문자열을 첫번쨰 비워둔 문자열 사이에 복사
		st[index + i] = ch[i];
	}
	st[len + slen] = '\0'; //마지막 개행문자 추가

	printf("%s", st); //출력
	return 0;
}