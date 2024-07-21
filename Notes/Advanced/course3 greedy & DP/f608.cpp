/*
非嚴格遞增 ---> upper bound
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int,int>> map;
vector <int> ans;

bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first)
        return a.first<b.first;
    else
        return a.second<b.second;
}

int main(){
    int n,x,y;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        map.push_back({x,y});
    }
    sort(map.begin(),map.end(),cmp);
    
    for(auto point:map){
        auto it = upper_bound(ans.begin(), ans.end(), point.second); //大於 map[i].y的第一個值的位置
        if(ans.empty())
            ans.push_back(map[0].second); //最近的點
        else if ( it == ans.end()) { //找不到
            ans.push_back(point.second);
        } else {
            ans[it - ans.begin()] = point.second; //讓數值變小，可以串接更多點
        }
    }
    
    cout << ans.size() << endl;
}