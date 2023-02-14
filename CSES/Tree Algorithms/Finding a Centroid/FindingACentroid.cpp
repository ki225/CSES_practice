#include <iostream>
#include <vector>
using namespace std;
vector <vector <int> > tree;
vector <int> sub_tree; //處存以 i 為中心點時，樹結點為多少
vector <int>  max_sub_tree_node;
vector <int> vis;
int num;
bool find_the_ans = false;
void dfs(int now , int parent);

int main(){
    int tmp1,tmp2;
    
    cin >> num;
    tree.resize(num+1);
    vis.resize(num+1);
    max_sub_tree_node.resize(num+1);
    sub_tree.resize(num+1);

    for(int i=0;i<num-1;i++){
        cin >> tmp1 >> tmp2;
        tree[tmp1].push_back(tmp2);
        tree[tmp2].push_back(tmp1);
    }
    dfs(1,0);

    return 0;
}

//用dfs去得知下面節點連接的情況
//用dfs要注意的是，很多指令要在呼叫函式之前執行，不然呼叫下一個函式的時候，前面的數據都為0
void dfs(int now , int parent){
    
    for(int i=0;i<tree[now].size();i++){
        if(tree[now][i] == parent) continue; //往回判斷

        dfs(tree[now][i] , now);
        max_sub_tree_node[now] = max( max_sub_tree_node[now] , sub_tree[tree[now][i]] ); //「 sub_tree[tree[now][i]] 」代表 now 這個節點的某一個子樹分支大小
        sub_tree[now] = sub_tree[now] + sub_tree[tree[now][i]]; //放到函式後面是因為要在最後一個開始往回加
    }

    sub_tree[now]++; //當前節點（包含本身的意思）
    max_sub_tree_node[now] = max( max_sub_tree_node[now] , num-sub_tree[now] ); //要放在「 sub_tree[now]++; 」後面，因為「 num-sub_tree[now] 」代表的子樹不包含本身（要扣除）。

    if(( max_sub_tree_node[now] <= num/2 ) && ( !find_the_ans )){ //扣掉一是為了扣掉自己
        find_the_ans = true;
        cout << now << endl;
    }
}
