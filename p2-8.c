#include <stdio.h>
#include <string.h> //���ο� ���̺귯�� ����

int main() {
	char A[101], B[101]; //���� ���� (��ĥ��츦 �����Ͽ� ���� �����Ӱ�)

	scanf("%s", A); //�Է����� �ʱ�ȭ
	scanf("%s", B);

	int result = strcmp(A, B); //���ڿ��� ������ ��
	if (result < 0) { //������ζ��
		printf("%s", strcat(B, A)); //����� ��ģ�� ���
	}
	else { //�����̶��
		printf("%s", strcat(A, B)); //�״�� ��ģ�� ���
	}
	return 0;
}