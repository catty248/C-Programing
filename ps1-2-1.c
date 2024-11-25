#include <stdio.h>

int main() {
	int sit_array[22] = {0,}, input_array[21]; //변수 선언
	int N, test = 0;

	scanf("%d", &N); //반복횟수 입력
	if (N < 5) { //최소 인원수 제한
		printf("-1"); //출력
	}
	else { //최소인원수 충족시
		for (int* p = input_array; p < input_array + N; p++) { //배열 반복
			scanf("%d", p);
			*(sit_array+(*p)) += 1; //자리값에 명수 추가
		}
		for (int* p = input_array; p < input_array + N; p++) { //배열반복
			if (*(sit_array + (*p)) > 1) { //중복 자리일경우
				test = 1; //확인자 조정
				printf("%d %d\n", *p, *(sit_array + (*p))); //출력
				*(sit_array + (*p)) = 0; //중복출력방지를 위한 메모리값 초기화
			}
		}
		if (test == 0) {
			printf("0"); //확인자가 변경안된거 확인되면 0출력
		}
	}

	return 0;
}