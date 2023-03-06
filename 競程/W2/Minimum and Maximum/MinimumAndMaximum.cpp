#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <vector<int> > road;
vector <int> dp_max;
vector <int> dp_min;
vector <int> mch_num1;
vector <int> vis;
queue <int> q;

int main(){
    int intersectionsNum , mch , roadsNum;//Mango Cake Houses
    cin >> intersectionsNum >> mch >> roadsNum;

    road.resize(roadsNum+1);
    dp_max.resize(intersectionsNum+1);
    dp_min.resize(intersectionsNum+1);
    mch_num1.resize(intersectionsNum+1);
    vis.resize(intersectionsNum+1);

    for(int i=0,tmp ; i<mch ; i++){
        cin >> tmp; //有芒果屋的路
        mch_num1[tmp]++;
    }

    for(int i=0,a,b ; i<roadsNum ;i++){
        cin >> a >> b;
        road[a].push_back(b);
    }

    //初始化 
    for(int i=2;i<=intersectionsNum;i++){
        dp_min[i] =1e9;
        dp_max[i] = -1; //初始化不能是零，不然會卡在 test2
    }
    dp_min[1] = mch_num1[1];
    dp_max[1] = mch_num1[1];

    //求最小
    //dijkstra
    priority_queue < pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq_min;
    pq_min.push({mch_num1[1],1});
    while(!pq_min.empty()){

        auto now = pq_min.top();  pq_min.pop();
        vis[now.second] = 1;

        if(now.second == intersectionsNum) break; //找到解
        for(int i=0;i<road[now.second].size();i++){
            auto next = road[now.second][i];
            
            if( !vis[next] && dp_min[next] > dp_min[now.second] + mch_num1[next]){
                dp_min[next] = dp_min[now.second] + mch_num1[next];
                pq_min.push({dp_min[next] , next});
            }
        }
    }

    //求最大 bfs
    queue <int> q;
    q.push(1);
    while(!q.empty()){
        auto now = q.front(); q.pop();
        for(auto next:road[now]){
            if(dp_max[next] < dp_max[now] + mch_num1[next]){
                dp_max[next] = dp_max[now] + mch_num1[next];
                q.push(next);
            }
        }
    }
    
    cout << dp_min[intersectionsNum] << ' ' << dp_max[intersectionsNum] << endl;
    return 0;
}
