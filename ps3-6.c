#include <stdio.h>
#include <string.h>

typedef struct { //구조체 정의
	char name[30]; //호텔 이름
	double rating; //호텔 평판도
	int tier; //호텔 등급
	double distance; //호텔과의 거리
	char breakfast; //조식 포함여부
} hotel_info; //사용자 정의 자료형이름

int in_hotel_info(hotel_info* p); //입력 함수
void out_hotel_info(hotel_info* p, int N, int G, double D); //검색후 출력함수

int main() {
	int tier; //변수선언
	int N = 0;
	double distance;
	hotel_info info[100];

	N = in_hotel_info(info); //입력함수 호출후 입력된 호텔수 저장
	scanf("%d %lf", &tier, &distance); //검색조건 입력

	out_hotel_info(info, N, tier, distance); //검색조건을 대입하여 함수 호출

	return 0;
}

//입력함수
int in_hotel_info(hotel_info* p) {
	int N = 0; //호텔수 초기화

	for (hotel_info* k = p; ; k++) {
		scanf("%s", k->name);
		if (strcmp(k->name, "0") == 0) { //종료조건 
			break;
		}
		scanf("%d %lf %lf %c", &k->tier, &k->rating, &k->distance, &k->breakfast); //호텔 이름, 등급, 평판도, 거리, 조식여부 입력
		getchar();

		N++; //호텔수 계산용
	}

	return N;
}


//검색후 출력함수
void out_hotel_info(hotel_info* p, int N, int G, double D) {

	for (int i = 0; i < N - 1; i++) {
		for (hotel_info* k = p; k < p + N; k++) { //호텔 정렬
			if (k->rating < (k + 1)->rating) { //평점기준으로 정렬
				hotel_info tmp = *k;
				*k = *(k + 1);
				*(k + 1) = tmp;
			}
			if (strcmp(k->name, (k + 1)->name) > 0 && k->rating == (k + 1)->rating) { //같은평점일 경우 사전순 정렬
				hotel_info tmp = *k;
				*k = *(k + 1);
				*(k + 1) = tmp;
			}
		}
	}

	for (hotel_info* k = p; k < p + N; k++) {
		if (k->tier >= G && k->distance <= D) { //검색조건
			printf("%s %d %0.1f %0.1f %c", k->name, k->tier, k->rating, k->distance, k->breakfast); //최종적으로 검색된 가장 사전순으로 빠른 이름을 가진 호텔 정보 출력
		}
	}

	return 0;
}