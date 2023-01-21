#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,now=1,times=0,size;
    vector <int> vec;
    int arr[200001]; //arr的 index值代表某個數字

    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp; 
        vec.push_back(tmp);
        arr[tmp] =i; //存放某個字的index位置
    }
    
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i+1]){
            times++;
        }
    }
    times++;
    cout << times << endl;
    return 0;
}
