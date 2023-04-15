#include <iostream>
#include <algorithm>
using namespace std;
int dp[5005][5005]={};

int main(){
    string a, b;
    cin >> a >> b;
    
    //初始化
    for(int i=0 ; i<=a.length() ; i++){ //把最外面那層初始化
        dp[i][0] = i;
    }
    for(int j=0 ; j<=b.length();j++){
        dp[0][j] = j;
    }
    if(a[0]!=b[0]) dp[1][1] = 1;
    else dp[1][1] = 0;

    for(int i=1; i<=a.length();i++){
        for (int j =1; j<=b.length();j++){
            if(i==1 && j==1) continue;
            else if(a[i-1]!=b[j-1]){ //不同
                dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j])+1; //max,min一次只能比較兩個
            }
            else{ // 相同
                dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]+1), dp[i-1][j]+1);
               
            } 
                
        } 
    }
    cout << dp[a.length()][b.length()] << endl;
}
