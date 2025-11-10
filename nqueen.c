#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#define N 4 // Change this value for different board sizes
void printSolution(int board[N][N])
{
int i,j;
for (i = 0; i < N; i++)
{
for (j = 0; j < N; j++)
{
printf("%c ", board[i][j] ? 'Q' : '.');
}
printf("\n");
} printf("\n");
}
bool isSafe(int board[N][N], int row, int col)
{
for (int i = 0; i < col; i++) // Check left
if (board[row][i])
return false;
for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) // Check upper diagonal
if (board[i][j])
return false;
for (int i = row, j = col; i < N && j >= 0; i++, j--) // Check lower diagonal
if (board[i][j])
return false;
return true;

}
bool solveNQUtil(int board[N][N], int col)
{
if (col >= N)
return true; // All queens placed
for (int i = 0; i < N; i++)
{
if (isSafe(board, i, col))
{ board[i][col] = 1; // Place queen
if (solveNQUtil(board, col + 1))
return true;
board[i][col] = 0; // Backtrack
}
}
return false;
}
void solveNQ()
{
int board[N][N] = {0};
if (!solveNQUtil(board, 0))
{
printf("Solution does not exist.\n");
return;
}
printSolution(board);
}
int main()
{
clock_t start;
clock_t end;
double cpu_time_used;
 start=clock();
solveNQ();
 end=clock();
cpu_time_used=(double)((end-start)/CLOCKS_PER_SEC);
printf("time taken by program : %f seconds",cpu_time_used);
return 0;
}