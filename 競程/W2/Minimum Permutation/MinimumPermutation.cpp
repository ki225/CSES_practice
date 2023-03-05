#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <vector<int>> adj;
vector <int> deg;
priority_queue <int,vector<int> , greater<int> > pq; 
vector <int> ans;

int main(){
    int permutationsNum , limitNum;
    cin >> permutationsNum >> limitNum;
    adj.resize(permutationsNum+1);
    deg.resize(permutationsNum+1);

    for(int i=0,a,b ; i<limitNum ; i++){
        cin >> a >> b; //a贏b(有向)
        adj[a].push_back(b);
        deg[b]++;
    }

    //找到最前面，沒有連接的（可能不只一個）    
    for(int i=1;i<=permutationsNum;i++){
        if(deg[i] == 0)pq.push(i);
    }

    while(!pq.empty()){
        if(ans.size()>permutationsNum) break;
        int now = pq.top();
        ans.push_back(now);
        pq.pop();
        
        for(int i : adj[now]){ 
            deg[i]--;
            if(deg[i] == 0){
                pq.push(i);
            }
        }
    }
    if(ans.size() != permutationsNum) cout <<-1<<endl;
    else  for(int i=0;i<permutationsNum;i++) cout << ans[i] << ' ';
    return 0;  
}
