#include <stdio.h>

int sum_between(int x, int y) {
    int sum = 0;
    for (int i = x; i <= y; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    printf("%d\n", sum_between(10, 20));
    return 0;
}
