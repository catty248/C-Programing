#include <stdio.h>

int main() {
	int N; //���� ����
	int in_N[4] = {0,};
	char st[4][4] = { "\0", "TEN", "HUN", "THO"}; //���� �迭�� ���ڿ� ����
	char cNum[9][6] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	scanf("%d", &N); //�� �Է¹޾� �ʱ�ȭ
	for (int* p = in_N; p < in_N + 4; p++) { //���� �������� ���� ����
		*p = N % 10;
		N /= 10;
	}

	for (int i = 3; i >= 0; i--) { //�������� �ҷ����� �۾�ó��
		if (in_N[i] != 0) { //0�ϰ�� ĵ��
			printf("%s %s ", cNum[in_N[i]-1], st[i]); //�������ǿ� �°� ���
		}
	}

	return 0;
}

