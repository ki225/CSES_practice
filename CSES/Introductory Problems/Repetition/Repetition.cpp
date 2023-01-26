#include <iostream>
#include <vector>

using namespace std;
vector <long> ContiLength;

void findContinuous(string words){
    int count=1,i=0;
    for(i=0;i<words.length()-1;i++){
        if(words[i]==words[i+1]){
            count++;
        }
        else if (words[i]!=words[i+1]){
            ContiLength.push_back(count);
            count=1;
        }
    }
    if(count!=1){
        ContiLength.push_back(count);
    }
}

int main(){
    string DNASequence;
    int DNALength;
    int maxConti;

    cin >> DNASequence;
    if(DNASequence.length()==1){
        cout <<1<<endl;
    }
    else{
        findContinuous(DNASequence);

        DNALength = DNASequence.length();

        maxConti = ContiLength[0];
        for(int i=1;i<ContiLength.size();i++){
            if(ContiLength[i]>maxConti){
                maxConti = ContiLength[i];
            }
        }
        cout << maxConti<<endl;
    }
    

    return 0;
}
