/*
  @author: Shadman Sakib
  Ahsanullah University of Science And Technology
*/
#include<iostream>

using namespace std;

int coins[] = {1, 5, 6, 8};
int money = 11;
int n = 4;

int dp[100][100];

int coinChange()
{
  for(int i=0; i<=n; i++)
    dp[i][0] = 0;

  for(int i=0; i<=money; i++)
    dp[1][i] = i;

  for(int i=2; i<=n; i++){
    for(int j=1; j<=money; j++){
        if(coins[i-1]<=j)
             dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
        else
             dp[i][j] = dp[i-1][j];
    }
  }

  return dp[n][money];
}


void printTable()
{
  cout << "Table: " << endl;
  for(int i=0; i<=n; i++){
    for(int j=0; j<=money; j++)
        cout << dp[i][j] << "\t";

    cout << endl;
  }
}

int main()
{
  cout << "Minimum number of coins needed: " << coinChange() << endl;

  printTable();

  return 0;
}
