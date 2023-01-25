#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(){
    int x; //x代表長度
    int n; //n代表路燈數
    set <int> lightSet;//處存電燈位置
    multiset <int> dis; //處存每個路段的長度
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> x >> n;
    lightSet.insert(0);
    lightSet.insert(x);
    dis.insert(x);  

    for(int i=0;i<n;i++){
        int light;
        cin >> light;
        /*
        int low = *lightSet.lower_bound(light);
        int upper = *lightSet.upper_bound(light);
        */

        auto it = lightSet.upper_bound(light);
        dis.erase(dis.find(*it - *--it)); //刪除舊的距離 //此時 it=it-1，所以等等使用 it要加一
        dis.insert(light - *it++); //要扣除的數字為lower_bound 所以用原本減一後的it即可
        dis.insert(*it-light);

        cout << *dis.rbegin() << ' '; //印出距離set最後的字（也就是長度最長的）
        lightSet.insert(light);
        
    }
    return 0;
}
