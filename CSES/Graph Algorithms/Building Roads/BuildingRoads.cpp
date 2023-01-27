#include <iostream>
#include <vector>
using namespace std;

vector <vector<int> > connect; //一個小的 vector裡處存的是一組相連的城市代號
vector <int> lead; //每一組的 leader（其實也就是每一組的其中一個城市），把所有組的leader都相連就是答案
vector <bool> vis; //表示去過了沒

void dfs(int i);

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int cityNum,connectedNum;
    int total=0; //表示有幾組獨立區塊
    //input
    cin >>cityNum >>connectedNum;
    connect.resize(cityNum+1);
    vis.resize(cityNum+1);
    for(int i=0 ; i<connectedNum ; i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        connect[tmp1].push_back(tmp2); //互相連接
        connect[tmp2].push_back(tmp1);
    }

    for(int i=1;i<=cityNum;i++){
        //cout <<'*'<<i<<endl;
        if(!vis[i]){ //還沒去過
            lead.push_back(i); //把 i作為leader
            dfs(i); //把和i連接的城市都 visit過一次
            total++;
        }
    }

    cout <<total -1 <<endl; //有多少路徑
    for(int i=0;i<total-1;i++){
        cout <<lead[i]<<' '<<lead[i+1]<<endl;
    }
    return 0;
}

void dfs(int i){ 
    //cout << i<<endl;
    vis[i] = true; //表示造訪過了
    for(int j=0;j<connect[i].size();j++){ //可能這個數後面push_back很多和他相連的數字
        //cout <<connect[i][j]<<' ';
        if(!vis[connect[i][j]]){
            dfs(connect[i][j]);
        }
    }
    //cout <<endl;
}
