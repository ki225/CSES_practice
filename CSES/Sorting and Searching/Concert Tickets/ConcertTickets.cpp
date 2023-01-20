#include <iostream>
#include <vector>
using namespace std;

vector <long> ticket;
vector <long> CustomerMaxPrice;
vector <long> outputVec;

void findNearest(long customer);
void rearrange(long n);

int main(){
    long n,m; //n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
    long tmp;

    cin >> n >> m;

    for(long i=0;i<n;i++){
        cin >> tmp;
        ticket.push_back(tmp);
    }
    rearrange(n);

    for(long i=0;i<m;i++){
        cin >> tmp;
        CustomerMaxPrice.push_back(tmp);
        findNearest(tmp);
    }
    for(long i=0;i<m;i++){
        cout << outputVec[i] << endl;
    }
}

void findNearest(long customer){
    long nearestIndex=-1;
    long i=0;

    while(customer >= ticket[i]){
        if(ticket[i] != 0){
            nearestIndex = i;
        }
        i++;
    }
    if(nearestIndex == -1){
        outputVec.push_back(-1);
    }
    else{
        outputVec.push_back(ticket[nearestIndex]);
        ticket[nearestIndex] = 0; //表示不存在，賣掉了
    }
}

void rearrange(long n){
    for(long i=0;i<n-1;i++){
        for(long j=0;j<n-1;j++){
            if(ticket[j]>ticket[j+1]){
                long tmp = ticket[j];
                ticket[j] = ticket[j+1];
                ticket[j+1] = tmp;
            }
        }
    }
}
