#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> vec(n+1,0);
    vec[0]=1; //等於 f(0)=1

    for(int i=1;i<n+1;i++){
        for(int j=1;j<=6;j++){
            if(j>i) break;
            vec[i] = (vec[i]+vec[i-j]) % mod; //也就是 vec[i]=vec[i-1]+vec[i-2]+...+vec[i-6]
        }
    }
    cout << vec[n]<<endl;
    return 0;
}
