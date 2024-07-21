#include <iostream>
using namespace std;

string s1,s2;
int dp[1005][1005]={0};

void LCS(){
    int len1=s1.length();
    int len2=s2.length();
    fill(*dp, *dp + len1 * len2, 0);
    for(int i=1 ; i<=len1 ; i++){
        for(int j=1 ; j<=len2 ; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);       
        }
    }
    cout << dp[len1][len2] << endl;
}

int main(){
    
    while(cin >> s1 >> s2){
        LCS();
    }
}