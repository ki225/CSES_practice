#include <iostream>
#include <stack>
#include <vector>

using namespace std;
stack <int> stk;
vector <int> vec;


int main(){
    int n,tmp;
    while(cin >> n){
        if(n==0)
            break;
        while(cin >>tmp && tmp){
            vec.push_back(tmp);
            for(int i=1;i<n;i++){
                cin >> tmp;
                vec.push_back(tmp);
            }
            int vec_index=0;
            
            for(int i=1;i<=n;i++){
                stk.push(i);
                while(!stk.empty() && stk.top()==vec[vec_index]){
                    //cout << stk.top() << endl;
                    vec_index++;
                    stk.pop();
                }
            }
            if(!stk.size())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;

            vec.clear();
        }
        
        
        
    }
}