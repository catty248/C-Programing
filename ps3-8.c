#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { //사용자 정의형 구조체 선언
	int car_num; //차량번호
	int ph_num; //전화번호
	char type; //상품 유형
	char member; //정기권 가입 유무
	int m_type; //정기권 형태
	int min; //주차시간
	double tot; //최종요금
} info;

void input(info* p, int N); //함수 원형 선언
void compute(info* p);
void display(info* p, int N);

int main() {
	info* parking; //구조체 포인터 선언
	int N;

	scanf("%d", &N); //차량수 입력
	parking = (info*)malloc(N * sizeof(info)); //동적 메모리 할당

	input(parking, N); //입력함수 호출
	for (info* p = parking; p < parking + N; p++) { //모든 차량에 대해 요금 계산
		compute(p);
	}
	parking_info_sort(parking, N); //정렬함수 호출
	display(parking, N); //계산된 정보 출력

	free(parking);

	return 0;
}

//입력함수
void input(info* p, int N) {
	for (info* k = p; k < p + N; k++) {
		scanf("%d %d %c", &k->car_num, &k->ph_num, &k->type); //기본정보 입력
		getchar();
		if (k->type == 'S') { //정기권 구매자인지 확인
			scanf("%c %d %d", &k->member, &k->m_type, &k->min); //구매자인경우 추가정보 입력
		}
		else {
			scanf("%d", &k->min);
		}
	}
}

//요금계산 함수
void compute(info* p) {
	if (p->type == 'S') { //상품 확인
		if (p->member == 'N') { //정기권 유무 확인
			if (p->m_type == 7) {
				p->tot = 30000.0;
			}
			else if (p->m_type == 30) {
				p->tot = 100000.0;
			}
			else {
				p->tot = 500000.0;
			}
		}
		else { //정기권 대상자에 대해 기본요금 미적용
			p->tot = 0.0;
		}
	}
	else { //일일권 요금 부과
		p->tot = 5000.0;
	}

	if (p->min > 240) { //초과된 시간에 대한 추가요금계산
		p->tot += ((p->min - 240) / 10) * 200;
	}

}
//정렬함수
void parking_info_sort(info* p, int N) {
	for (int i = 0; i < N - 1; i++) {
		for (info* k = p; k < p + N - 1 - i; k++) {
			if (k->type == 'S' && (k+1)->type == 'D') { //둘의 주차권이 다르면 정렬
				info tmp = *k;
				*k = *(k + 1);
				*(k + 1) = tmp;
			}
			if (k->type == (k+1)->type && k->car_num >(k + 1)->car_num) { //주차권종이 같을경우 차량번호순으로 정렬
				info tmp = *k;
				*k = *(k + 1);
				*(k + 1) = tmp;
			}
		}
	}
}

//출력함수
void display(info* p, int N) {
	double D = 0.0, S = 0.0;
	for (info* k = p; k < p + N; k++) { //모든 정보에 대해 출력
		printf("%d %d %c %.0f\n", k->car_num, k->ph_num, k->type, k->tot);
		if (k->type == 'D') { //주차권종별 요금 합산
			D += k->tot;
		}
		else {
			S += k->tot;
		}
	}
	printf("%.0f %.0f %.0f", D, S, D + S); //주차권종별 요금 출력후 총합요금 출력
}