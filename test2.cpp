#include <stdio.h>

int main()
{
    int depth, num;

    scanf("%d", &num);

    while (scanf("%d%d", &depth, &num) == 2) {
        int k = 1;

        for (int d = 0; d < depth - 1; d++) {
            if (num % 2) {
                k *= 2;
                num = (num + 1) / 2;
            }

            else {
                k = (k * 2) + 1;
                num /= 2;
            }
        }

        printf("%d\n", k);
    }
}