#include <iostream>
using namespace std;
int main(){
    int a1,a2,b1,b2,c1,c2,n;
    int max_income=-1000;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    cin >> n;
    for(int i=0;i<=n;i++){
        //cout << a1*i*i+b1*i+c1+a2*(n-i)*(n-i)+b2*(n-i)+c2  << endl;
        max_income=max(a1*i*i+b1*i+c1+a2*(n-i)*(n-i)+b2*(n-i)+c2 , max_income);
    }
    cout << max_income << endl;
}