#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<char, int> roman {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
};
map<int, string> romanMap {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
int arr[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

int romantodec(string s){
    int sum=0;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(i+1<len && roman[s[i+1]]>roman[s[i]]){
            sum+=roman[s[i+1]]-roman[s[i]];
            i++;
        }else{
            sum+=roman[s[i]];
        }
    }
    return sum;
}

string dectoroman(int n){
    string s="";
    int q,i=0;
    while(n){
        q=n/arr[i];
        n-=q*arr[i];
        while(q--){
            s+=romanMap[arr[i]];
        }i++;
    }
    return s;
}

int main(){
    string s1,s2;
    while(cin >> s1){
        if(s1[0]=='#')
            break;
        else
            cin >> s2;

        int diff = abs(romantodec(s1)-romantodec(s2));
        if(diff==0)
            cout << "ZERO" << endl;
        else{
            cout << dectoroman(diff) << endl;
        }
    }
}