/*
吃的越慢的人要排前面一點
*/
#include <iostream>
#include <vector>
using namespace std;

vector <pair<int,int>> vec;

bool greater_cmp(const pair<int,char> a, const pair<int ,char> b) {
    if(a.first != b.first)
        return a.first>b.first; // 降冪排序
    else
        return a.second>b.second;
}

int main(){
    int n,c,e;
    int prepare=0,last_time=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> c >> e;
        vec.push_back({e,c}); //先比較吃的時間
    }
    sort(vec.begin(),vec.end(),greater_cmp);

    for(auto people:vec){
        prepare+=people.second; //準備食物的時間
        last_time=max(last_time,prepare+people.first);
    }
    cout << last_time << endl;
    
}