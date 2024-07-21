#include <iostream>
#include <vector>
using namespace std;

vector <int> vec;

int main(){
    int n,r,tmp;
    cin >> n;
    while(n--){
        cin >> r;
        while(r--){
            cin >> tmp;
            vec.push_back(tmp); 
        }
        sort(vec.begin(),vec.end());
        int house = vec.size()/2;
        int sum=0;
        for(int i=0;i<vec.size();i++){
            sum+=abs(vec[house]-vec[i]);
        }
        cout << sum << endl;
        vec.clear();
    }
}