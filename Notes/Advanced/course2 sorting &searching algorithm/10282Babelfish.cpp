#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main(){
    string line,a,b,target;
    map<string,string> m;
    while(getline(cin,line)){
        if(line=="")
            break;
        istringstream sin(line);
        sin >> a >> b;
        m[b]=a;
    }
    while(cin >> target){
        
        if(m.find(target)!= m.end()){
            cout << m[target] << endl;
        }else{
            cout << "eh" << endl;
        }
    }
}