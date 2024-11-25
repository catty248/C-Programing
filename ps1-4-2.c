#include <stdio.h>

void bubble_sort(int* p, int len); //함수 원형 선언

int main() {
	int n[11], m[11]; //변수 선언
	int len_n = 0, len_m = 0; //길이 변수

	for (int* p = n; p < n + 11; p++) { //101호 시험장 점수와 수험생 입력
		scanf("%d", p);
		if (*p == -1) { break; }
		len_n++;
	}

	for (int* p = m; p < m + 11; p++) { //102호 시험장 점수와 수험생 입력
		scanf("%d", p);
		if (*p == -1) { break; }
		len_m++;
	}

	bubble_sort(n, len_n), bubble_sort(m, len_m); //최대 점수와 최소 점수를 비교하기 위한 
	//정렬 함수 호출

	int cn = 0, cm = 0; //증감값 초기화
	for (int i = 0; i < len_n; i++) { //학생수만큼 반복
		if (*(n + len_n-1  - cn) > *(m + len_m-1 - cm)) { //큰값부터 비교
			printf("%d ", *(n + len_n-1  - cn)); //출력된값은 증감값 변화
			cn++;
		}
		else {
			printf("%d ", *(m + len_m-1  - cm)); //출력된 값은 증감값 변화
			cm++;
		}
	}
	printf("\n"); //1회차 루프 끝나면 줄바꿈

	cn = 0, cm = 0; //증감값 초기화
	for (int i = 0; i < len_m; i++) { //학생수만큼 반복
		if (*(n + cn) < *(m+ cm)) { //작은값부터 비교
			printf("%d ", *(n  + cn)); //출력된값은 증감값 변화
			cn++;
		}
		else {
			printf("%d ", *(m  + cm)); //출력된 값은 증감값 변화
			cm++;
		}
	}

	return 0;

}

void bubble_sort(int* p, int len) { //버블정렬 함수
	for (int i = 0; i < len - 1; i++) {
		for (int* k = p; k < p + len - i - 1; k++) {
			if (*k > *(k + 1)) {
				int tmp = *k;
				*k = *(k + 1);
				*(k + 1) = tmp;
			}
		}
	}
}