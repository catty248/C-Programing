#include <stdio.h>

int main() {
	int N, ar_count = 0, ar[100];
	int* p;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", p);
		if (*p > 0) {
			*(ar + ar_count) = *p;
			ar_count++;
		}
		else {
			continue;
		}
	}

	if ((ar_count + 1) % 2 == 0) {
		for (int i = 0; i < ar_count - 1; i++) {
			for (int* k = ar; k < ar + ar_count - i - 1; k++) {
				if (*k > *(k + 1)) {
					int tmp = *k;
					*k = *(k + 1);
					*(k + 1) = tmp;
				}
			}
		}
	}
	else {
		for (int i = 0; i < ar_count - 1; i++) {
			for (int* k = ar; k < ar + ar_count - i - 1; k++) {
				if (*k < *(k + 1)) {
					int tmp = *k;
					*k = *(k + 1);
					*(k + 1) = tmp;
				}
			}
		}
	}

	int max_conti = 0;
	int conti = 0;

	for (int* k = ar; k < ar + ar_count; k++) {
		if (*k % 2 == 1) {
			conti++;
			if (max_conti < conti) {
				max_conti = conti;
			}
		}
		else {
			conti = 0;
		}
	}

	printf("%d\n", ar_count);
	for (int i = 0; i < ar_count; i++) {
		printf("%d ", *(ar + i));
	}
	printf("\n%d", max_conti);

	return 0;
}