/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>

using namespace std;

int board[100][100];

int n;

bool isSafe(int row, int col)
{
  for(int i=row; i>=0; i--) // Check same column above
    if(board[i][col] == 1) return false;

  for(int i=row, j=col; i>=0 && j>=0; i--, j--) // check upper left diagonal
    if(board[i][j] == 1) return false;

  for(int i=row, j=col; i>=0 && j<n; i--, j++) // check upper right diagonal
    if(board[i][j] == 1) return false;

  // if no queens found, position is safe, return true
  // not checking same column down or lower diagonals because no queen placed there yet

  return true;
}

void printBoard();

bool placeQueens(int row)
{

  if(row>=n) return true;

  for(int i=0; i<n; i++){

     if(isSafe(row, i)){

        board[row][i] = 1;

        if(placeQueens(row+1))
          return true;
        else
          board[row][i] = 0;

     }

  }

  return false;
}

void printBoard()
{
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
        cout << (board[i][j]==0? "*" : "Q") << "\t";
    cout << endl;
  }

  cout << endl;
}

int main()
{
  cout << "Enter value of n for n*n board: " << endl;
  cin >> n;

  placeQueens(0);
  printBoard();

  return 0;
}
