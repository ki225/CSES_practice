#include <iostream>
#include <vector>
using namespace std;
vector <vector<char> > map1;
vector <vector<int> > vis;
void dfs(int y, int x);
int width,length,totalRoom=0;

int main(){
    int tmp;
    cin >> width >> length; //wid是左邊的邊
    map1.resize(width+3);
    vis.resize(width+3);

    map1[0].resize(length+3);
    vis[0].resize(length+3);
    map1[width+1].resize(length+3);
    vis[width+1].resize(length+3);
    //input
    for(int i=1;i<=width;i++){
        map1[i].resize(length+3);
        vis[i].resize(length+3);
        for(int j=1;j<=length;j++){
            cin >> map1[i][j];
        }
    }
    //設定邊界
    for(int i=0;i<=1+width;i++){
        map1[i][0]='#';
        map1[i][length+1]='#';
    }
    for(int i=0;i<=1+length;i++){
        map1[0][i] = '#';
        map1[width+1][i] = '#';
    }
    for(int i=1;i<=width;i++){
        for(int j=1;j<=length;j++){
            if((map1[i][j]=='.') && (vis[i][j] == 0)){
                dfs(i,j);
                totalRoom++;
            }
        }
    }
    cout << totalRoom << endl;

    return 0;
}

void dfs(int y, int x){
    vis[y][x] = 1; //visited
    /*
    for(int i=0;i<=width+1;i++){
        for(int j=0;j<=length+1;j++){
            cout << map1[i][j];
        }
        cout <<endl;
    }
    */
    
    if((vis[y][x+1] == 0) && (map1[y][x+1]=='.')){ //right   
        dfs(y,x+1);
    } 
    if((vis[y][x-1] == 0) && (map1[y][x-1]=='.')){ //left
        dfs(y,x-1);
    }
    if((vis[y+1][x] == 0) && (map1[y+1][x]=='.')){ //up
        dfs(y+1,x);   
    }
    if((vis[y-1][x] == 0) && (map1[y-1][x]=='.')){ //down
        dfs(y-1,x);
    }
}
