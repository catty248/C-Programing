#include <stdio.h>

int main() {
	int sit_array[22] = {0,}, input_array[21]; //���� ����
	int N, test = 0;

	scanf("%d", &N); //�ݺ�Ƚ�� �Է�
	if (N < 5) { //�ּ� �ο��� ����
		printf("-1"); //���
	}
	else { //�ּ��ο��� ������
		for (int* p = input_array; p < input_array + N; p++) { //�迭 �ݺ�
			scanf("%d", p);
			*(sit_array+(*p)) += 1; //�ڸ����� ��� �߰�
		}
		for (int* p = input_array; p < input_array + N; p++) { //�迭�ݺ�
			if (*(sit_array + (*p)) > 1) { //�ߺ� �ڸ��ϰ��
				test = 1; //Ȯ���� ����
				printf("%d %d\n", *p, *(sit_array + (*p))); //���
				*(sit_array + (*p)) = 0; //�ߺ���¹����� ���� �޸𸮰� �ʱ�ȭ
			}
		}
		if (test == 0) {
			printf("0"); //Ȯ���ڰ� ����ȵȰ� Ȯ�εǸ� 0���
		}
	}

	return 0;
}