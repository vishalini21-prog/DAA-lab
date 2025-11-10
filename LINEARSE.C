#include<stdio.h>
#include<conio.h>
#include<time.h>
int main(){
clock_t start,end;
double cpu_time_used;
int n=2000,i=0,key=999;
int a[10000];
clrscr();
start=clock();
for(i=0;i<n;i++){
a[i]=i;}
for(i=0;i<n;i++){
if(a[i]==key){
printf("value found at index : %d",i);
}}
end=clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
printf("\nExecution time:%f seconds",cpu_time_used);
getch();
return 0;
}