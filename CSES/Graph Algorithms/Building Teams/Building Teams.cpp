
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector < vector<int> > relation; //朋友關係
vector <int> vis; //表示查過與否
vector <int> group;

bool dfs(int start ,int groupNum ,int before);
int pupilsNum,relationNum;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int tmp1,tmp2;
    cin >> pupilsNum >> relationNum;

    relation.resize(pupilsNum+1); //卡超久結果是忘記加一
    vis.resize(pupilsNum+1);
    //cout << vis.size()<<endl;
    group.resize(pupilsNum+1);

    for(int i=0;i<relationNum;i++){
        cin >> tmp1 >> tmp2;
        relation[tmp1].push_back(tmp2);
        relation[tmp2].push_back(tmp1);
    }
    for(int i=1;i<=pupilsNum;i++){  //vector 不會自動初始化為零
        vis[i] = 0;
        group[i] = 0;
    }
    for(int i=1;i<=pupilsNum;i++){
        if(!vis[i]){
            //cout <<"oooooooo"<<i<<endl;
            if(! dfs(i,1,-1)){ //before為-1就確保不會重複
                cout << "IMPOSSIBLE" <<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=pupilsNum;i++){
        cout <<group[i]<<' ';
    }
    return 0;
}


bool dfs(int start ,int groupNum ,int before){
    vis[start] = 1;
    group[start] = groupNum;
    int nextGroupNum=0;
    if(groupNum == 1){
        nextGroupNum = 2;
    }
    else if(groupNum == 2){
        nextGroupNum = 1;
    }
 
    for(int i=0;i<relation[start].size();i++){
        if(relation[start][i] == before) 
            continue;//C++ 中的continue 语句有点像break 语句。 但它不是强迫终止，continue 会跳过当前循环中的代码，强迫开始下一次循环。

        if(group[relation[start][i]] == 0){ //不可以用 vis[start][i] ==0 
            if(! dfs(relation[start][i] , nextGroupNum , start)){
                return false;
            }
        }
        if(group[relation[start][i]] == group[start]){ //和朋友相同組別
            return false;
        }
    }

    return true;
}

/*
注意
for(int i=0;i<relation[start].size();i++){
        if(relation[start][i] == before) continue;//C++ 中的continue 语句有点像break 语句。 但它不是强迫终止，continue 会跳过当前循环中的代码，强迫开始下一次循环。
    
        if(group[relation[start][i]] == 0){ //不可以用 vis[start][i] ==0 
            if(! dfs(relation[start][i] , nextGroupNum , start)){
                cout <<"A"<<endl;
                return false;
            }
        }
        cout << relation[start][i] <<' '<<"start:"<<start<<endl;
        if(group[relation[start][i]] == group[start]){ //和朋友相同組別
        cout <<"B"<<endl;
            return false;
        }
    }
}

check那行會輸出
2 start:1
3 start:1
1 start:2 (重複)
B
ＩＭＰＯＳＳＩＢＬＥ
*/
