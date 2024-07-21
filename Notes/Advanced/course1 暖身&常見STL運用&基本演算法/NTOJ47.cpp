#include <iostream>
#include <vector>
using namespace std;

vector <int> vec;
bool found;
int ans;
int left_,right_;

void binary_search(int l, int r,int target){
    while(l<=r){
        
        int middle=(l+r)/2;
        if(vec[middle]==target){
            ans=target;
            found=true;
            break;
        } 
        else if(target>vec[middle]){
            l=middle+1;
        }
        else if(target<vec[middle]){
            r=middle-1;
        }
        left_=r;
        right_=l;
    }

}

int main(){
    int n,tmp,t;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());
    cin >> t;
    while(t--){
        cin >> tmp;
        found=false;
        binary_search(0,vec.size()-1,tmp);
        if(found)
            cout << ans << endl;
        else{
            //cout << left_ << ' '<< right_ << endl;
            if(left_<vec.size() && left_>=0 && right_<vec.size() && right_>=0){
                cout << vec[left_] <<" " << vec[right_] << endl;
            }else if(left_<vec.size() && left_>=0 ){
                cout << vec[left_] <<" no"<< endl;
            }else if(right_<vec.size() && right_>=0){
                cout << "no " <<vec[right_] << endl;
            }
        }
           
    }
}