#include <iostream>
using namespace std;

int howManyFive(int n){
    int op=0;
    while(n%5 == 0){
        n=n/5;
        op++;
    }
    return op;
}

int find_five(int n){ //照理說要找 2和 5，但有五就會有二（總而言之二會比五多），所以只要找五
    int num5=0,plus;
    while(n>=5){
        num5=num5+howManyFive(n);
        //cout << n << ' ' << num5 << endl;
        n=n-5;
    }
    return num5;
}

int main(){
    int n,ans;
    cin >> n;
    ans = find_five(n);
    cout <<ans<<endl;
}
