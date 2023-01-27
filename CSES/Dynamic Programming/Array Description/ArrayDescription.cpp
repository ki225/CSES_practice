
#include <iostream>
#define MOD 1000000007
using namespace std;

int stringInt[100005];
int dp[100005][105];

int main(){
    int length,choice; //表示一串字串有幾個數字；表示遇到0的時候有幾個數字選擇
    cin >> length >> choice;

    cin >> stringInt[0];
    if(stringInt[0]==0){
        for(int i=1;i<=choice;i++){
            dp[1][i] = 1;
        }
    }
    else{
        dp[1][stringInt[0]] = 1;
    }

    for(int i=1;i<length;i++){
        cin >>stringInt[i];
    }
    
    for(int i=1;i<=length;i++){
        if(stringInt[i-1]!=0){
            for(int j=0;j<=choice;j++){
                if(j!=stringInt[i-1]){
                    dp[i][j] = 0;
                }
            }
        }
        for(int j=1;j<=choice;j++){
            if(j>1){
                dp[i+1][j-1] = (dp[i+1][j-1]+dp[i][j])%MOD;
            }
            if(j<choice){
                dp[i+1][j+1] = (dp[i+1][j+1] +dp[i][j])%MOD;
            }
            dp[i+1][j] = (dp[i+1][j] + dp[i][j])%MOD;
            //dp[i][j] = dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
        }
        
    }
    //check
    /*
    for(int i=0;i<=length;i++){
        for(int j=0;j<=choice;j++){
            cout <<dp[i][j]<<' ';
        }
        cout <<endl;
    }
    */
    
    if(stringInt[length-1]!=0){
        cout << dp[length][stringInt[length-1]] << endl;
    }
    else if(stringInt[length-1]==0){
        int ans =0;
        for(int i=1 ; i<=choice ;i++){
            ans = (ans+dp[length][i])%MOD;
        } 
        cout << ans << endl;
    }
    
}
