#include <stdio.h>
#include <string.h>

int check(char* st1, char* st3); //�Լ� ��������

int main() {
	char str1[81], str2[82]; //���� ����

	scanf("%s", str1); //���ڿ� �ʱ�ȭ
	scanf("%s", str2);

	printf("%d %d", strlen(str1), check(str1, str2)); //���̿� ���Կ��� ��� 

	return 0;
}

int check(char* st1, char* st3) { //���ڿ� ���� Ȯ�� �Լ�
	for (int i = 0; i < strlen(st1); i++) { //��� ���ڿ� ���� Ž�� ����
		int testor = 0; //���� Ȯ���� �ʱ�ȭ
		for (int k = 0; k < strlen(st3); k++) { //���Ե� ���ڿ��� ���̸�ŭ �ݺ�
			if (st1[i + k] == st3[k]) { //���ڰ� ���Եɶ����� Ȯ���� 1����
				testor++;
			}	
		}
		if (testor == strlen(st3)) { //Ȯ���ڰ� ���Ե� ���ڿ��� ���̿� ��������� �����Ѵ� �����ϰ� 1����
			return 1;
		}
	}
	
	return 0; //�ƹ��͵� �������� �ʾҴٸ� ���Ծȵɰɷ� ����
}