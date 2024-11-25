#include <stdio.h>
#include <string.h>

typedef struct { //����ü ����
	char name[30]; //ȣ�� �̸�
	double rating; //ȣ�� ���ǵ�
	int tier; //ȣ�� ���
	double distance; //ȣ�ڰ��� �Ÿ�
	char breakfast; //���� ���Կ���
} hotel_info; //����� ���� �ڷ����̸�

int in_hotel_info(hotel_info* p); //�Է� �Լ�
void out_hotel_info(hotel_info* p, int N, int G, double D); //�˻��� ����Լ�

int main() {
	int tier; //��������
	int N = 0;
	double distance;
	hotel_info info[100];

	N = in_hotel_info(info); //�Է��Լ� ȣ���� �Էµ� ȣ�ڼ� ����
	scanf("%d %lf", &tier, &distance); //�˻����� �Է�

	out_hotel_info(info, N, tier, distance); //�˻������� �����Ͽ� �Լ� ȣ��

	return 0;
}

//�Է��Լ�
int in_hotel_info(hotel_info* p) {
	int N = 0; //ȣ�ڼ� �ʱ�ȭ

	for (hotel_info* k = p; ; k++) {
		scanf("%s", k->name);
		if (strcmp(k->name, "0") == 0) { //�������� 
			break;
		}
		scanf("%d %lf %lf %c", &k->tier, &k->rating, &k->distance, &k->breakfast); //ȣ�� �̸�, ���, ���ǵ�, �Ÿ�, ���Ŀ��� �Է�
		getchar();

		N++; //ȣ�ڼ� ����
	}

	return N;
}


//�˻��� ����Լ�
void out_hotel_info(hotel_info* p, int N, int G, double D) {

	for (int i = 0; i < N - 1; i++) {
		for (hotel_info* k = p; k < p + N; k++) { //ȣ�� ����
			if (k->rating < (k + 1)->rating) { //������������ ����
				hotel_info tmp = *k;
				*k = *(k + 1);
				*(k + 1) = tmp;
			}
			if (strcmp(k->name, (k + 1)->name) > 0 && k->rating == (k + 1)->rating) { //���������� ��� ������ ����
				hotel_info tmp = *k;
				*k = *(k + 1);
				*(k + 1) = tmp;
			}
		}
	}

	for (hotel_info* k = p; k < p + N; k++) {
		if (k->tier >= G && k->distance <= D) { //�˻�����
			printf("%s %d %0.1f %0.1f %c", k->name, k->tier, k->rating, k->distance, k->breakfast); //���������� �˻��� ���� ���������� ���� �̸��� ���� ȣ�� ���� ���
		}
	}

	return 0;
}