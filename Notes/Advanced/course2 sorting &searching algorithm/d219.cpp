/*
7%5=2
7^2%5=4=(7%5)^2

7^3%5=343%5=3
(7%5)^3%5=8%5=3

*/

#include <iostream>
using namespace std;

int b,p,m;

int mul(int pp){
    if(pp==1)
        return b%m;
    if(pp%2==1)
        return (mul(pp/2)*mul(pp/2+1))%m;
    else
        return (mul(pp/2)*mul(pp/2))%m;
}

int main(){
    while(scanf("%d\n%d\n%d", &b, &p, &m) != EOF){
        b%=m;
        cout << mul(p) << endl;
    }
}