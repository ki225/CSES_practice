
#include <iostream>
#include <cstring> //memset
using namespace std;

long long min_dis[505][505],tmp3; //計算 i 到 j 的最短距離
int cityNum , roadNum , queries;

int main(){
    int tmp1,tmp2;
    cin >> cityNum >> roadNum >> queries;
    memset( min_dis , 0x3f , sizeof(min_dis) );

    for(int i=1;i<=cityNum;i++) min_dis[i][i] = 0;

    for(int i=0;i<roadNum;i++){
        cin >> tmp1 >> tmp2 >> tmp3;
        min_dis[tmp1][tmp2] = min( min_dis[tmp1][tmp2], tmp3 ); //*****
        min_dis[tmp2][tmp1] = min( min_dis[tmp2][tmp1], tmp3 );
    }

    //Floyd_Warshall
    for(int k=1;k<=cityNum;k++){
        for(int i=1 ; i<=cityNum ; i++){
            for(int j=1 ; j<=cityNum ; j++){
                min_dis[i][j] = min( min_dis[i][j] , min_dis[i][k]+min_dis[k][j] );
            }
        }
    }

    for(int i=0;i<queries;i++){
        cin >> tmp1 >> tmp2; //輸入要求哪點到哪點的距離
        if(min_dis[tmp1][tmp2] > 1e18) cout << -1 << endl;
        else cout << min_dis[tmp1][tmp2] << endl;
    }
    return 0;
}
