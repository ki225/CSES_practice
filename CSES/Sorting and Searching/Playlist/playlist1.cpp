#include <iostream>
#include <vector>
using namespace std;

vector <int> vec; // 判斷下一個字有沒有和前幾個字重複

bool InOrNot(int n);

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    
    int successiveSongNum=0;
    int longestSequence=0;
    int n,tmp;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >>tmp;
        if(n == 1){
            longestSequence =1;
            break;
        }
        if(!(InOrNot(tmp))){
            successiveSongNum++;
            vec.push_back(tmp);
            if((i==n-1)&&(successiveSongNum>longestSequence)){
                longestSequence = successiveSongNum;
            }
        }
        else{
            vec.clear();
            vec.push_back(tmp);
            if(successiveSongNum>longestSequence){
                longestSequence = successiveSongNum;
            }
            successiveSongNum =1;
        }
        
    }
    cout <<longestSequence<<endl;
    return 0;
}

bool InOrNot(int n){
    bool whetherIn=false;
    for(int i=0;i<vec.size();i++){
        if(n == vec[i]){
            whetherIn = true;
            break;
        }
    }
    return whetherIn;
}
