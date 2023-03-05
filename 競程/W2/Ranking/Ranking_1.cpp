#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <vector<int>> win;
vector <int> deg;
queue <int> q;
vector <int> ans;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int teamNum , relationNum;
    cin >> teamNum >> relationNum;
    win.resize(teamNum+1);
    deg.resize(teamNum+1);

    for(int i=0,a,b ; i<relationNum ; i++){
        cin >> a >> b; //a贏b(有向)
        win[a].push_back(b);
        deg[b]++;
    }

    //找到最前面，沒有連接的（可能不只一個）    
    for(int i=1;i<=teamNum;i++){
        if(deg[i] == 0)q.push(i);
    }

    while(!q.empty()){
        if (q.size() > 1) { // 如果有多個隊伍同時排名就無法分出勝負
            cout << -1 << endl;
            return 0;
        }
        int now = q.front();
        ans.push_back(now);
        q.pop();
        for(int i : win[now]){
            deg[i]--;
            if(deg[i] == 0){
                q.push(i);
            }
        }
    }
    if (ans.size() < teamNum) { 
        cout << -1 << endl;
        return 0;
    }
    else for(int i=0;i<teamNum;i++) cout << ans[i] << ' ';
    return 0;  
}
