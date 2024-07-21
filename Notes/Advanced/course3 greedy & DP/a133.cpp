#include <iostream>
#include <cstring>
using namespace std;

int tower1[105]={0};
int tower2[105]={0};
int dp[105][105]={0};

int LCS(int n, int m){
  //memset(dp, 0, sizeof(dp));
  fill(*dp, *dp + n * m, 0);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
        if(tower1[i] == tower2[j]) 
            dp[i][j] = dp[i - 1][j - 1] + 1;
        else 
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[n][m];
}

int main(){
    int N1,N2,towerNum=1;
    while(cin >> N1 >> N2){
        if(!N1&&!N2)
            break;
        for(int i=1;i<=N1;i++){
            cin >> tower1[i];
        }
        for(int i=1;i<=N2;i++){
            cin >> tower2[i];
        }
        //LCS
        // for(int i=1 ; i<=N1 ; i++){
        //     for(int j=1 ; j<=N2 ; j++){
        //         if(tower1[i-1] == tower2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        //         else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);       
        //     }
        // }
        cout << "Twin Towers #" << towerNum++ << '\n';
        cout <<"Number of Tiles : " << LCS(N1,N2) << '\n';
        //
        //fill(begin(dp), end(dp), 0)
    }
}