#include <stdio.h>

void gcdlcm(int x, int y, int* a, int* b); //함수 원형 선언


int main() {
	int x, y; //변수 선언
	int a, b;

	scanf("%d %d", &x, &y); //입력받아 초기화
	gcdlcm(x, y, &a, &b); //함수 호출

	printf("%d %d", a, b); //포인터를 이용해 출력

	return 0;
}


void gcdlcm(int x, int y, int* a, int* b) {
	int N = 0; //기준 숫자 설정
	if (x <= y) { //비교후 작은 숫자로 설정
		N = x;
	}
	else {
		N = y;
	}
	
	for (int i = N; i > 1; i--) { //최대 공약수 구하기
		if (x % i == 0 && y % i == 0) {
			*a = i;
			N = i;
			break;
		}
	}

	*b = (x / N) * (y / N) * (N); //최대 공배수 공식 사용
	//값들은 포인터에 저장해 이동
}