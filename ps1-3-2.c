#include <stdio.h>

void PRT(int n, char* p); //�Լ� ���� ����

int main() {
	char ch[100]; //���� ����
	char long_word[100], tmp_word[100];
	int length = 0, max_length = 0;
	int max_arg = 0;

	for (char* p = ch; p < ch + 100; p++) { //�Է��� ���� ����
		scanf("%c", p);
		if (*p == '#') { break; } //��������
		max_arg++;
	}

	for (char* p = ch; p < ch + max_arg; p++) { //�Է¹��� ��ŭ�� �ݺ�
		if (*p >= 'a' && *p <= 'z') { //�ҹ��� �� ��쿡�� ���
			*(tmp_word + length) = *p; //�ӽôܾ ���ĺ� ����
			length++;
			printf("%c", *p); //�� ���ڸ� ���
		}
		else {
			if (length > 0) { //�ҹ������� �ٸ� ���ڰ� ���ð�츸 �ٹٲ�
				printf("\n");
			}
			if (length > max_length) { //���� ���� �ִ뺸�� Ŭ��� ����
				max_length = length;
				for (int i = 0; i < max_length; i++) { //�ִ���� ���Ž� �ܾ� ����
					*(long_word + i) = *(tmp_word + i);
				}
			}
			length = 0; //���̰� �ʱ�ȭ
		}
	}
	if (length > 0) { //�������� �ҹ��ڷ� ������ ����� ����ó��
		printf("\n");
	}
	printf("%d %c\n", max_length, *long_word); //�ִ� ���� ���/��ܾ��� �ձ��� ���
	PRT(max_length, long_word);

	return 0;
}

void PRT(int n, char* p) {
	for (char* c = p; c < p + n; c++) { //��ܾ� ���
		printf("%c", *c);
	}
}