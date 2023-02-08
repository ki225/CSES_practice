#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

vector < vector<int> > connect;
vector <int> connect_reverse(100005,-1);//初始化
vector <int> visit1; 
stack <int> stk;

void bfs();

int main(){
    int computerNum,connectedNum;

    cin >> computerNum >> connectedNum;
    connect.resize(computerNum+1);
    connect_reverse.resize(computerNum+1);
    visit1.resize(computerNum+1);

    for(int i=0;i<connectedNum;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        connect[tmp1].push_back(tmp2); //互相連接
        connect[tmp2].push_back(tmp1);
    }
    
    //廣度優先
    bfs();

    if(connect_reverse[computerNum] == -1){
        cout << "IMPOSSIBLE"<<endl;
        return 0;
    }

    int current_node = computerNum;
    while (current_node != -1)
    {
        stk.push(current_node);
        current_node = connect_reverse[current_node]; //求他連接的上一個
    }
    cout << stk.size() << endl;
    while (!stk.empty())
    {
        cout << stk.top()<<' ';
        stk.pop();
    }
    return 0;
}

//廣度優先

void bfs(){
    visit1[1]=1; //造訪過了， 1代表第一層
    queue <int> bfs_q; //裡面放等等要找的，也就是這一層下面連接的 //不可遍歷
    bfs_q.push(1);

    while(! bfs_q.empty()){
        int front_index = bfs_q.front(); //取出最上面的（第一個）（最早被放入的）
        bfs_q.pop(); //取出最上面的
        for(int i=0;i<connect[front_index].size();i++){ //先把同一層的都走過一次，再從每一層的元素去找更下面的
            if(!visit1[connect[front_index][i]]){
                visit1[connect[front_index][i]] = 1;
                connect_reverse[connect[front_index][i]] = front_index;
                bfs_q.push(connect[front_index][i]);
            }
        }

    }
}

