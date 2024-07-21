#include <iostream>
using namespace std;

int arr[9]={1,5,10,50,100,500,1000,5000,10000};

int main(){
    int n,coin_num=0;
    cin >> n;
    for(int i=8;i>=0;i--){
        if(!n)
            break;
        else if(n>=arr[i]){
            
            coin_num+=n/arr[i];
            n%=arr[i];// -=(n/arr[i])*arr[i];
            //cout <<n << endl;
        }else
            continue;
    }
    cout << coin_num << endl;
}