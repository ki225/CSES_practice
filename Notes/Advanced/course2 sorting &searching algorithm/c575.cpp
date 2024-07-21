#include <iostream>
#include <vector>
using namespace std;

vector <int> vec;

int check(int len){
    int num=1; //基地台數量
    int start_pos=0;
    for(int i=0;i<vec.size();i++){
        if(vec[i]>len+vec[start_pos]){
            start_pos=i;
            num++;
        }
    }
    return num;
}

int binary_search(int l, int r, int k){
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)<=k){ //表示可以試著縮小長度
            r=mid-1;
        }else{ // 表示長度太短
            l=mid+1;
        }
    }
    return l; //合理的最小長度
}

int main(){
    int n,k,tmp;
    cin >> n >> k;
    while(n--){
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());
    int min_len=binary_search(1,vec[vec.size()-1]-vec[0],k);
    cout << min_len << endl;
}