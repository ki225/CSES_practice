#include <iostream>
#include <vector>

using namespace std;

//vector <pair<,long long>> vec;
pair<long long,long long>arr[100000+10];

bool cmp(pair<long long,long long> a,pair<long long,long long> b){
    return a.first*b.second <a.second*b.first;
}

int main(){
    long long n,tmp;
    cin >> n;
    //vec.resize(n+1);
    for(int i=0;i<n;i++){
        cin >> arr[i].first; //weight
    }
    for(int i=0;i<n;i++){
        cin >> arr[i].second; //fetch
    } 
    sort(arr,arr+n,cmp);

    long long energy = 0,sum=arr[0].first;
    for(long long i=1;i<n;i++){
        energy+=sum*arr[i].second;
        sum+=arr[i].first;
    }
    cout << energy << endl;

}