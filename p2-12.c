#include <stdio.h>
#include <string.h>

int CheckCount(char* st1, char* st3); //�Լ� ��������

int main() {
	char str1[101], str3[101]; //���� ����

	scanf("%[^\n]%*c", str1); //���ڿ� �ʱ�ȭ 
	scanf("%s", str3); //%[^\n]%*c�� �̿��� ���� ����

	printf("%d", CheckCount(str1, str3)); //�Լ� ȣ���Ͽ� �䱸�� ���� �ذ�

	return 0;
}


int CheckCount(char* st1, char* st3) { //���ڿ� ���� Ȯ�� �Լ�
	int indicator = 0;
	int len1 = strlen(st1);
	int len3 = strlen(st3);

	for (int i = 0; i <= len1; i++) { //��� ���ڿ� ���� Ž�� ����
		int testor = 1; //���� Ȯ���� �ʱ�ȭ
		for (int k = 0; k < len3; k++) { //���Ե� ���ڿ��� ���̸�ŭ �ݺ�
			if (st1[i + k] != st3[k]) { //���ڰ� ��ġ ���� ������ Ȯ���� ����
				testor = 0;
			}
		}
		if (testor == 1) { //Ȯ���ڰ� ���Ե� ���ڿ��� ���̿� ��������� �����Ѵ� �����ϰ� Ƚ�� 1����
			indicator++;
			i += len3 - 1; //�ߺ� ������ ���� �ǳʶٱ�
		}
	}

	return indicator; //���� ī���ð� Ȯ��
}