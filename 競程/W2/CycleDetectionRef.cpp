#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool vis[100005], nowvis[100005];
int check = 0;
vector<int> graph[100005];
stack<int> ans;

void dfs(int a){
    for(auto x:graph[a]){
        if(nowvis[x]){
            check = x;
            ans.push(x);
            ans.push(a);
            break;
        }
        else if(!vis[x]){
            nowvis[x] = true;
            vis[x] = true;
            dfs(x);
            nowvis[x] = false;
            if(check){
                if(check != -1)
                    ans.push(a);
                if(check == a)
                    check = -1;
                break;
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    while(m--){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = true;
            nowvis[i] = true;
            dfs(i);
            nowvis[i] = false;
        }
        if(check)
            break;
    }
    if(ans.size()){
        cout<<ans.size()<<"\n";
        while(!ans.empty()){
            cout<<ans.top()<<" ";
            ans.pop();
        }
    }
    else
        cout<<"IMPOSSIBLE";
}
