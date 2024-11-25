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

	printf("%d %d\n", len_n, len_m); //수험생의 수 먼저 출력
	bubble_sort(n, len_n), bubble_sort(m, len_m); //최대 점수와 최소 점수를 비교하기 위한 
												  //정렬 함수 호출

	if (*(n + len_n - 1) > *(m + len_m - 1)) { //정렬된 후에 값 비교 하여 최대 점수 출력
		printf("%d", *(n + len_n - 1));
	}
	else {printf("%d", *(m + len_m - 1));}

	if (*(n) > *(m)) { printf("%d ", *m); } //정렬된 후에 값 비교하여 최소 점수 출력
	else { printf("%d", *n); }

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