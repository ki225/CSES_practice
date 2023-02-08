#include <iostream>
using namespace std;

long long binaryexponentiation(long long base, long long ex){
    int modulo = 1e9+7;
    long long ans = 1;
    for(;ex; ex >>=1 , base = base*base%modulo){ //右移
        if(ex&1){ //如果指數是奇數
            ans = ans*base %modulo;
        }
    }
    return ans;
}

int main(){
    int num,exponent,base;
    cin >> num;
    for(int i=0;i<num;i++){
        cin >> base >> exponent;
        cout << binaryexponentiation(base , exponent)%1000000007<<endl;
    }
    return 0;
}
