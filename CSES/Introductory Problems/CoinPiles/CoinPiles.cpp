#include <iostream>
using namespace std;

int main(){
    int n;

    cin >>n;

    int arr[2][n];

    for(int i=0;i<n;i++){
        cin >> arr[0][i] >> arr [1][i];
    }
    for(int i=0;i<n;i++){
        if(arr[1][i]>2*arr[0][i] || arr[0][i]>2*arr[1][i]){
            cout << "NO"<<endl;
        }
        else{
            if((arr[1][i]%3==1 && arr[0][i]%3==2) || (arr[1][i]%3==2 && arr[0][i]%3==1) ||(arr[1][i]%3==0 && arr[0][i]%3==0)){
                cout <<"YES"<<endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
