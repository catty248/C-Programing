#include <stdio.h>

int passengerN(int n); //�Լ� ���� ����
void rebooking(int* ar);
int changeseat(int* ar);

int main() {
	int input_array[21] = {0,}; //���� ����
	int N;

	scanf("%d", &N); //�ݺ�Ƚ�� �Է�
	if (passengerN(N) == -1) { //�ο� �Լ� ȣ��
		printf("-1"); //�ο��� ���ڶ�� -1 ���
		return 0; //�������� ����
	}

	for (int* p = input_array; p < input_array + N; p++) { //�迭 �ݺ�
		scanf("%d", p); //�迭 �ʱ�ȭ
	}
	rebooking(input_array); //�翹�� �Լ� ȣ��
	printf("0\n"); //�����ڵ� ���
	for (int* p = input_array; p < input_array + N; p++) { //�迭 �ݺ�
		printf("%d ", *p); //ó���Ϸ�� �迭 ���
	}

	return 0;
}

int passengerN(int n) { //�ο� �Լ�
	if (n < 5) { //���ڸ��� -1 ����
		return -1;
	}
	return 0;
}

void rebooking(int* ar) { //�翹�� �Լ�
	int sit_array[22] = { 0, }, checking[22] = {0,}; //�ο��������� Ȯ�� ���� ����
	for (int* p = ar; p < ar + 21; p++) { //�ߺ��ο� üũ
		*(sit_array + *(p)) += 1;
	}
	for (int* p = ar; p < ar+21; p++) { //�ڸ� Ȯ��
		if (*(sit_array + *(p)) > 1 && *p != 0 && *(checking+ *(p)) != 0) {
			*(sit_array + *(p)) -= 1;
			*p = changeseat(sit_array); //���ڸ� Ȯ�� �Լ�
		}
		*(checking + *(p)) += 1; //Ȯ�κ��� üũ
	}
}

int changeseat(int* ar) { //���ڸ� �Լ�
	int index = 1; //�ε������� �����ϱ� ���� ����
	for (int* p = ar+1; p < ar + 22; p++) {
		if (*p < 1) { //���ڸ� Ȯ�εǸ� 
			*p += 1; //�ڸ����� 1�߰���
			return index; //�ε��� ����
		}
		index++;
	}
	return 0;
}