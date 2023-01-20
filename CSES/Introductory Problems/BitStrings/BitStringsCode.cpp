#include <iostream>
#define MOD 1000000007

using namespace std;

int main(){
    int n,ans=1;
    cin >> n;
    for(int i=0;i<n;i++){
        ans *=2;
        ans %=MOD;
    }
    cout << ans;
    return 0;
}
