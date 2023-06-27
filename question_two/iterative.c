#include <stdio.h>

int fibonacciIterative(int n) {
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;

    int prev3 = 0, prev2 = 1, prev1 = 1, current;

    for (int i = 3; i <= n; i++) {
        current = prev3 + prev2;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

int main() {
    int n = 10; // Change the value of n as per your requirement
    int result = fibonacciIterative(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}
