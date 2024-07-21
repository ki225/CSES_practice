#include <iostream>
using namespace std;

void move_rings(int target, char from, char another, char to){
    if(target==1){
        cout << "Move ring " << target << " from "<< from << " to " << to << endl;
    }else{
        move_rings(target-1,from,to,another);
        cout << "Move ring " << target << " from "<< from << " to " << to << endl;
        move_rings(target-1,another,from,to);
    }
        
        
}

int main(){
    int n;
    while(cin >> n){
        move_rings(n,'A','B','C');
        cout << endl;
    }
}