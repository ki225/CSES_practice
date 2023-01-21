#include <iostream>
#include <vector>
#include <algorithm> //sort()會用到
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){ //自己定義的排序規則：比較 pair裡結束時間先後
    return (a.second<b.second);
}

int main(){
    int n;
    int movieNum=1,endTime;
    cin >> n;
    vector < pair <int,int> > intervals(n);
    for(int i=0;i<n;i++){
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin() , intervals.end(), cmp); //  排序
    endTime = intervals[0].second;
    for(int i=1;i<n;i++){
        if(intervals[i].first >= endTime){
            endTime = intervals[i].second;
            movieNum++;
        }
    }
    cout << movieNum<<endl;
    return 0;
}
