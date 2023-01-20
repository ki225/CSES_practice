#include <iostream>
#include <vector>
#include <map>
#include <cstring> //memset
using namespace std;

map <char,int> map1;
vector <char> vec1;

bool findInOrNot(char c);
void ifOdd(string s);
void ifEven(string s);
void putInVecMap(string s);
void rearrange(string s,char whichIsOdd);

int main(){
    string inputString;
    cin >> inputString;

    if(inputString.length()%2 != 0 ){ //奇數個字母只能出現一種字母有奇數個
        putInVecMap(inputString);
        ifOdd(inputString);
    }
    else{ //偶數個的話，所有字母都只能有偶數個
        putInVecMap(inputString);
        ifEven(inputString);
    }
    return 0;
}

void putInVecMap(string s){
    //存入map vector方便判斷
    int tmp1 = s.length();
    for(int i=0;i<tmp1;i++){
        if(findInOrNot(s[i])){
            map1[s[i]] ++;
        }
        else{
            vec1.push_back(s[i]);
            map1[s[i]] = 1 ;
        }
    }
}

//判斷有沒有解法 ---> 如果有超過一個奇數個字母，就沒有了
void ifOdd(string s){
    int oddWord=0;
    char whichIsOdd; //若有奇數個字母牌在一起，則中間那個字一定是奇數個的
    bool haveSolution = true;

    int tmp1 = vec1.size();
    for(int i=0;i<tmp1;i++){
        if(map1[vec1[i]]%2 !=0){
            oddWord++;
            whichIsOdd = vec1[i];
        }
        if(oddWord>=2){
            haveSolution = false;
            cout << "NO SOLUTION" << endl;
            break;
        }
    }
    if(haveSolution){
        rearrange(s , whichIsOdd);
    }
}

void ifEven(string s){
    int tmp1 = vec1.size();
    bool haveSolution = true;
    for(int i=0;i<tmp1;i++){
        if(map1[vec1[i]]%2 !=0){
            haveSolution = false;
            cout << "NO SOLUTION" << endl;
            break;
        }       
    }
    if(haveSolution){
        rearrange(s , '0');
    }
}

bool findInOrNot(char c){
    bool InOrNot = false;
    int tmp1 = vec1.size();
    for(int i=0;i<tmp1;i++){
        if(c == vec1[i]){
            InOrNot = true;
            break;
        }
    }
    return InOrNot;
}

void rearrange(string s,char whichIsOdd){ //如果都沒有 whichIsOdd 就是 '0'
    int middleIndex,whichWord=0;
    int tmp1 = vec1.size();
    int tmp2 = s.length();
    //cout << tmp1 <<' '<< tmp2;
    char outputString[tmp2];
    memset( outputString, '0', tmp2 * sizeof(int) ); // 初始化

    for(int i=0;i<tmp1-1;i++){
        for(int j=0;j<tmp1-1;j++){
            if(vec1[j]>vec1[j+1]){ //把 vector 內的字母按順序排一次
                char tmp = vec1[j];
                vec1[j] = vec1[j+1];
                vec1[j+1] = tmp;
            }
        }
    }

    if(s.length()%2!=0){
        middleIndex = (tmp2-1)/2; 
        whichWord =0;
        //cout <<whichIsOdd<<endl;
        for(int i=0;i<= middleIndex;i++){
            //cout <<'i'<<i<<' ';
            //cout <<"vec1[whichWord]"<<vec1[whichWord]<<' ';
            //cout <<"map1[vec1[whichWord]]"<<map1[vec1[whichWord]]<<endl;
            
            if((whichWord==0)&&(map1[vec1[whichWord]]<2)){
                whichWord++;
            }
            if(map1[vec1[whichWord]]>=2){
                outputString[i] = vec1[whichWord];
                outputString[tmp2-1-i] = vec1[whichWord];
                map1[vec1[whichWord]] = map1[vec1[whichWord]] - 2;
            }
            else if((vec1[whichWord] == whichIsOdd) && (i==middleIndex)){ //map1[vec1[whichWord]] == 1
                outputString[i] = vec1[whichWord];
            }
            if(i == middleIndex){
                outputString[i] = whichIsOdd;
            }
            if((map1[vec1[whichWord]]<2) && ((i+1)!=middleIndex)){ //不用 else if 的原因是：用 else if 的話，就不能及時更改下一個要排進 outputString 的字母，而是要再跑一次回圈來判斷，但不執行動作而浪費一個 i 的位置（ i 還是會 +1 但裡頭沒放東西）
                whichWord++; //表示要排列下一個字
            }
            
        }
    }
    else{
        for(int i=0;i<= (tmp2/2);i++){
            if(map1[vec1[whichWord]]>=2){
                outputString[i] = vec1[whichWord];
                outputString[tmp2-1-i] = vec1[whichWord];
                map1[vec1[whichWord]] = map1[vec1[whichWord]] - 2;
            }
            if(map1[vec1[whichWord]]<2){
                whichWord++; //表示要排列下一個字
            }
        }
    }
    int i=0;
    while(outputString[i]!='0'){
        cout << outputString[i];
        i++;
    }
    cout <<endl;
}
