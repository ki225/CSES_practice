#include <iostream>
using namespace std;

bool Equivalent(string s1,string s2,int string_size){
    if(s1==s2)
        return true;
    if(string_size%2==1)
        return false;

    string a1=s1.substr(0, string_size/2);
    string a2=s1.substr(string_size/2,string_size);
    string b1=s2.substr(0, string_size/2);
    string b2=s2.substr(string_size/2, string_size);

    if(Equivalent(a1,b1,string_size/2)&&Equivalent(a2,b2,string_size/2) || (Equivalent(a2,b1,string_size/2)&&Equivalent(a1,b2,string_size/2)))
        return true;
    else
        return false;
    
}

int main(){
    string s1,s2;
    bool ans=true;
    cin >> s1 >> s2;
    
    if(Equivalent(s1,s2,s1.length()))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}