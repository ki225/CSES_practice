#include <iostream>
#include <set>
#include <map>
using namespace std;

//set<int,less<int>> s; //小到大
set<int,greater<int>> s;

map <int,int> num_map{
    {1,0},
    {2,0},
    {3,0},
    {4,0},
    {5,0},
    {6,0},
    {7,0},
    {8,0},
    {9,0},
};

int main(){
    int tmp,max_ans=0;
    for(int i=0;i<3;i++){
        cin >> tmp;
        num_map[tmp]++;
        s.insert(tmp);
    }
    for(int i=1;i<=9;i++){
        max_ans=max(max_ans,num_map[i]);
    }
    cout << max_ans << " ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
}