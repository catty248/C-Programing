#include <stdio.h>
#include <string.h>

int main() {
	char st[100][101]; //���� ����
	int N, min_len = 100, min_index;

	scanf("%d", &N); //�Է¹��� Ƚ�� �ʱ�ȭ
	for (int i = 0; i < N; i++) { //Ƚ����ŭ �ݺ�
		scanf("%s", st[i]); //���ڿ� �Է¹ޱ�
		if (strlen(st[i]) < min_len) { //���� ���� ���ڿ��� ���̰� ���� �ּҰ����� �۴ٸ�
			min_len = strlen(st[i]); //�� ����
			min_index = i;
		}
	}
	printf("%s", st[min_index]); //�ּ� ���ڿ� ���

	return 0;
}