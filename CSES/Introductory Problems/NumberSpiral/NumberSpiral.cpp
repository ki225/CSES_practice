#include <iostream>
#include <vector>

using namespace std;

vector <long> op_vec;

void find(long x, long y){
    long ans;
    if(x>y){
        if(x==2 && y==1){
            ans = 2;
        }
        else if(x%2 !=0){ //代表 (x,1)為最大值
            ans=x*x-(y-1);
        }
        else{ // 代表 (x,1) 為最小值
            ans=(x-1)*(x-1)+y;
        }
    }
    else if(y>=x){
        if(y%2 !=0){ //代表 (1,y)為最小值
            ans=(y-1)*(y-1)+x;
        }
        else{ // 代表 (1,y) 為最大值
            ans=y*y-(x-1);
        }
    }
    op_vec.push_back(ans);
}

int main(){
    int n_test;
    long x,y;
    cin >> n_test;

    //int arr[n_test][2];
    for(int i=0 ; i<n_test ; i++){
        //cin >> arr[i][0] >> arr[i][1];
        cin >> y >> x;
        find(x,y);
    }
    for(int i=0;i<op_vec.size();i++){
        cout << op_vec[i] << endl;
    }


    return 0;
}
