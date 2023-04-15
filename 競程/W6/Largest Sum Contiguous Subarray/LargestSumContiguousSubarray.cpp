
#include <iostream>
#include <vector>
#include <algorithm>
#define mod 1000000007
using namespace std;

vector <int> arr1;
vector <int> arr2;//乘x

vector <int> dp1;
vector <int> dp2;

int main(){
    int n, x, tmp;
    int maxsum=0; //當maxsum<0時就歸零重算

    cin >> n >> x;
    dp1.resize(n+1);
    dp2.resize(n+1);

    for(int i=0;i<n;i++){
        cin >> tmp;
        arr1.push_back(tmp);
        arr2.push_back(tmp*x);
    }

    for(int i=1;i<=arr1.size();i++){
        maxsum = (maxsum + arr1[i-1]) % mod;
        if(maxsum<0)
            maxsum = 0;
        dp1[i] = max(dp1[i-1], maxsum) % mod;
            
    }
    maxsum=0;
    for(int i=1;i<=arr2.size();i++){
        maxsum = (maxsum + arr2[i-1])%mod;
        if(maxsum<0)
            maxsum = 0;
        dp2[i] = max(dp2[i-1], maxsum) % mod;
            
    }


    if(dp2[n]>0)
        cout << (dp1[n]+dp2[n])%mod << endl;
    else
        cout << dp1[n] << endl;

}
