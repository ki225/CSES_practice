#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> vec;
vector <int> cost;

int main(){
    int n,tmp;
    while(cin >> n && n){
        
        for(int i=0;i<n;i++){
            cin >> tmp;
            vec.push_back(tmp);
        }
        while(vec.size()>1){
            sort(vec.begin(),vec.end());
            vec.push_back(vec[0]+vec[1]);
            cost.push_back(vec[0]+vec[1]);
            vec.erase(vec.begin());
            vec.erase(vec.begin());
        }
        int sum=0;
        for(auto i:cost){
            sum+=i;
        }
        cout << sum << endl;
        vec.clear();
        cost.clear();
    }
}