#include <stdio.h>

int main() {
	char st[41], ch[21]; //���� ����
	int slen = 0, len = 0, index, test;

	scanf("%s", st); //ù��° ���ڿ� �ʱ�ȭ
	for (int i = 0; i < 21; i++) { //ù���� ���ڿ� �ε����� Ȯ��
		if (st[i] == '\0') {
			break;
		}
		slen++;
	}
	scanf("%s", ch); //�ι��� ���ڿ� �ʱ�ȭ
	for (int i = 0; i < 21; i++) { //�߹��� ���ڿ� �ε����� Ȯ��
		if (ch[i] == '\0') {
			break;
		}
		len++;
	}
	scanf("%d", &index); //������� �ε����� �Է�
	for (int i = slen; i >= index; i--) { //���� �������� �ι��� ���ڿ�����ŭ �ڷ� �б�
		st[i + len] = st[i];
	}
	scanf("%d", &test); //���� ���� Ȯ���� �ʱ�ȭ
	if (test == 0) { //���������� ���
		for (int i = 0; i < len; i++) { //������� ������ ����
			st[index + i] = ch[i];
		}
	}
	else {
		for (int i = 0; i < len; i++) { //�ݴ��ϰ�� ���� ����
			st[index + i] = ch[len - 1 - i];
		}
	}
	st[len + slen] = '\0'; //������ ���๮�� �߰�

	printf("%s", st); //���
	return 0;
}