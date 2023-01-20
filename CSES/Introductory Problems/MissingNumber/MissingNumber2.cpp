#include <iostream>
using namespace std;

int sum(int n){
    int sum1=0;
    for(int i=1;i<=n;i++){
        sum1=sum1+i;
    }
    return sum1;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    int idealTotal,actualTotal=0;
    cin >> n;
    idealTotal=sum(n); //1+2+...+n

    for(int i=0;i<n-1;i++){
        int tmp;
        cin >> tmp;
        actualTotal = actualTotal + tmp;
    }
    cout << idealTotal - actualTotal<<endl;
    return 0;
}
