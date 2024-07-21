#include <iostream>
#include <algorithm>
using namespace std;

int c[100000]={0};
int v[100000]={0};
int dp[10000]={0};

void BP01(int n,int W){
    for(int i=1;i<=n;i++){ // 遍歷每個物品
        for(int j=W;j>0;j--){ // 從大到小遍歷重量
            if(j>=v[i]) dp[j]=max(dp[j],dp[j-v[i]]+c[i]);
        }
    }
}

int main(){
    int n;
    while (cin >> n)
    {
        for(int i=1;i<=n;i++){
            cin >> v[i] >> c[i];
        }
        BP01(n,100);
        cout << dp[100] << endl;
        fill(begin(dp), end(dp), 0);
    }
    
}