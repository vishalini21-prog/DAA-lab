#include <stdio.h>
void insertionSort(int array[], int n) {
int i, element, j;
for(i=1;i<n;i++)
{
element=array[i];
j=i-1;
while (j >= 0 && array[j] > element)
{
array[j + 1] = array[j];
j=j-1;
}
array[j + 1] = element;
}
}
void printArray(int array[], int n)
{
int i;
for (i = 0; i < n; i++)
printf("%d ", array[i]);
printf("\n");
}
int main() {

int arr[] = {50, 23, 9, 18, 61, 32};
clock_t start,end;
double cpu_time_used;
int n = sizeof(arr) / sizeof(arr[0]);

clrscr();
printf("\nBefore sorting: ");
printArray(arr, n);
start=clock();
insertionSort(arr, n);
end=clock();
printf("\nAfter sorting: ");
printArray(arr, n);
clock_time_used=((double)(end-start))/CLOCKS_PER_SEC;
printf("time used: %f sec",clock_time_used) ;
getch();
return 0;
}