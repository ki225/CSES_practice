//直接解法

#include <iostream>
using namespace std;

int main(){
    int n,remainPeople,p[200000],count;
    cin >> n;
    remainPeople = n;

    for(int i=1;i<=n;i++){
        p[i] =1;
    }
    count = 1;
    while(remainPeople > 0){
        for(int i=1;i<=n;i++){
            if((p[i]==1) && (count==2)){
                //cout <<"aa"<<endl;
                remainPeople--;
                p[i] = 0;
                count = 1;
                cout << i <<' ';
                if(remainPeople == 0) {
                    break;
                }
            }
            else if((p[i]==1) && (count!=2)){
                //cout <<"bb"<<endl;
                count++;
            }
            
        }
    }
    return 0;
}
