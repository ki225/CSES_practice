
#include <iostream>
#include <vector>
using namespace std;

vector <vector<int> > company; //裡面存 i 的下屬有誰
vector <int> subordinate; //下屬數量
void dfs(int now);

int main(){
    int num,tmp; //公司所有成員的數量
    cin >> num;
    company.resize(num+1);
    subordinate.resize(num+1);
    for(int i=2;i<=num;i++){ //第 i 個人的上司
        cin >> tmp;
        company[tmp].push_back(i); //tmp這個人有 i 這個下屬
    }
    dfs(1);
    for(int i=1;i<=num;i++){ //印出第幾個人有幾個下屬
        cout << subordinate[i] << ' ';
    }
    return 0;
}

void dfs(int now){
    if( company[now].size() == 0 ) subordinate[now] = 0;
    else{
        for(int i=0;i<company[now].size();i++){
            dfs(company[now][i]);
            subordinate[now] = subordinate[now] + subordinate[ company[now][i] ] + 1; // +1 代表 company[now][i]這個點
        }
    }

}
