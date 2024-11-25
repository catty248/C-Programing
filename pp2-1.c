#include <stdio.h>
#include <string.h>

int main() {
	char st[100][101];
	int min_index = 0;

	for (int i = 0; i < 100; i++) {
		scanf("%s", st[i]);
		if (strcmp(st[min_index], st[i]) >= 0) {
			min_index = i;
		}
	}

	printf("%s", st[min_index]);
}