//直接解法

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,now=1,times=0,size;
    vector <int> vec;

    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp; 
        vec.push_back(tmp);
    }

    while(now <= n){
        size = vec.size()-now+1;
        for(int i=0;i<size;i++){
            //cout <<"i:"<<i<<" size:" << vec.size()<<endl;
            if(vec[i]==now){
                now++;
                //auto iter = vec.erase(vec.begin()+i);
            }
        }
        times++;
    }
    cout << times << endl;
    return 0;
}
