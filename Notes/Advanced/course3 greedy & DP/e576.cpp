#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    int target,num1,num2;
    int now_r,last_r,use_num;
    cin >> n;
    while(n--){
        use_num=0;
        vector <pair<int,int>> lines;
        vector <pair<int,int>> uses;
        cin >> target;
        while(cin >> num1 >> num2){
            if(num1==0 && num2==0)
                break;
            lines.push_back({num1,num2});
        }

        sort(lines.begin(),lines.end());

        last_r=now_r=0;
        int index=0;
        while(index<lines.size() && now_r<target){
            while(index<lines.size() && lines[index].first<=last_r){
                if(lines[index].second>now_r){
                    last_r=now_r;
                    now_r=lines[index].second;  
                }
                if(now_r>=target)
                    break;
                index++; 
                
            }
            use_num++;
            uses.push_back(lines[index++]);
        }
      

        if(now_r<target)
            cout << 0 << endl;
        else{
            cout << use_num << endl;
            for(auto line : uses)
                cout << line.first << " " << line.second << endl;
        } 
        if(n)
            cout << endl;
    }
}