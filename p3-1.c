#include <stdio.h>

struct vector { //����ü ����
	int x;
	int y;
	int z;
};

int main() {
	struct vector v1; //����ü ����
	struct vector v3;
	struct vector v4;

	scanf("%d %d %d", &v1.x, &v1.y, &v1.z); //�Է����� �ʱ�ȭ
	scanf("%d %d %d", &v3.x, &v3.y, &v3.z);

	v4.x = v1.x * v3.x; //���Һ� ������
	v4.y = v1.y * v3.y;
	v4.z = v1.z * v3.z;

	printf("%d %d %d\n", v4.x, v4.y, v4.z); //������ ���� ���
	printf("%d", v4.x + v4.y + v4.z); //���� ���

	return 0;
}