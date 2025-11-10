#include <stdio.h>
#include<conio.h>
#include <time.h>

int recursiveBinarySearch(int arr[], int low, int high, int key) {
int mid;
if (high < low)
return -1;
mid = low + (high - low) / 2;
if (arr[mid] == key)
return mid;

else if (arr[mid] > key)
return recursiveBinarySearch(arr, low, mid - 1, key);

else
return recursiveBinarySearch(arr, mid + 1, high, key);
}

int main() {
int n = 1000,i,key=999,result;
clock_t start,end;
double cpu_time_used;

int arr[1000];
clrscr();
for (i = 0; i < n; i++) {
arr[i] = i;
}
start = clock();
result = recursiveBinarySearch(arr, 0, n - 1, key);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
if (result != -1)
printf("Element found at index %d\n", result);
else
printf("Element not found\n");
printf("Execution time: %f seconds\n", cpu_time_used);
getch();
return 0;
}