#include <iostream>
using namespace std;

int whichFive(int n , int power){
    int divide=1,i=1;
    while(i<=power){
        divide=divide*5;
        i++;
    }
    return (n-(n%divide))/divide;
}

int find_five(int n){ //照理說要找 2和 5，但有五就會有二（總而言之二會比五多），所以只要找五
    int num5=0,tmp=5,highest=0,i=1;
    while(n>=tmp){
        tmp = tmp*5;
        highest++;
    }
    while(i <= highest){
        num5=num5+whichFive(n , i);
        i++;
    }
    return num5;
}

int main(){
    int n,ans;
    cin >> n;
    ans = find_five(n);
    cout <<ans<<endl;
}
