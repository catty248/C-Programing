#include <stdio.h>
#include <string.h>

int check_w(char* p, char* q); //�Լ� ���� ����

int main() {
	int N, M, tmp = 0, max, index; //���� ����
	int result[10] = { 0, };
	char st[10][101] = { "", };

	//�Է±�
	scanf("%d %d", &N, &M);
	getchar(); //���๮�� ����

	//�Է¹�����ŭ �ݺ� ����
	for (int i = 0; i < N; i++) {
		gets(st[i]);
		tmp = check_w(st[i], st[i] + M); //���ڿ� ��ȣ ���� Ȯ��
		result[i] = tmp;
	}

	//��ȣ�� ���� ������� ���
	for (int i = 0; i < 10; i++) {
		max = 0, index = 0;
		for (int k = 0; k < 10; k++) { //�ִ밪 ã��
			if (result[k] > max) {
				max = result[k];
				index = k;
			}
		}
		if (max != 0) { //0�� ��� �������� ����ó���� ���
			printf("%s\n", st[index]);
			result[index] = 0; //����� ���� 0���� �ʱ�ȭ ���� ���� ���꿡�� ����
		}
	}


	return 0;
}


//���ڿ� ��ȣ���� Ȯ�� �Լ�
int check_w(char* p, char* q) {
	int count = 0;

	//���ڿ� ���ۺ��� ������ Ȯ��
	for (char* k = p; k < q && *k != '\0'; k++) {
		if ((*k >= 'a' && *k <= 'z') || (*k >= 'A' && *k <= 'Z') || (*k == ' ')) {
			continue;
		}
		else {
			count++;
		}
	}

	return count;
}