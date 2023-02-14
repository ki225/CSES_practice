#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> tree[200010];
vector <int> level; //第i點在第幾層
int parent[200010][20]; //parent[a][b] 儲存第 a 點的前 b+1層是誰。例如level[2][0]表示 2的上一層 parent是誰

int nodes_num,queries_num;
int LCA(int x , int y);
void dfs(int node );

int main(){
    cin.tie(0), ios_base::sync_with_stdio(0);
    int tmp1,tmp2;
    cin >> nodes_num >> queries_num;
    level.resize(nodes_num+1);
 
    for(int i=0;i<nodes_num-1;i++){
        cin >> tmp1 >> tmp2;
        tree[tmp1].push_back(tmp2);
        tree[tmp2].push_back(tmp1);
    }

    parent[1][0] =0;
    level[1] = 0;

    dfs(1);
    
    // 找出每個節點的 2^i 倍祖先
    // 2^20 = 1e6 > 200000
    //建立parent的表 
    for(int i=1 ; i< 20; i++){
        for(int j=1;j<=nodes_num ;j++){
            if(parent[j][i] != 0) continue;
            parent[j][i] = parent[ parent[j][i-1] ][i-1];
        }
    }

    for(int i=0;i<queries_num;i++){
        cin >> tmp1 >> tmp2;
        cout << LCA(tmp1,tmp2) << endl;
    }
}


//用dfs遍歷整個樹，求得每個節點的層數（ level[i] ）
void dfs(int node ){ 
    for(int i=0;i<tree[node].size();i++){
        if (level[ tree[node][i] ] || tree[node][i] == 1) continue;

        level[ tree[node][i] ] = level[node]+1 ;
        parent[ tree[node][i] ][0] = node; // tree[node][i] 的父親是 node
        dfs(tree[node][i]);
    }
}


//尋找 x 和 y 的共同最近祖先（ Lowest Common Ancestor ）
int LCA(int x , int y){
    if(level[x] < level[y]) swap(x,y); //預設要把比較底層的 x用到跟上層的y同一層再進行比較。
    int level_x=level[x] , level_y = level[y]; //要儲存原本的x,y所在的層數，因為等等在浮的過程裡，x和 y會變得不一樣。

    //先把兩個一到同一層
    for(int i=19; i>=0 ;i--){
        if(level[parent[x][i]] >= level[y]){
            x = parent[x][i];
        }
    }
    if(x == y) return level_x - level_y;
    else{
        for(int i=19 ; i>=0 ;i--){
            if(parent[x][i] != parent[y][i]){
                x = parent[x][i];
                y = parent[y][i];
            }
        }
    }
    return level_x + level_y - 2*level[parent[x][0]];
}
