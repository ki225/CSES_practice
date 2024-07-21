#include <iostream>
using namespace std;

int main(){
    int c;
    float p;
    
    while(cin >> c >> p){
        int wrapper=c,candyGet=c;
        while(wrapper>=1){
            candyGet+=(wrapper*p)/1;
            wrapper=+(wrapper*p)/1;
        }
        cout << candyGet << endl;
    }
}