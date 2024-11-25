#include <stdio.h>
#include <string.h>

int main() {
    char str_A[21], str_B[21], ch_A[21], ch_B[21];
    int i, j, num;

    gets(str_A);
    gets(str_B);

    for (i = 1; i <= 10; i++) {
        for (j = 0; j <= strlen(str_A); j++) {
            if (('A' <= str_A[j]) && (str_A[j] <= 'Z')) {
                if (str_B[j] == (str_A[j] + i)) {
                    ch_A[j] = (str_A[j] + i);
                }
                else {
                    break;
                }
            }
            else if (('a' <= str_A[j]) && (str_A[j] <= 'z')) {
                if (str_B[j] == (str_A[j] - i)) {
                    ch_A[j] = (str_A[j] - i);
                }
                else {
                    break;
                }
            }
            else if (('0' <= str_A[j]) && (str_A[j] <= '9')) {
                if (('0' <= str_A[j + 1]) && (str_A[j + 1] <= '9')) {
                    num = (str_A[j] - '0') * 10 + (str_A[j + 1] - '0');
                    if (str_B[j] == num + 'A') {
                        ch_A[j] = num + 'A';
                        ch_A[j + 1] = num + 'A';
                        j += 2;

                    }
                    else {
                        break;
                    }
                }
                else {
                    num = (str_A[j] - '0');
                    if (str_B[j] == num + 'A') {
                        ch_A[j] = num + 'A';
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
    puts(ch_A);

}