#include <stdio.h>
#include<time.h>
#include<stdlib.h>
void findSubset(int set[], int subset[], int n, int index, int target, int currentSum) {
int i=0;
if (currentSum == target) {
printf("Subset found: ");
for (i = 0; i < index; i++) {
printf("%d ", subset[i]);
}
printf("\n");
return;
}

if (currentSum > target || n == 0) {
return;
}


subset[index] = set[0];
findSubset(set + 1, subset, n - 1, index + 1, target, currentSum + set[0]);


findSubset(set + 1, subset, n - 1, index, target, currentSum);
}

int main() {
clock_t start,end;
int n, target,i;
int set[100],subset[100];
double cpu_time_used;
clrscr();
printf("Enter the number of elements in the set: ");
scanf("%d", &n);

printf("Enter the elements of the set: ");
for (i = 0; i < n; i++) {
scanf("%d", &set[i]);
}

printf("Enter the target sum: ");
scanf("%d", &target);

printf("Subsets with sum %d:\n", target);
start=clock();
findSubset(set, subset, n, 0, target, 0);
end=clock();
cpu_time_used=((double)(end-start)/CLOCKS_PER_SEC);
printf("time taken is:%f sec",cpu_time_used);
getch ();
return 0;
}