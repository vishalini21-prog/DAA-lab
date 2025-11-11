#include <stdio.h>
#include <time.h>
#include <conio.h>

// On Turbo C++, CLK_TCK must be used
#ifndef CLK_TCK
#define CLK_TCK 18.2
#endif

// Function to find the maximum of two integers
int maximum(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem with a static array
int knapsack(int W, int wt[], int val[], int n) {
    // Corrected: All variables declared at the top of the function
    int i, w;
    // Note: Statically allocated 2D array, size must be constant
    int knap[4][51];

    // Build the knap table in a bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                knap[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                knap[i][w] = maximum(val[i - 1] + knap[i - 1][w - wt[i - 1]], knap[i - 1][w]);
            } else {
                knap[i][w] = knap[i - 1][w];
            }
        }
    }
    return knap[n][W];
}

// Driver code to test the knapsack function
void main() {
    // Corrected: All local variables declared first
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = 3; // Fixed item count for static array
    int result;
    clock_t start, end;
    float cpu_time_used;

    clrscr();

    // Now, all executable statements follow the declarations
    start = clock();
    result = knapsack(W, wt, val, n);
    end = clock();
    cpu_time_used = (float)(end - start) / CLK_TCK;

    printf("The maximum value that can be put in the knapsack is: %d\n", result);
    printf("Execution time: %f seconds\n", cpu_time_used);

    getch();
}
