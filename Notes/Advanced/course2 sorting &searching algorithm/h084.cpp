#include <iostream>
#include <vector>
using namespace std;

vector <long long> woods;
vector <long long> papers;
long long n,k,tmp,max_len=0;

// bool check(long long h){
//     int len=0,target_index=0;
//     for(auto i:woods){
//         if(target_index==papers.size())
//             return true;
//         if(i<h){
//             len=0;
//             //cout <<h << " " << i << endl;
//         }else{
//             len++;
//             if(len==papers[target_index]){
//                 target_index++;
//             }
            
//         }
//     }
  
//     return false;
// }

bool check(int h){
    vector<int>v;
    int tmp=0;
    // 連續大於h高度的木頭長度
    for(int i=0;i<n;i++){
        if(woods[i]>=h)tmp++;
        else{
            if(tmp!=0){
                v.push_back(tmp);
                tmp=0;
            }
        }
    }
    if(tmp!=0)v.push_back(tmp);
    // 貼海報
    int cnt=0; //貼幾張海報
    for(int i=k-1;i>=0&&v.size();i--){
        if(v.back()>=papers[i]){
            v.back()-=papers[i];
            cnt++;
            if(v.back()==0)v.pop_back();
        }
        else{
            while(v.back()<papers[i]&&v.size())
                v.pop_back();
            i++;
        }
    }
    return cnt==k;
}

long long binary_search(long long l, long long r){
    long long mid;
    while(l<=r){
        mid =(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    if(check(l))
        return l;
    else 
        return r;
    //return (l+r)/2;
}

int main(){
    
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> tmp;
        max_len=max(max_len,tmp);
        woods.push_back(tmp);
    }
    for(int i=0;i<k;i++){
        cin >> tmp;
        papers.push_back(tmp);
    }
    //cout << max_len << endl;
    cout << binary_search(1,max_len) << endl;
}