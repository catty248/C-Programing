#include <stdio.h>
#include <string.h>

int check_w(char* p, char* q); //함수 원형 선언

int main() {
	int N, M, tmp = 0, max, index; //변수 선언
	int result[10] = { 0, };
	char st[10][101] = { "", };

	//입력구
	scanf("%d %d", &N, &M);
	getchar(); //개행문자 제거

	//입력받은만큼 반복 시작
	for (int i = 0; i < N; i++) {
		gets(st[i]);
		tmp = check_w(st[i], st[i] + M); //문자외 기호 개수 확인
		result[i] = tmp;
	}

	//기호가 많은 순서대로 출력
	for (int i = 0; i < 10; i++) {
		max = 0, index = 0;
		for (int k = 0; k < 10; k++) { //최대값 찾기
			if (result[k] > max) {
				max = result[k];
				index = k;
			}
		}
		if (max != 0) { //0은 출력 안함으로 예외처리후 출력
			printf("%s\n", st[index]);
			result[index] = 0; //출력한 값은 0으로 초기화 시켜 다음 연산에서 제외
		}
	}


	return 0;
}


//문자외 기호개수 확인 함수
int check_w(char* p, char* q) {
	int count = 0;

	//문자열 시작부터 끝까지 확인
	for (char* k = p; k < q && *k != '\0'; k++) {
		if ((*k >= 'a' && *k <= 'z') || (*k >= 'A' && *k <= 'Z') || (*k == ' ')) {
			continue;
		}
		else {
			count++;
		}
	}

	return count;
}