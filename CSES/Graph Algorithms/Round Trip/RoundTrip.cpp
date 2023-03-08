#include <iostream>
#include <vector>
using namespace std;

int cityNum,routeNum;
int start_ans=0,end_ans=0;
vector <vector<int> > route;
vector <bool> vis;
vector <int> before_vec;

bool dfs(int start,int before);
void print_ans();
bool visit_all();

int main(){
    //input
    cin >> cityNum >> routeNum;

    route.resize(cityNum+1); //resize
    vis.resize(cityNum+1);
    before_vec.resize(cityNum+1);
    
    for(int i=0;i<routeNum;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        route[tmp1].push_back(tmp2);
        route[tmp2].push_back(tmp1);
    }
  
    if(visit_all()){
        print_ans();
    }
    else{
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    return 0;
}

bool dfs(int start,int before){

    before_vec[start] = before;
    vis[start] = true;


    for(int i=0 ; i<route[start].size();i++){
        if(route[start][i] == before) {
            continue; //表示此點的上上個位置也是此點，就只是來回走而已
        }
        if(vis[route[start][i]] != 0){
            start_ans = route[start][i]; 
            end_ans = start; //若 end_ans = before_vec[route[start][i]]，且開頭為 1 ，則這邊的before[1] = -1   
            return true; //表示找到原點，即 dfs的終點。
        }
        if(! vis[route[start][i]]){ //沒到過
            if(dfs(route[start][i] , start)){ //繼續往下去找
                return true;
            }  
        }
    }   
    return false; 
}


bool visit_all(){
    for(int i=1;i<= cityNum;i++){
        if(vis[i] == 0){
            if(dfs(i,-1)){
                return true;
            }
        }
    }
    return false;
}

void print_ans(){
    vector <int>vec;

    int Num = end_ans;
    while(before_vec[Num] != start_ans){
        vec.push_back(Num);
        Num = before_vec[Num]; //得到該點的上一個位置
    }
    vec.push_back(Num); //因為第二個數字（end_ans）符合 before_vec[end_ans] == start_ans，所以不會被算進去
    vec.push_back(start_ans);

    int siz = vec.size();
    cout << siz +1 << endl; //印出長度


    for(int i=siz-1;i>=0;i--){
        cout << vec[i] << ' ';
    }
    cout << start_ans<<' '; //放進vec的第一個字是整條round最末字（最末字不等於第一個），所以要放入真正回到起點的最末字
}
