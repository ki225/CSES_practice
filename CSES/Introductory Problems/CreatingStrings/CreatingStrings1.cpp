#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector <char> words; //用來存放出現過的字（都只有一次）
vector <string> vec2; //用來存放排列好的字串
map <char,int> map1;

//該字母不在vec內，就加入vec。vec內放著這個字串所出現的所有字

void checkSame(string s);
void outputNum(int wholeStringLength , int diffCharNum);
//void Permutation(int n);
void swap(string originalString, int swapIndex);
bool whetherIn(string s);

int main(){
    string ipStr;
    int diffNum;
    cin >> ipStr;
    checkSame(ipStr);
    diffNum = ipStr.length() - words.size();
    outputNum(ipStr.length(),diffNum);

    swap(ipStr,0);
    return 0;
}

void checkSame(string s){
    bool inOrNot = false;
    for(int i=0;i<s.length();i++){
        for(int j=0;j<words.size();j++){
            if(words[j] == s[i]){
                inOrNot = true;
                map1[s[i]] ++;
                break;
            }
        }
        if(inOrNot == false){
            words.push_back(s[i]);
            map1[s[i]] = 1; //map內那個字只出現過一次
        }
    }
}

// print the first line
void outputNum(int wholeStringLength , int diffCharNum){
    int outputNumber=1 , divide=1;
    for(int i=0;i<words.size();i++){
        for(int j = 2 ; j <= map1[words[i]] ; j++){
            divide = divide * j;
        }
    }
    for(int i = 1 ; i<=wholeStringLength ; i++){
        outputNumber = outputNumber * i;
    }
    outputNumber = outputNumber / divide;
    cout << outputNumber << endl;
}
/*
void Permutation(int n){ 
    for(int i=0;i<n;i++){

    }
}
*/

//Permutation是排列
/*
String permutation algorithm | All permutations of a string
https://youtube.com/watch?v=GuTPwotSdYw&feature=shares
*/

void swap(string originalString, int swapIndex){
    //string front; //前面已經排序過的（如影片內綠色底線的字）
    //string newWord; //新的字
    string tmp1;
    char tmp2;
    
    for(int i=0;i<originalString.length() - (swapIndex) ;i++){ // swapIndex+1 代表第幾層
        //newWord = front + "";
        tmp1 = originalString; //儲存原本的字
        //cout <<"swap index:"<<swapIndex<<"  original: "<<originalString;////////
        //swap
        tmp2 = originalString[swapIndex];
        originalString[swapIndex] = originalString[i];
        originalString[i] = tmp2;

        //cout <<"  newOne: ";//////
        string outputString="";
        for(int j=0;j<originalString.length();j++){
            outputString=outputString+originalString[j];
        }
        if(! whetherIn(outputString)){
            cout << outputString <<endl;
            vec2.push_back(outputString);
        }

        //保留前幾位數字，挑後面的兩個數字swap。     
        if(swapIndex+1<originalString.length()){
            swap(originalString,swapIndex+1); //此時的 originalString 是 swap 過一次的
        }
        originalString = tmp1; 

    }
}

bool whetherIn(string s){
    bool InOrNot = false; //true表示在裡面
    for(int i=0;i<vec2.size();i++){
        if(s == vec2[i]){
            InOrNot = true;
            break;
        }
    }
    return InOrNot;
}

