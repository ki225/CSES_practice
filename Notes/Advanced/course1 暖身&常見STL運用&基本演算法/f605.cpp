#include <iostream>
using namespace std;
int main(){
    int n,d;
    int p1,p2,p3;
    int pay=0,goods_num=0;
    cin >> n >> d;
    while(n--){
        cin >> p1 >> p2 >> p3;
        int max_price=max({p1,p2,p3});
        int min_price=min({p1,p2,p3});
        if((max_price-min_price)>=d){
            int avg=(p1+p2+p3)/3;
            pay+=avg;
            goods_num++;
        }
    }
    cout << goods_num << " " << pay << endl;
}