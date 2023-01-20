#include <iostream>
using namespace std;

int howManyOutput(int n);
int findFirstOne(string s,int n);
void op( string s,int times, int n);

int main(){
    int n,times;
    cin >> n;

    char s[n];
    //memset( s, '9', n * sizeof(int) ); // 初始化
    times = howManyOutput(n);
    for(int i=0;i<n;i++){ //創建字串 0000 (n 個 0)
        s[i]='0';
    }

    int i=0;
    while(i<n){
        cout<<s[i];
        i++;
    }
    cout <<endl;
    
    op(s,times,n);
    return 0;
}

int howManyOutput(int n){ //計算有幾個輸出
    int ans=1;
    for(int i=0;i<n;i++){
        ans *=2;
        ans %=MOD;
    }
    return ans;
}

int findFirstOne(string s,int n){
    int whichIndex=0;
    for(int i=n-1;i>0;i--){
        if(s[i]=='1'){
            whichIndex = i;
            break;
        }
    }
    return whichIndex;
}

void op( string s,int times, int n){
    int FirstOneIndex;
    for(int i=1;i<=times-1;i++){
        if(i%2 == 0){
            FirstOneIndex=findFirstOne(s,n);
            if(s[FirstOneIndex-1]=='0'){
                s[FirstOneIndex-1] = '1';
            }
            else{
                s[FirstOneIndex-1] ='0';
            }
        }
        else{
            if(s[n-1]=='0'){
                s[n-1] = '1';
            }
            else{
                s[n-1] ='0';
            }
        }
        for(int i=0;i<n;i++){ 
            cout << s[i];
        }
        cout <<endl;
    }
}
