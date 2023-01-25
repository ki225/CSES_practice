#include <iostream>
using namespace std;

int whichDigit(int arr[],int n);

int main(){
    int n,digits[7],totalDigits,bigNum;
    int steps = 0;
    cin >> n;
    while(n != 0){
        int target = n;
        int i = 0;
        totalDigits = 0;
        while(target > 0){
            digits[i] = target % 10;
            target = (target - (target%10)) / 10;
            i++;
            totalDigits++;
        }
        bigNum = whichDigit(&digits[0] , totalDigits); //選每個位數的數字中，數值最大的。
        n = n - bigNum;
        steps++;
    }
    cout <<steps<<endl;
    return 0;
}

int whichDigit(int arr[],int n){
    int returnValue = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] > returnValue){
            returnValue = *(arr+i);
        }
    }
    return returnValue;
}
