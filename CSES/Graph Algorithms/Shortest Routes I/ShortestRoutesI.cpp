#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <vector<pair<int,int> > > len; //len[a]={ {b,c} } 表示 a 到 b 的距離為c
vector <long long> dis; //第一個城市到其他城市的距離
void dijkstra();

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    long long tmp1,tmp2,tmp3;
    int flightConnections,cityNum;

    cin >> cityNum >> flightConnections;
    len.resize(cityNum+1);
    dis.resize(cityNum+1);

    for(auto i = 0; i <= cityNum; ++i)
	{
		dis[i] = 1e17;
	}
    //不要用 vector <long long> dis(1000000,1e17) ;

    for(auto i=0;i<flightConnections;i++){
        cin >> tmp1 >> tmp2 >> tmp3;
        len[tmp1].push_back( {tmp2,tmp3} ); //不用len[tmp1][tmp2] = tmp3，因為同樣一個點到另一個點可能有多個距離
    }

    dijkstra();

    for(auto i=1;i<=cityNum;i++) cout << dis[i] <<' ';
}

void dijkstra(){
    dis[1]=0;//一到一的距離是零

    priority_queue< pair<long long,int> , vector<pair<long long,int> >, greater<pair<long long,int> > > pq; //前者放距離，後者放目的地
    pq.push( make_pair(0,1)); //因為元素為pair時，比較的時候是比較first的元素
    while(! pq.empty()){
        auto now = pq.top();
        pq.pop();

        if(now.first > dis[now.second]) continue; //如果 1~該點（now.second）的路徑長大於 1~該點（now.second）的最短距離
        for(auto i : len[now.second]){
            if(dis[i.first] > i.second + dis[now.second]){
                dis[i.first] = i.second + dis[now.second] ;
                pq.push( {dis[i.first] , i.first} );
            }
        }
    }
}
