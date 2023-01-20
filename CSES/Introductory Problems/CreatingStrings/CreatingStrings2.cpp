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
void permute(char *a, int l, int r) ;
void swap(char *x, char *y) ;
//void swap(string originalString, int swapIndex);
bool whetherIn(string s);

int main(){
    string ipStr;
    int diffNum;
    cin >> ipStr;
    checkSame(ipStr);
    diffNum = ipStr.length() - words.size();
    outputNum(ipStr.length(),diffNum);

    permute(&ipStr[0],0,ipStr.length()-1);
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
/* Function to swap values at two pointers */
void swap(char *x, char *y) 
{ 
	char temp; 
	temp = *x; 
	*x = *y; 
	*y = temp; 
} 

/* Function to print permutations of string 
This function takes three parameters: 
1. String 
2. Starting index of the string 
3. Ending index of the string. */
void permute(char *a, int l, int r) //Permutation是排列
{ 
	int i; 
	if (l == r) {
        if(!whetherIn(a)){
            cout<<a<<endl; 
            vec2.push_back(a);
        }  
    }
		
	else
	{ 
		for (i = l; i <= r; i++) 
		{ 
			swap((a+l), (a+i)); 
			permute(a, l+1, r); 
			swap((a+l), (a+i)); //backtrack 
		} 
	} 
} 
/*
String permutation algorithm | All permutations of a string
https://youtube.com/watch?v=GuTPwotSdYw&feature=shares
*/

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
