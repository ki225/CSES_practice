#include <iostream>
#include <vector>
#include <climits>
using namespace std;
//vector <vector<int> > dp(505,vector<int>(505,0));
int dp[505][505];
int main(){
    int x,y;
    int cutTimes=0;
    cin >> x >> y;

    //base case 
    for(int i=1;i<=x;i++){

        for(int j=1;j<=y;j++){
            if(i == j){
                dp[i][j] = 0; //表示為正方形
            }
            else {
                int minValue = INT_MAX;
                for(int k=1;k<i;k++){ //水平切 //k起始值不可以是 0，不然就會讀到dp[0][j]這種值為0的，導致數字加不起來
                    minValue =  min(dp[i-k][j]+dp[k][j] , minValue);
                }
                for(int k=1;k<j;k++){ //垂直切
                    minValue =  min(dp[i][j-k]+dp[i][k] , minValue);
                }
                dp[i][j] = minValue + 1 ;      
            }
        }
    }
    //test
    /*
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            cout << dp[i][j] << ' ';
        }
        cout <<endl;
    }
    */
    
    
    cout << dp[x][y]<<endl;
    return 0;
}
