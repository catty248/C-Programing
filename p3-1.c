#include <stdio.h>

struct vector { //구조체 정의
	int x;
	int y;
	int z;
};

int main() {
	struct vector v1; //구조체 선언
	struct vector v3;
	struct vector v4;

	scanf("%d %d %d", &v1.x, &v1.y, &v1.z); //입력으로 초기화
	scanf("%d %d %d", &v3.x, &v3.y, &v3.z);

	v4.x = v1.x * v3.x; //원소별 곱연산
	v4.y = v1.y * v3.y;
	v4.z = v1.z * v3.z;

	printf("%d %d %d\n", v4.x, v4.y, v4.z); //연산한 벡터 출력
	printf("%d", v4.x + v4.y + v4.z); //내적 계산

	return 0;
}