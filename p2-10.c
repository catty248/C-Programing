#include <stdio.h>
#include <string.h>

int main() {
	char st[100][101]; //변수 선언
	int N, min_len = 100, min_index;

	scanf("%d", &N); //입력받을 횟수 초기화
	for (int i = 0; i < N; i++) { //횟수만큼 반복
		scanf("%s", st[i]); //문자열 입력받기
		if (strlen(st[i]) < min_len) { //새로 받은 문자열의 길이가 기존 최소값보다 작다면
			min_len = strlen(st[i]); //값 갱신
			min_index = i;
		}
	}
	printf("%s", st[min_index]); //최소 문자열 출력

	return 0;
}