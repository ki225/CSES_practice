#include <iostream>
#include <vector>
#include <cmath>
#define mod 1000000007
using namespace std;

int dp[105][605]={};

int main(){
    int n, a, b; //n代表擲 n次骰子； a, b代表擲骰子總和的範圍
    double sum=0, ans;
    cin >> n >> a >> b;

    //初始化
    for(int i = 0 ; i<=n ; i++)
        dp[i][i] = 1;

    for(int i = 1 ; i<=n ;i++){
        for(int j=1 ; j<=b ; j++){
            if(i>j) 
                continue;
            else if( i!=1 && j!=1 && dp[i-1][j-1] == 0)
                dp[i][j] = (dp[i][j-1]-1) % mod;
            else if (j>i*6)
                break;
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i][j-1]) % mod;
        }
    }
    //sum
    for(int i=a ; i<=b ; i++){
        sum +=dp[n][i];
    }
    //ans
    ans = sum / pow(6,n);
    cout << ans << endl;
   
    for(int i=0;i<=b;i++){
        for(int j=0;j<=b;j++){
            cout <<dp[i][j]<<"\t";
        }
        cout << endl;
    }
}
