#include <iostream>
#include <cmath>
using namespace std;

int a_arr[1000][1000];
int b_arr[1000][1000];
int s,t,n,m,r;
int a_sum=0;
int matrices_num=0;
int b_sum;
int min_sum=1000000;

void find_min_sum(int i, int j){
    b_sum=0;

    for(int x=i;x<s+i;x++){
        for(int y=j;y<t+j;y++){
            b_sum+=b_arr[x][y];
        }
    }
   

    min_sum=min(min_sum,abs(b_sum-a_sum));
}

void distance(int i, int j){
    int dis=0;
    int a_x=0,a_y=0;

    for(int x=i;x<i+s;x++){
        a_y=0;
        for(int y=j;y<j+t;y++){
            
            
            if(b_arr[x][y]!=a_arr[a_x][a_y])
                dis++;
            a_y++;
        }
        a_x++;
    }
    if(dis<=r){

        matrices_num++;
        find_min_sum(i,j);//從 b[i][j]開始
        
    }        
}
void make_sub(){
    for(int i=0;i<=n-s;i++){
        for(int j=0;j<=m-t;j++){
            distance(i,j);
            
        }
    }
}

int main(){
    
    cin >> s >> t >> n >> m >>r;
    for(int i=0;i<s;i++){
        for(int j=0;j<t;j++){
            cin >> a_arr[i][j];
            a_sum+=a_arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> b_arr[i][j];
        }
    }
    make_sub();
    if(!matrices_num){
        cout << matrices_num << "\n" << -1 << endl;
    }else{
        cout << matrices_num << "\n" << min_sum << endl;
    }
}