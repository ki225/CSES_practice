//最長的嚴格遞增子序列

#include <iostream>
#include <vector>
using namespace std;

int arr[1000000]={0};
int dp[1000000]={0};
vector <int> tmp;
int max_dp=1;
vector <int> ans;

void LIS(int n){
    tmp.push_back(arr[0]);

    for(int i=1;i<n;i++){
        if(arr[i]>tmp.back()){
            tmp.push_back(arr[i]);
            max_dp++;
            dp[i]=max_dp;
        }else{
            auto it = lower_bound(tmp.begin(), tmp.end(), arr[i]); //在tmp找到最接近arr[i]且比他大的數值
            *it = arr[i]; //把他換成 arr[i]
            dp[i] = (int) (it - tmp.begin() + 1);
        }
            
    }
    cout << max_dp << '\n' << '-' << '\n';
    //從後往前找出最長遞增子序列的值

    for(int i=n-1;i>=0;i--){
        if(dp[i]==max_dp){
            ans.push_back(arr[i]);
            max_dp--;
        } 
    }
}


// void LIS(int n){
//     for(int i=1;i<n;i++){
//         for(int j=0;j<i;j++){
//             if(arr[j]<arr[i]){
//                 dp[i]=max(dp[i],1+dp[j]);
//                 max_dp=max(max_dp,dp[i]);
//             }
//         }
//     }
//     //從後往前找出最長遞增子序列的值
//     for(int i=n-1;i>=0;i--){
//         if(dp[i]==max_dp){
//             ans.push_back(arr[i]);
//             max_dp--;
//         } 
//     }
// }


int main(){
    int i=0;

    while(cin >> arr[i++]);
    dp[0]=1;
    LIS(i);
    reverse(ans.begin(), ans.end());
    for (auto j: ans){
        cout << j << '\n';
    }
}
