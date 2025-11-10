#include <stdio.h>
#include<time.h>
int main() {
clock_t start,end;
double cpu_time_used;
int n, t1 = 0, t2 = 1, nextTerm;
// Get the number of terms from the user
printf("Enter the number of terms: ");
scanf("%d", &n);
// Print the first two terms (0 and 1)
start=clock();
printf("Fibonacci Series: %d, %d", t1, t2);
// Generate and print subsequent terms
for (int i = 3; i <= n; ++i) {
nextTerm = t1 + t2; // Calculate the next term
printf(", %d", nextTerm); // Print the next term
t1 = t2; // Update t1 to the previous t2
t2 = nextTerm; // Update t2 to the newly calculated nextTerm
}
end=clock();
cpu_time_used=(double)(end-start)/CLOCKS_PER_SEC;
printf("\nExecution time:%f s",cpu_time_used);
printf("\n"); // Newline for cleaner output
return 0;
}