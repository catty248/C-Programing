#include <stdio.h>

void strcopy(char a[], char b[]); //�Լ� ���� ����

int main() {
	char ch[6]; //���ڿ� ����
	char co[6];

	for (char* p = ch; p < ch + 6; p++) { //������ �ݺ����� �Է¹ޱ�
		scanf("%c", p);
	}
	strcopy(ch, co); //�Լ� ȣ��

	for (char* p = co; p < co + 6; p++) { //������ �ݺ����� ����ϱ�
		printf("%c", *p);
	}

	return 0;

}


void strcopy(char a[], char b[]) { //�����Լ�
	for (int i = 0; i < 6; i++) { //�ݺ������� ������ ���� �ҷ��� ����
		*(b + i) = *(a + i);
	}
}