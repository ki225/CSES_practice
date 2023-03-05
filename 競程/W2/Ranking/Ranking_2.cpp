//耗費時間較多的樣子

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q, ans;

int main(){
    int teamNum , relationNum;
    cin >> teamNum >> relationNum;
    int deg[teamNum + 1] = {};
    vector<int> graph[teamNum + 1];

    //建圖
    while(relationNum--){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        deg[b]++;
    }
    
    //找第一個
    for(int i = 1; i <= teamNum; i++){
        if(!deg[i])
            q.push(i);
    }
    while(!q.empty()){
        if(q.size() != 1){
            cout<<-1;
            return 0;
        }
        int now = q.front();
        q.pop();
        ans.push(now);
        for(auto x : graph[now]){
            deg[x]--;
            if( !deg[x] )   q.push(x);
        }
    }
    if(ans.empty()) cout<<-1;
    else{
        while(!ans.empty()){
            cout<<ans.front()<<" ";
            ans.pop();
        }
    }
}
