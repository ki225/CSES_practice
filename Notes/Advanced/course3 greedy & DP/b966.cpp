#include <iostream>
using namespace std;

int line[10000005]={0};

int main(){
    int n,start,end,len,max_end=0,min_start=1000000,ans=0;
    cin >> n;
    for( int i=0;i<n;i++){
        cin >> start >> end;
        max_end=max(max_end,end);
        min_start=min(min_start,start);
        
        for(int j=start+1;j<=end;j++){
            line[j]++;
        }
    }
    for(int i=min_start;i<=max_end;i++){
        if(line[i])
            ans++;
    }
    cout << ans << endl;
}