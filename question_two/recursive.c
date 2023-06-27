#include <stdio.h>

int fibonacciRecursive(int n) {
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;
    else
        return fibonacciRecursive(n - 3) + fibonacciRecursive(n - 2);
}

int main() {
    int n = 10; // Change the value of n as per your requirement
    int result = fibonacciRecursive(n);
    printf("F(%d) = %d\n", n, result);
    
    return 0;
}
