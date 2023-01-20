#include <iostream>

using namespace std;

void rearrange(long arr[],long n){ //1d array is a pointer
    for(long j=0;j<n-1;j++){
        for(long i=0;i<n-2;i++){
            if(*(arr+i)>*(arr+i+1)){
                long temp = *(arr+i);
                *(arr+i) = *(arr+i+1);
                *(arr+i+1) = temp;
            }
        }
    }
    
}

int main(){
    long n;
    cin >>n;

    long arr[n];

    for(long i=0;i<n-1;i++){
        cin >>arr[i];
    }

    rearrange(&arr[0],n);

    if(n==2){
        if(arr[0]==n){
            cout <<1<<endl;
        }
        else{
            cout <<n<<endl;
        }
    }

    else{
        for(long i=0;i<n-1;i++){
            if((arr[i+1]-arr[i])!=1){
                cout <<arr[i+1]-1<<endl;
                break;
            }
        }
    }

    return 0;
}
