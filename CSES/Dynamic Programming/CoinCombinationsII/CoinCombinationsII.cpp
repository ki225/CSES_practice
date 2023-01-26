#include <iostream>
#define MOD 1000000007;
using namespace std;

int dp[1000005];

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,x;
    
    int tmp;
    cin >> n >> x; //n是金幣種類數，x是總金額

    dp[0] = 1; //這樣就不用處理 basic
    for(int i=0;i<n;i++){ //input
        cin >> tmp;
        for(int j=0;j+tmp<=x;j++){
            dp[j+tmp] = (dp[j+ tmp] + dp[j]) % MOD;
        }
    }
   
    cout << dp[x] << endl;
    return 0;
}
