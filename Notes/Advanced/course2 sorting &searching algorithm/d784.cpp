/*
最大序列可能在左半邊、右半邊或是橫跨兩半邊

sum
max_sum
5    8   -2   9        4   -5  -8  10
 \  /      \ /          \  /    \  /
  13        9            4       10
    \      /               \   /
       20                    10   
            \               /
                    24



*/

#include <iostream>
const long long INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
int arr[200005]={0};

int maxCrossingSum(int l, int mid, int r){
    //從中間往兩側找
    long long max_left_sum=-INF,max_right_sum=-INF,sum=0;
    //左半
    for(int j=mid;j>=0;j--){
        sum+=arr[j];
        max_left_sum=max(max_left_sum,sum);
    }
    //對於右半部分X[mid+1，r]
    sum=0;
    for(int j=mid+1;j<=r;j++){
        sum+=arr[j];
        max_right_sum=max(max_right_sum,sum);
    }
    return max_left_sum+max_right_sum;
}

int getMaxSubarraySum (int l, int r){
    if (l == r)
        return arr[l];
    else{
        int mid = (l+r)/2;
        long long leftSum = getMaxSubarraySum(l, mid);
        long long rightSum = getMaxSubarraySum(mid+1, r);
        long long crossingSum = maxCrossingSum(l, mid, r);
        return max({leftSum, rightSum, crossingSum});
    }
    
}

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        cout << getMaxSubarraySum(0,n-1) << endl;
    }
    
}