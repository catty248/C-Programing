#include <stdio.h>
#include <string.h>

void FindWord(char* c);

char word[20][201];

int main() {
	char st[201];

	gets(st);
	FindWord(st);
}