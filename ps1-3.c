#include <stdio.h>

int main() {
	char ch[100]; //���� ����
	int length = 0, max_length = 0;
	int max_arg = 0;

	for (char* p = ch; p < ch + 100; p++) { //�Է��� ���� ����
		scanf("%c", p);
		if (*p == '#') {break;} //��������
		max_arg++;
	}

	for (char* p = ch; p < ch + max_arg; p++) { //�Է¹��� ��ŭ�� �ݺ�
		if (*p >= 'a' && *p <= 'z') { //�ҹ��� �� ��쿡�� ���
			length++;
			if (length > max_length) { //���� ���� �ִ뺸�� Ŭ��� ����
				max_length = length;
			}
			printf("%c", *p); //�� ���ڸ� ���
		}
		else {
			if (length > 0) { //�ҹ������� �ٸ� ���ڰ� ���ð�츸 �ٹٲ�
				printf("\n");
			}
			length = 0; //���̰� �ʱ�ȭ
		}
	}
	if (length > 0) { //�������� �ҹ��ڷ� ������ ����� ����ó��
		printf("\n");
	}
	printf("%d", max_length); //�ִ� ���� ���


	return 0;
}