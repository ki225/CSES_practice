#include <iostream>
#include <vector>
#include <climits> //INT_MAX 和 INT_MIN 的標頭檔 
using namespace std;

int main(){
    long long dp[1000001];
     
    dp[0] = 0; //零元的排列方法只有零個
    int n,x,total;

    cin >>n; //硬幣幾種
    cin >>total;

    vector <int> c(n);

    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    for(int i=0;i<=total;i++){  //存放多少錢時最少硬幣數，用大值初始化，等等取小的 
        dp[i] = INT_MAX; //INT_MAX為2^(31) - 1
    }
    for(int i=0;i<n;i++){ //先處理 basic 情況
        dp[c[i]] =1;
    }
    for(int i=1;i<=total;i++){ //利用迴圈從 1元往上找到所求的金額，保證每個金額都有答案
        for(int j=0;j<n;j++){
            if (i-c[j] >=0){
                dp[i] = min(dp[i],dp[i-c[j]] +1); //多加的一就是c[j]額度的coin
            }
        }
    }
    
    if(dp[total]==INT_MAX){ //無法排列
        cout << -1 << endl;
    }
    else{
        cout << dp[total]<<endl;
    }
    
    
    return 0;
}
