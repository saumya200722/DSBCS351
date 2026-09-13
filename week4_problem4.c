#include <stdio.h>

// Factorial using recursion
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// Fibonacci using recursion
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// GCD using recursion
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Sum of digits using recursion
int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int n, a, b;

    // Factorial
    printf("Enter a number for factorial: ");
    scanf("%d", &n);
    printf("Factorial = %d\n", factorial(n));

    // Fibonacci
    printf("\nEnter number of terms for Fibonacci: ");
    scanf("%d", &n);
    printf("Fibonacci series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    // GCD
    printf("\n\nEnter two numbers for GCD: ");
    scanf("%d %d", &a, &b);
    printf("GCD = %d\n", gcd(a, b));

    // Sum of digits
    printf("\nEnter a number for sum of digits: ");
    scanf("%d", &n);
    printf("Sum of digits = %d\n", sumOfDigits(n));

    return 0;
}
