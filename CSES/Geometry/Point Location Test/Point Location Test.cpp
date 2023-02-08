#include <iostream>
using namespace std;

int main(){
    long long num,x1,y1,x2,y2,x3,y3;
    long long a,b,c,d;
    cin >> num;
    for(int i=0;i<num;i++){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >>y3;
        a=y2-y1;
        b=x1-x2;
        c=x2*y1-x1*y2;
        d=a*x3 + b*y3 +c;
        
        if(d == 0) cout <<"TOUCH"<< endl;
        else if(d > 0) cout <<"RIGHT"<< endl;
        else if(d < 0) cout <<"LEFT"<< endl;
    }
    return 0;
}
