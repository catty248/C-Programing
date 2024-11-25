#include <stdio.h>

int passengerN(int n); //함수 원형 선언
void rebooking(int* ar);
int changeseat(int* ar);

int main() {
	int input_array[21] = {0,}; //변수 선언
	int N;

	scanf("%d", &N); //반복횟수 입력
	if (passengerN(N) == -1) { //인원 함수 호출
		printf("-1"); //인원이 모자라면 -1 출력
		return 0; //리턴으로 종료
	}

	for (int* p = input_array; p < input_array + N; p++) { //배열 반복
		scanf("%d", p); //배열 초기화
	}
	rebooking(input_array); //재예약 함수 호출
	printf("0\n"); //정상코드 출력
	for (int* p = input_array; p < input_array + N; p++) { //배열 반복
		printf("%d ", *p); //처리완료된 배열 출력
	}

	return 0;
}

int passengerN(int n) { //인원 함수
	if (n < 5) { //모자르면 -1 리턴
		return -1;
	}
	return 0;
}

void rebooking(int* ar) { //재예약 함수
	int sit_array[22] = { 0, }, checking[22] = {0,}; //인원수변수와 확인 변수 선언
	for (int* p = ar; p < ar + 21; p++) { //중복인원 체크
		*(sit_array + *(p)) += 1;
	}
	for (int* p = ar; p < ar+21; p++) { //자리 확인
		if (*(sit_array + *(p)) > 1 && *p != 0 && *(checking+ *(p)) != 0) {
			*(sit_array + *(p)) -= 1;
			*p = changeseat(sit_array); //빈자리 확인 함수
		}
		*(checking + *(p)) += 1; //확인변수 체크
	}
}

int changeseat(int* ar) { //빈자리 함수
	int index = 1; //인덱스값을 리턴하기 위해 선언
	for (int* p = ar+1; p < ar + 22; p++) {
		if (*p < 1) { //빈자리 확인되면 
			*p += 1; //자리값에 1추가후
			return index; //인덱스 리턴
		}
		index++;
	}
	return 0;
}