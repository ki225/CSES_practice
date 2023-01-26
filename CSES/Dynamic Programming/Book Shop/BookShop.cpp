#include <iostream>
#include <algorithm> //max()
#include <vector>
#define MaxPrice 100005
using namespace std;

int dp[MaxPrice+5];

int main(){
    int n,x; //n為書籍數量，x為身上的錢
    cin >> n >> x;

    vector < pair<int ,int> > books(n); 

    for(int i=0;i<n;i++)     cin >>books[i].first;
    for(int i=0;i<n;i++)    cin >> books[i].second;

    for(int i=0;i<n;i++){
        for(int j=MaxPrice;j>=books[i].first;j--){ //避免重複運算，從尾開始執行，不需要用到前面的，只要用後面的
            dp[j] = max( dp[j-books[i].first]+books[i].second , dp[j] );
        }
    }

    cout <<dp[x]<<endl;
    return 0;
}
