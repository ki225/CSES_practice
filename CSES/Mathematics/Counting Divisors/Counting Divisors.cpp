#include <iostream>
#include <vector>
using namespace std;
vector <int> divisor;

void count(){
    int j;
    for(int i=1;i<=1000000;i++){ //因數為幾
        for(j=i;j<=1000000;j+=i){
            divisor[j]+=1;
        }
    }
}

int main(){
    int num,tmp;
    cin >> num;
    divisor.resize(1000000);
    count();
    for(int i=0;i<num;i++){
        cin >> tmp;
        cout << divisor[tmp]<<endl;
    }
    return 0;
}
