#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct taxi_info { //구조체 정의
	char start[11]; //출발지
	char target[11]; //목적지
	double distance; //거리
	int t_time; //정체시간
	char late_night; //심야여부
	int tot; //최종금액
};

typedef struct taxi_info TAXI; //사용자 정의형으로 선언

TAXI* sel_max(TAXI* p, int N, char* s, char* d);

int main() {
	int N; //운행수 
	TAXI* info; //구조체 변수로 선언
	char start[11], destination[11];

	scanf("%d", &N); //운행수 입력
	info = (TAXI*)malloc(N * sizeof(TAXI)); //운행수만큼만 동적할당

	for (TAXI* p = info; p < info + N; p++) { //운행수만큼 입력받기
		scanf("%s %s %lf %d %c", p->start, p->target, &p->distance, &p->t_time, &p->late_night);
		if (p->late_night == 'N') { //주간 운행일때
			if (p->distance >= 2.0) { //추가운임이 발생할 경우
				p->tot = (int)(((p->distance) - 2) * 1000 / 100) * 100 + (int)(p->t_time / 30) * 100 + 3800;
			}
			else { //추가운임이 발생하지 않을 경우
				p->tot = (int)(p->t_time / 30) * 100 + 3800;
			}
		}
		else { //심야 할증일때
			if (p->distance >= 2.0) { //추가운임이 발생할 경우
				p->tot = (int)(((p->distance) - 2) * 1000 / 100) * 120 + (int)(p->t_time / 30) * 120 + 4800;
			}
			else { //추가운임이 발생하지 않을 경우
				p->tot = (int)(p->t_time / 30) * 120 + 4800;
			}
		}
	}

	scanf("%s %s", start, destination); //검색할 출발/목적지 설정
	TAXI* result = sel_max(info, N, start, destination); //최대요금찾기 함수 호출후 결과값 저장

	printf("%0.2f %d %c %d", result->distance, result->t_time, result->late_night, result->tot);

	free(info); //메모리 해제

	return 0;
}

//최대요금찾기 함수
TAXI* sel_max(TAXI* p, int N, char* s, char* d) {
	TAXI* max = NULL; //최대값 설정

	for (TAXI* k = p;k < p +N ; k++) {
		if (strcmp(k->start, s) == 0 && strcmp(k->target, d) == 0) { //검색조건 확인
			if (max == NULL || max->tot < k->tot) { //최대값인지 확인
				max = k; //최대값 갱신
			}
		}
	}

	return max; //최대값 구조체 리턴
}