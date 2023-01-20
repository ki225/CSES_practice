#include <iostream>

using namespace std;

int main(){
    long n;
    cin >>n; // input the integer n
    cout << n <<' ';
    while(n!=1){
        if(n%2==0){
            n=n/2;
        }
        else if((n%2)!=0){
            n=n*3+1;
        }
        cout << n<<' ';
    }
}
