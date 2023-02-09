
#include <iostream>
#include <vector>
using namespace std;

vector <int> dp; //表示index為i時的最大長度為幾
vector <int> pc; //potential candidates pc[i]代表長度為i時的數字
int max_len=1;

int compare(int n){
    int return_val = 0;
    for(int i=max_len ; i >= 1 ; i--){
        if(n>pc[i]){
            return_val = i;
            break;
        }
    }
    return return_val; // 回傳長度值（比哪個長度的數字大） （pc index）
}

int main(){
    int tmp;
    int sequence_len;
    
    cin >> sequence_len;
    dp.resize(sequence_len + 1);
    pc.resize(sequence_len + 1);

    cin >> tmp;
    dp[0] = max_len;
    pc[max_len] = tmp;

    for(int i=1;i<sequence_len;i++){
        
        cin >> tmp;
        
        if(compare(tmp) == 0){ //表示最小
            pc[1] = tmp;
        }
        else if(compare(tmp) == max_len){
            max_len = max_len + 1;
            pc[max_len] = tmp; //pc[max_len+1]的位置為tmp，同時 max_len = max_len+1
        }
        else{ //不是最大長度，而是卡在中間
            pc[ compare(tmp)+1 ] = tmp;
        }
        dp[i] = max_len;
    }

    cout << dp[sequence_len-1]<<endl;

    return 0;
}
