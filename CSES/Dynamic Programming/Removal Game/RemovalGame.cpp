#include <iostream>
#include <vector>
using namespace std;

vector <vector<long long> > dp;

int main(){
    int length;
    long long tmp,ans,sum=0;
    cin >> length;
    dp.resize(length+1);
    //input
    for(int i=0;i<length;i++){
        dp[i].resize(length+1);
        cin >> dp[i][i];
        sum = (sum + dp[i][i]) ;
    }
    for(int i=1;i<=length-1;i++){
        for(int j=0;j<length-i;j++){
            dp[j][j+i] = max( dp[j][j]-dp[j+1][j+i] , dp[j+i][j+i] - dp[j][j+i-1]) ;
        }
    }

    ans = (sum + dp[0][length-1])  / 2;
    cout << ans <<endl;
    return 0;
}
