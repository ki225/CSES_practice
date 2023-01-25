#include <iostream>
#define MOD 1000000007;
using namespace std;

int main(){
    //int total = 0 ;
    int n,x,ans;
    int dp[1000001];
    int c[1000001];
    cin >> n >> x; //n是金幣種類數，x是總金額
    for(int i=0;i<n;i++){ //input
        cin >> c[i];
    }
    for(int i=0;i<=x;i++){ //初始化
        dp[i] = 0;
    }
    
    for(int i=0;i<n;i++){ //basic
        dp[c[i]] = 1;
    }
    
    for(int i=0;i<x;i++){
        for(int j=0;j<n;j++){
            //cout << "dp["<<i<<"]:"<<dp[i] << endl;
            if((i+ c[j]) <= x){
                if(dp[i] !=0){
                    dp[i+ c[j]] = (dp[i+ c[j]] + dp[i]) % MOD;
                }
                //cout << i<<'+' <<c[j]<<' ';
                //cout << "*dp["<<i+ c[j]<<"]:"<<dp[i+c[j]] << endl;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}
