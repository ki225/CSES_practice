#include <iostream>
#include <stack>
using namespace std;

int main(){
    int row,col,m,func;
    int arr[1000][1000]={0};
    int tmp_arr[1000][1000]={0};
    cin >> row >> col >> m;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> arr[i][j];
        }
    }
    stack <int> stk;
    while(m--){
        cin >> func;
        stk.push(func);
    }

    // 反向執行操作
    while(!stk.empty()){
        func=stk.top();
        stk.pop();
        // 翻轉
        if(func==1){
            for(int i=0;i<row/2;i++){
                for(int j=0;j<col;j++){
                    int tmp=arr[i][j];
                    arr[i][j]=arr[row-1-i][j];
                    arr[row-1-i][j]=tmp;
                }
            }
        }else{ // 旋轉
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    tmp_arr[col-1-j][i]=arr[i][j];
                }                  
            }
            int tmp=row;
            row=col;
            col=tmp;

            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    arr[i][j]=tmp_arr[i][j];
                }                  
            }
        }
    }
    
    cout << row << " " << col << endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }
}