#include <iostream>
using namespace std;

void output(int n){

    for(int i=2;i<=n;i=i+2){ //偶數先
        cout << i << ' ';
    }
    for(int i=1;i<=n ;i=i+2){
        cout << i << ' ';
    }
}
    
        

int main(){
    int n;
    cin >> n;
    if(n==1){
        cout << 1 << endl;
    }
    else if(n<=3){
        cout << "NO SOLUTION"<<endl;
    }
    else{
        output(n);
    }
    return 0;
}
