#include <stdio.h>
#include <string.h>
 
//return 0 means false
 
int isSafe(int n ,char board[n][n], int r, int c)
{
    
    for (int i = 0; i < r; i++)
    {
        if (board[i][c] == 'Q') {
            return 0;
        }
    }
 
    // return 0 if two queens share the same `LEFT` diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q') {
            return 0;
        }
    }
 
    // return 0 if two queens share the same `RIGHT` diagonal
    for (int i = r, j = c; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q') {
            return 0;
        }
    }
 
    return 1;
}
 
int total_soltuion = 0;
void display(int size ,char board[size][size])
{
	printf("\n");
    for (int i = 0; i < size; i++)
    { 
        for (int j = 0; j < size; j++) {
            printf("|%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}
 
void nQueen(int n , char board[n][n] , int r  )
{
    
    if (r == n)
    {
        total_soltuion++;
        display(n ,board);
        return;
    }
 
    
    for (int i = 0; i < n; i++) // LOOP FOR COLUMN
    {
       
        if (isSafe(n,board, r, i))
        {
            
            board[r][i] = 'Q';
 
            // recursion  for the next row
            nQueen(n ,board, r + 1);
 
            // backtrack and remove the queen from the current square
            board[r][i] = ' ';
        }
    }
}
 
int main()
{
    int size;
    printf("\nEnter size of Board :");
    scanf("%d",&size);

    char board[size][size];
 
    for(int i=0; i<size; i++)
	{
        for(int j=0; j<size; j++)
		{
            board[i][j]=' ';
        }
    }
 
    nQueen( size, board, 0 );
    printf("\nTotal %d possible for %d Queen ",total_soltuion,size);
    return 0;
}