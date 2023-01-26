#include <iostream>
#include <set>
using namespace std;

multiset <int> ticketPriceSet;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int ticketPriceNum,cusNum; 
    int ticketPrice,CustomerMaxPrice;

    cin >> ticketPriceNum >> cusNum;

    for(int i=0;i<ticketPriceNum;i++){ //輸入所有票價
        cin >> ticketPrice;
        ticketPriceSet.insert(ticketPrice);
    }
    ticketPriceSet.insert(-1); //作為最小的值
    for(int i=0;i<cusNum;i++){
        cin >> CustomerMaxPrice;
        auto ans_pos = ticketPriceSet.upper_bound(CustomerMaxPrice); //比期望金額大的 //找不到會回傳 end()位置（理論而言是1）
        int op = *(--ans_pos);
        cout << op << endl; //比期望金額大的前一張（就比較小或相同）
        if(op != -1)
            ticketPriceSet.erase(ans_pos); //刪除這張票
    }
}
