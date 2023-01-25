//會超時

#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(){
    int x; //x代表長度
    int n; //n代表路燈數
    set <int> lightSet;//處存電燈位置
    set <int> dis; //處存每個路段的長度
    map <int ,int> map1; //計算長度為多少的路有幾條。因為set不會處存相同長度的數目
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> x >> n;
    lightSet.insert(0);
    lightSet.insert(x);
    dis.insert(x);
    map1[x]++;   

    for(int i=0;i<n;i++){
        int light;
        cin >> light;
 
        auto it = lightSet.upper_bound(light);
        int tmp =*it - *--it;
        if(map1[tmp] == 1){
            dis.erase(dis.find(tmp)); //刪除舊的距離 //此時 it=it-1，所以等等使用 it要加一
        }
        map1[tmp]--;

        tmp = light - *it++;
        dis.insert(tmp); //要扣除的數字為lower_bound 所以用原本減一後的it即可
        map1[tmp]++;

        tmp = *it-light;
        dis.insert(tmp);
        map1[tmp]++;

        cout << *dis.rbegin() << ' '; //印出距離set最後的字（也就是長度最長的）
        lightSet.insert(light);
        
    }
    return 0;
}
