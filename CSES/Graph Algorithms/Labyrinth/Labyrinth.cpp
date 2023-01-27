#include <iostream>
#include <vector>
using namespace std;

char Map[1005][1005];
int height, weight;

pair <int,int> start1; //A
pair <int,int> end1; //B
vector <pair <int ,int> > path; //存放可能路徑最後一步的位置
vector <char > ans; //最後要印出的

bool valid(int x ,int y); //能不能移動到該點
int Answer(pair <int,int>end1); //整理 ans 這個vector

int main(){
    pair <int,int> start;
    bool arrive = false;  //抵達終點
    cin >> height >>weight;

    //input
    for(int i=0;i<height;i++){
        for(int j=0;j<weight;j++){
            cin >>Map[i][j];
            if(Map[i][j]=='A'){
                start1.first = j; //x座標
                start1.second = i; //y
                //Map[i][j]='.';
            }
            else if(Map[i][j]=='B'){
                end1.first = j;
                end1.second = i;
                Map[i][j]='.';
            }
        }
    }
    
    path.push_back(start1);
    while(!path.empty() && (arrive == false)){ //若vector為空則回傳true值
        
            start.first = path[0].first;
            start.second = path[0].second;
            path.erase(path.begin());

            bool haveSolution = false;
            
            bool now_deleted = false; //防止重複刪除

            if((start.first == end1.first)&&(start.second == end1.second)){
                arrive = true;
                break;
            }

            if(valid(start.first , start.second -1)){ //UP
                
                haveSolution = true;
                Map[start.second-1][start.first]='U';
                pair <int ,int> next (start.first , start.second-1) ; //宣告 pair :   pair<string,int> example1("hello",1);
                now_deleted = true;
                path.push_back(next);
                
            }
            if(valid(start.first , start.second +1)){ //Down
                haveSolution = true;
                Map[start.second+1][start.first]='D';
                pair <int ,int> next (start.first , start.second+1) ; 

                path.push_back(next);
            }
            if(valid(start.first-1 , start.second )){ //Left
                haveSolution = true;
                Map[start.second][start.first-1]='L';
                pair <int ,int> next (start.first-1 , start.second) ; 

                path.push_back(next);
            }
            if(valid(start.first+1 , start.second )){ //Right
                haveSolution = true;
                Map[start.second][start.first+1]='R';
                pair <int ,int> next (start.first+1 , start.second) ; 

                path.push_back(next);
                
            }
            
    }
    if(arrive){
        
        cout <<"YES"<<endl;
        int total = Answer(end1);
        cout <<total<<endl;
        while(ans.size()>0){
            cout << ans.back();
            ans.pop_back();
        }
        cout <<endl;
        
    }
    else if(arrive == false){
        cout << "NO" <<endl;
    }

    return 0;
}


bool valid(int x ,int y){
    if((x>=0)&&(x<weight)&&(y>=0)&&(y<height)&&(Map[y][x]=='.')){
        return true;
    }
    else{
        return false;
    }
}

int Answer(pair <int,int>end1){
    int total=0;
    pair <int,int> now; //每一步
    now.first = end1.first;
    now.second = end1.second;
    while(1){
        ans.push_back(Map[now.second][now.first]);
        total++;
        if(ans.back() == 'U'){ //要回到上一步必須往下
            now.second++;
        }
        else if(ans.back() == 'D'){ //要回到上一步必須往上
            now.second--;
        }
        else if(ans.back() == 'L'){ //要回到上一步必須往右
            now.first++;
        }
        else if(ans.back() == 'R'){ //要回到上一步必須往左
            now.first--;
        }
        if((now.first==start1.first)&&(now.second==start1.second)) break;
    }
    return total;
}
//不可以四個都用 if ，不然上一個 now更改後會到下一個去判斷
