#include <stdio.h>
#include <string.h>

int check(char* ch); //�Լ� ���� ����

int main() {
	char in_char[31]; //���� ����

	scanf("%s", in_char); //Ȯ���� ���� �Է¹޾� �ʱ�ȭ
	printf("%d %d", strlen(in_char), check(in_char)); //ǥ�� ���ڿ� ó�� �Լ��� ����� ���� ��� �� �Լ� ȣ��

	return 0;
}

int check(char* ch) { 
	char rch[31]; //������ ������ ���� ����
	for (int i = 0; i < strlen(ch); i++) { //���ڿ��� ���̸� �̿��� ���� ����
		rch[strlen(ch) - i-1] = ch[i];
	}
	rch[strlen(ch)] = '\0'; //�񱳸� ���� ������ �ι��� �߰�

	if (strcmp(ch, rch) == 0) { //���Լ� ����Ͽ� ����� ���
		return 1;
	}
	else {
		return 0;
	}
}