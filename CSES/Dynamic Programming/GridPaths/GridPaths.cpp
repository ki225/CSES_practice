#include <iostream>
#define MOD 1000000007
using namespace std;

int main(){
    int n;
    char map1[1000][1000];
    int map2[1000][1000]; //存放方法數

    cin >> n;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ;j++){
            cin >> map1[i][j];
        }
    }
    //初始化邊界
    map2[0][0] = map1[0][0]=='.' ? 1 : 0; 
    for(int i=1 ; i<n ; i++){
        if(map1[i][0] == '.'){
            map2[i][0] = map2[i-1][0];
        }
        if(map1[0][i] == '.'){
            map2[0][i] = map2[0][i-1];
        }
    }
  //計算內部
    for(int i=1 ; i<n ; i++){
        for(int j=1 ; j<n ;j++){
            if(map1[i][j] == '.'){
                map2[i][j] = (map2[i][j-1] + map2[i-1][j]) % MOD;
            }
            else if(map1[i][j] == '*'){
                map2[i][j] = 0;
            }
        }
    }
    cout << map2[n-1][n-1] << endl;

    return 0;
}
