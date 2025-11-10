#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int miller_rabin_test(long long n, long long d) {
    long long a = 2 + rand() % (n - 4);
    long long x = power_mod(a, d, n);
    if (x == 1 || x == n - 1)
        return 1;
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1) return 0;
        if (x == n - 1) return 1;
    }
    return 0;
}

int is_prime(long long n, int k) {
    if (n <= 1 || n == 4) return 0;
    if (n <= 3) return 1;
    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (int i = 0; i < k; i++)
        if (!miller_rabin_test(n, d))
            return 0;
    return 1;
}

int main() {
    long long n;
    int k = 5;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter a number to check if it is prime: ");
    scanf("%lld", &n);

    start = clock();

    if (is_prime(n, k))
        printf("%lld is a prime number.\n", n);
    else
        printf("%lld is not a prime number.\n", n);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}