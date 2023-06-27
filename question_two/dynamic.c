#include <stdio.h>

int fibonacciDP(int n) {
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;

    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;

    for (int i = 3; i <= n; i++)
        fib[i] = fib[i - 3] + fib[i - 2];

    return fib[n];
}

int main() {
    int n = 10; // Change the value of n as per your requirement
    int result = fibonacciDP(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}
