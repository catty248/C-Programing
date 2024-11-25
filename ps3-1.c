#include <stdio.h>
#include <stdlib.h>

struct taxi_info { //구조체 정의
	char start[11]; //출발지
	char target[11]; //목적지
	double distance; //거리
	int t_time; //정체시간
	char late_night; //심야여부
	int tot; //최종금액
};

typedef struct taxi_info TAXI; //사용자 정의형으로 선언

int main() {
	int N; //운행수 
	TAXI *info; //구조체 변수로 선언

	scanf("%d", &N); //운행수 입력
	info = (TAXI*)malloc(N * sizeof(TAXI)); //운행수만큼만 동적할당

	for (TAXI* p = info; p < info + N; p++) { //운행수만큼 입력받기
		scanf("%s %s %lf %d %c", p->start, p->target, &p->distance, &p->t_time, &p->late_night);
		if (p->late_night == 'N') { //주간 운행일때
			if (p->distance >= 2.0) { //추가운임이 발생할 경우
				p->tot = (int)(((p->distance) - 2) * 1000/100)*100 + (int)(p->t_time / 30) * 100 + 3800;
			}
			else { //추가운임이 발생하지 않을 경우
				p->tot = (int)(p->t_time / 30) * 100 + 3800;
			}
		}
		else { //심야 할증일때
			if (p->distance >= 2.0) { //추가운임이 발생할 경우
				p->tot = (int)(((p->distance) - 2) * 1000/100)*120 + (int)(p->t_time / 30) * 120 + 4800;
			}
			else { //추가운임이 발생하지 않을 경우
				p->tot = (int)(p->t_time / 30) * 120 + 4800;
			}
		}
	}

	for (TAXI* p = info; p < info + N; p++) { //모든 변수에 대한 출력
		printf("%s %s %d\n", p->start, p->target, p->tot);
	}
	free(info); //메모리 해제

	return 0;
}