
#include <iostream>
#include <algorithm>
using namespace std;

int dp[5005][5005];
int findMin(int a,int b,int c);

int main(){

    string word1,word2;
    cin >> word1 >> word2;

    int length1 = word1.length();
    int length2 = word2.length();

    for(int y=0 ; y<=length1 ; y++){ //把最外面那層初始化
        dp[y][0] = y;
    }
    for(int x=0 ; x<=length2;x++){
        dp[0][x] = x;
    }

    for(int y=1 ; y<=length1 ; y++){
        for(int x=1;x<=length2;x++){
            dp[y][x]=1e9;
            if(word1[y-1] == word2[x-1]){ //判斷上一個 index值的數
                dp[y][x] = min( dp[y-1][x-1] , min(dp[y-1][x]+1, dp[y][x-1]+1) );
            }
            else{
                dp[y][x] = min( dp[y-1][x-1]+1 , min(dp[y-1][x]+1, dp[y][x-1]+1) );
            }
        }
    }
    cout << dp[length1][length2]<<endl;

    return 0;
}
